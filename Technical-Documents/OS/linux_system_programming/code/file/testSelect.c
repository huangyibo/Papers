/**
  * The select() example when stdin blocks the reading operating.
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
#define BUFFER_SIZE 4096
int main (int argc, char *argv[]){
  
  ssize_t fd_input = open("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("input:");
  }

  ssize_t fd_output = open("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/output",O_WRONLY | O_APPEND);
  if (fd_output  == -1){
    perror("output:");
  } 
  
  char buffer[BUFFER_SIZE];
  memset(&buffer,0,BUFFER_SIZE);
 
  ssize_t ret_read;
  ssize_t ret_write;
  fd_set readfds;
  fd_set writefds;
  bool std_end_flag = true;
  while (std_end_flag){  
	  FD_ZERO(&readfds);
	  FD_SET(STDIN_FILENO, &readfds);
	  FD_SET(fd_input, &readfds);
	  
          FD_ZERO(&writefds);
	  FD_SET(STDOUT_FILENO,&writefds);
	  FD_SET(fd_output, &writefds);
	  
	  int ret_select;
	  ret_select = select(FD_SETSIZE,&readfds,&writefds,NULL,NULL);
	  if (ret_select == -1){
	    perror("select:");
	    return 1;
	  }
	  if (FD_ISSET(STDIN_FILENO, &readfds)){
	    ssize_t std_ret = read(STDIN_FILENO,&buffer,BUFFER_SIZE);  //stdin blocks the following reading and writing operating. The default STDIN_FILENO is 0
	    if (FD_ISSET(STDOUT_FILENO, &writefds)){
	      write(STDOUT_FILENO,&buffer, std_ret);    // Writing from stdin to stdout
              std_end_flag = false;
	    } 
	  }
	  
	  if (FD_ISSET(fd_input, &readfds)){
	    while((ret_read = read(fd_input,&buffer,BUFFER_SIZE)) != 0){
	      if(ret_read == -1){
		if (errno  == EINTR){
		   continue;
		}
		perror("read:");
		break;
	      }
	      if (FD_ISSET(fd_output, &writefds)){
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
