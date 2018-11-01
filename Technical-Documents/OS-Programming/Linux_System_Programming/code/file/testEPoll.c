/**
  * The epoll_wait() example when stdin blocks the reading operating.
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
#include <sys/epoll.h>
#define BUFFER_SIZE 4096
#define MAX_EVENTS 4
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
  
  int epfd;
  epfd = epoll_create1(0);
  if(epfd < 0){
    perror("epoll_create1:");
  }
  struct epoll_event events;
  struct epoll_event wait_events[MAX_EVENTS];
  events.data.fd = 0;  //stdin
  events.events = EPOLLIN;
  epoll_ctl(epfd,EPOLL_CTL_ADD,0, &events);
  
//  events.data.fd = 1;  //stdout
//  events.events = EPOLLOUT;
//  epoll_ctl(epfd,EPOLL_CTL_ADD,1, &events);  
  
  events.data.fd = fd_input;
  events.events = EPOLLIN;
  epoll_ctl(epfd,EPOLL_CTL_ADD,fd_input,&events);

  events.data.fd = fd_output;
  events.events = EPOLLOUT;
  epoll_ctl(epfd,EPOLL_CTL_ADD,fd_output,&events);

  bool std_end_flag = true;
  int ret_epoll;
  while (std_end_flag){  
	  ret_epoll = epoll_wait(epfd,wait_events,MAX_EVENTS,-1);
	  if (ret_epoll == -1){
	    perror("epoll_wait:");
	    return 1;
	  }

	    if (events.data.fd == 0){
	       while((ret_read = read(STDIN_FILENO,&buffer,BUFFER_SIZE)) != 0){
	        if(ret_read == -1){
		  if (errno  == EINTR){
		     continue;
		  }
		  perror("read:");
		  break;
	        }
	        ret_write = write(STDOUT_FILENO,&buffer,(ssize_t)ret_read);
	        if (ret_write == -1){
		  if(errno == EINTR){
		    continue;
		  }
		  perror("write:");
		  break;
	        }
	    }//while read
        } 
	  if (events.data.fd == fd_input){
	    while((ret_read = read(fd_input,&buffer,BUFFER_SIZE)) != 0){
	      if(ret_read == -1){
		if (errno  == EINTR){
		   continue;
		}
		perror("read:");
		break;
	    }
        ret_write = write(fd_output,&buffer,(ssize_t)ret_read);
	    if (ret_write == -1){
            if(errno == EINTR){
                continue;
            }
            perror("write:");
            break;
        }
        }   //while
        } //if
  }

  int ret = fdatasync(fd_output);
  printf("sync:%d\n",ret);
  
  if (close(epfd) == -1){
    perror("epfd:");
  }
  if (close(fd_output) == -1){   //The fd_output is closed that is input file desctiptor. It is the second for the open sort.
    perror("fd_outpt:");
  }  
  if (close(fd_input)  == -1){
    perror("fd_input:");
  }
  return 0;

}
