#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#define BUFFER_SIZE 10

int main(int argc, char *argv[]){
  int fd_input;
  fd_input = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("open:");
  }
  
  ssize_t ret_input;
  char buffer[BUFFER_SIZE];
  
  ssize_t count =  0 ;
  while ((ret_input = pread(fd_input,&buffer,BUFFER_SIZE,10))!=0){
    if(ret_input == -1){
       if (errno = EINTR){
         continue;
       }
       perror("input:");
       break;
    }
    for (size_t i = 0; i < ret_input; i++){
       printf("%c",buffer[i]);
    }
    printf("\n");
    count++;
    if (count == 3){
       break; 
    }
  }
  return 0;
}
