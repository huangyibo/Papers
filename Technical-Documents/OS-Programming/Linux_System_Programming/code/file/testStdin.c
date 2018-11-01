#include <sys/types.h>  // It is finded in the /usr/include/sys/types.h.
#include <sys/stat.h>   //It is finded in the /usr/include/sys/stat.h.
#include <fcntl.h>  //fcntl means file control. It defines the file control operate.
#include <stdio.h>  //It includes perror(const char *str)
#include <unistd.h>   //It includes read(int fd, void* buf, size_t len)
#include <errno.h>
#include <string.h>  //It includes memset(void *str, int value, size_t __n)
#define BUFFER_SIZE 4096
// #define BUFFER_SIZE 20   // extreme case. The buffer size is common 4096 * n 
int main (int argc,char *argv[]){
  ssize_t ret;   // signed size_t, the negative numbers mean error
  char buf[BUFFER_SIZE];   //It means the buffer for the reading operating.
  memset(&buf,0,BUFFER_SIZE);  //It means the initial value for every value in the buffer
  size_t count = 0 ;
  while ((ret = (read(STDIN_FILENO,&buf,BUFFER_SIZE))) != 0){
    if(count == 3){
       break;
    }
    if (ret == -1){
       if (errno == EINTR)   //It means the program encounts interupts, for software interupts and so on.
           continue;
       perror("main");
       break;
    }
    write(STDOUT_FILENO,&buf,ret);  //#define STDOUT_FILENO 1. It is the standard output file description.
    count++;
  }
  return 0;
}

// http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/

