#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define BUFFER_SIZE 4096
int main (int argc, char *argv[]){
  
  ssize_t fd_input = open("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("input:");
  }

  ssize_t fd_output = open("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/output",O_RDWR | O_APPEND);
  if (fd_output  == -1){
    perror("output:");
  } 

  char buffer[BUFFER_SIZE];
  memset(&buffer,0,BUFFER_SIZE);
 
  ssize_t ret_read;
  ssize_t ret_write;
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
  }
  return 0;
}
