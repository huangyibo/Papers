#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]){
  int fd_input;
  fd_input = open("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("open:");
  }
  // int ret_lseek = lseek(fd_input, (off_t) 9, SEEK_END);
  int ret_lseek = lseek(fd_input, (off_t) 9, SEEK_CUR);  //The lseek() function adjusts the read pointer position.
  if (ret_lseek == (off_t) -1){
    perror("lseek:");
  }
  ssize_t ret_input;
  char buffer[BUFFER_SIZE];
  while ((ret_input = read(fd_input,&buffer,BUFFER_SIZE))!=0){
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
  }
  return 0;
}
