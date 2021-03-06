#include <sys/types.h>  // It is finded in the /usr/include/sys/types.h.
#include <sys/stat.h>   //It is finded in the /usr/include/sys/stat.h.
#include <fcntl.h>  //fcntl means file control. It defines the file control operate.
#include <stdio.h>  //It includes perror(const char *str)
#include <unistd.h>   //It includes read(int fd, void* buf, size_t len)
#include <errno.h>
#include <string.h>  //It includes memset(void *str, int value, size_t __n)
#define BUFFER_SIZE 64

int main (int argc,char *argv[]){
  int fd;   // It is the File Description which is used int the Linux System.
  fd = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/testRead.c",O_RDONLY);   //example 1: reading the testRead.c file
  //fd = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/input_not_null",O_RDONLY);   //example 2: reading the input file
  //fd = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/input_null",O_RDONLY);   //example 3: reading the null input file
  if (fd == -1){
    perror("main");
  }else{
    printf("Success!\n");
  }

  ssize_t ret;   // signed size_t, the negative numbers mean error
  char buf[BUFFER_SIZE+1];   //It means the buffer for the reading operating.
  memset(&buf,0,BUFFER_SIZE);  //It means the initial value for every value in the buffer
  while ((ret = (read(fd,&buf,BUFFER_SIZE))) != 0){
    if (ret == -1){
       if (errno == EINTR)   //It means the program encounts interupts, for software interupts and so on.
           continue;
       perror("main");
       break;
    }
    buf[ret] = '\0';   //It is must occur in here. If not exist, the stdout occurs bad codes.
    printf("%s",buf);
  }
  int ret_close = close(fd);
  if (ret_close == -1){
    perror("close:");
  }
  return 0;
}

// http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/

