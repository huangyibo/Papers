#include <sys/types.h>  // It is finded in the /usr/include/sys/types.h.
#include <sys/stat.h>   //It is finded in the /usr/include/sys/stat.h.
#include <fcntl.h>  //fcntl means file control. It defines the file control operate.
#include <stdio.h>  //It includes perror(const char *str)
#include <unistd.h>   //It includes read(int fd, void* buf, size_t len)
#include <errno.h>
#define BUFFER_SIZE 4096

int main (int argc,char *argv[]){
  int fd;   // It is the File Description which is used int the Linux System.
  fd = open("/home/os/Papers/Technical Documents/OS/linux_system_programming/code/testRead.c",O_RDONLY);
  if (fd == -1){
    perror("main");
  }else{
    printf("Success!\n");
  }

  size_t ret;

  char buf[BUFFER_SIZE];
  size_t len = 100;
  while (len != 0 && (ret = (read(fd,&buf,BUFFER_SIZE))) != 0){
    if (ret == -1){
       if (errno == EINTR)   //It means interupts
           continue;
       perror("main");
       break;
    }
//    len -= ret; 
//    buf += ret; 
    for (int i = 0 ; i < BUFFER_SIZE; i++){
      printf("%c",buf[i]);
    }
  }
  return 0;
}

// http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/

