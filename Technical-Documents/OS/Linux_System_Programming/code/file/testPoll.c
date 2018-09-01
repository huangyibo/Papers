/**
  * The poll() example when stdin blocks the reading operating.
  * @author Junpeng Zhu
  * @email jpzhu.gm@gmail.com
*/
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <poll.h>
#define BUFFER_SIZE 4096
int main (int argc, char *argv[]){
  
  ssize_t fd_input = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("input:");
  }

  ssize_t fd_output = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/output",O_WRONLY | O_APPEND);
  if (fd_output  == -1){
    perror("output:");
  } 
  
  char buffer[BUFFER_SIZE];
  memset(&buffer,0,BUFFER_SIZE);
 
  ssize_t ret_read;
  ssize_t ret_write;
  struct pollfd fds[4];
  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;
  fds[1].fd = fd_input;
  fds[1].events = POLLIN;
  fds[2].fd = STDOUT_FILENO;
  fds[2].events = POLLOUT;
  fds[3].fd = STDOUT_FILENO;
  fds[3].events = POLLOUT;

  bool std_end_flag = true;
  while (std_end_flag){  
	  int ret_poll;
	  ret_poll =poll(fds,4,-1);
	  if (ret_poll == -1){
	    perror("poll:");
	    return 1;
	  }
	  if (fds[0].revents && POLLIN){
	    ssize_t std_ret = read(STDIN_FILENO,&buffer,BUFFER_SIZE);  //stdin blocks the following reading and writing operating. The default STDIN_FILENO is 0
	    if (fds[2].revents && POLLOUT){
	      write(STDOUT_FILENO,&buffer, std_ret);    // Writing from stdin to stdout
              std_end_flag = false;
	    } 
	  }
	  
	  if (fds[1].revents && POLLIN){
	    while((ret_read = read(fd_input,&buffer,BUFFER_SIZE)) != 0){
	      if(ret_read == -1){
		if (errno  == EINTR){
		   continue;
		}
		perror("read:");
		break;
	      }
	      if (fds[3].revents && POLLOUT){
		ret_write = write(fd_output,&buffer,(ssize_t)ret_read);
		if (ret_write == -1){
		  if(errno == EINTR){
		    continue;
		  }
		  perror("write:");
		  break;
		}
	      }
	    }
	  }
  }
  int ret = fdatasync(fd_output);
  printf("sync:%d\n",ret);
  if (close(fd_output) == -1){   //The fd_output is closed that is input file desctiptor. It is the second for the open sort.
    perror("fd_outpt:");
  }  
  if (close(fd_input)  == -1){
    perror("fd_input:");
  }
  return 0;
}
