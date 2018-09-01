#include <stdio.h>
int main (int argc, char *argv[]){
  FILE *stream;
  stream = fopen("/home/os/Papers/Technical-Documents/OS/linux_system_programming/code/file/testRead.c","r");
  size_t flag = 1;
  int c;
  while (flag){
    c = fgetc(stream);
    if (c == EOF){
      flag = 0;
    }else{
      printf("%c",(char) c);
    }
  }
  return 0;
}
