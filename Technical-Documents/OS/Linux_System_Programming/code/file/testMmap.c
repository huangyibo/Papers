#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#define BUFFER_SIZE 4096
int main(int argc, char *argv[]){
  ssize_t fd;
  fd = open("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/file/testInt",O_RDWR);
  char *p = (char*)mmap(NULL,BUFFER_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
  for (int i = 0; i < BUFFER_SIZE; i++){
    printf("%c",(char) p[i]);
  }
  printf("\n");
  return 0;
}

