#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){
  printf("argc:%d\n",argc);
  int count = sizeof(argv);
  for (int i = 0; i < count; i++){
    printf("argv[%d]:%s\n",i,argv[i]);
  }
  return 0;
}
