#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/uio.h>
#define BUFFER_SIZE 256

int main (int argc, char *argv[]){
  
  ssize_t fd_input = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/testRead.c",O_RDONLY);
  if (fd_input == -1){
    perror("input:");
  }

  ssize_t fd_output = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/output",O_WRONLY | O_APPEND);
  if (fd_output  == -1){
    perror("output:");
  } 
  
  char buffer1[BUFFER_SIZE]; 
  char buffer2[BUFFER_SIZE];
  char buffer3[BUFFER_SIZE];
  char buffer4[BUFFER_SIZE];
  char buffer5[BUFFER_SIZE];
  char buffer6[BUFFER_SIZE];
  char buffer7[BUFFER_SIZE];
  char buffer8[BUFFER_SIZE];

  memset(&buffer1,0,BUFFER_SIZE);
  memset(&buffer2,0,BUFFER_SIZE);
  memset(&buffer3,0,BUFFER_SIZE);
  memset(&buffer4,0,BUFFER_SIZE);
  memset(&buffer5,0,BUFFER_SIZE);
  memset(&buffer6,0,BUFFER_SIZE);
  memset(&buffer7,0,BUFFER_SIZE);
  memset(&buffer8,0,BUFFER_SIZE);

  struct iovec iovs[8];
  iovs[0].iov_base = buffer1;
  iovs[0].iov_len = sizeof(buffer1);
  iovs[1].iov_base = buffer2;
  iovs[1].iov_len = sizeof(buffer2);
  iovs[2].iov_base = buffer3;
  iovs[2].iov_len = sizeof(buffer3);
  iovs[3].iov_base = buffer4;
  iovs[3].iov_len = sizeof(buffer4);
  iovs[4].iov_base = buffer5;
  iovs[4].iov_len = sizeof(buffer5);
  iovs[5].iov_base = buffer6;
  iovs[5].iov_len = sizeof(buffer6);
  iovs[6].iov_base = buffer7;
  iovs[6].iov_len = sizeof(buffer7);
  iovs[7].iov_base = buffer8;
  iovs[7].iov_len = sizeof(buffer8);

  ssize_t ret_readv;
  ssize_t ret_writev;
  while((ret_readv = read(fd_input,iovs,8)) != 0){
    if(ret_readv == -1){
      if (errno  == EINTR){
         continue;
      }
      perror("read:");
      break;
    }
    ret_writev = write(fd_output,iovs,8);
    if (ret_writev == -1){
      if(errno == EINTR){
        continue;
      }
      perror("write:");
      break;
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
