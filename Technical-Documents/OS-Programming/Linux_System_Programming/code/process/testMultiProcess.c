#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){
  pid_t cld_fork;
  int status;
  if (!(cld_fork = fork())){
    execl("/home/os/Papers/Technical-Documents/OS/Linux_System_Programming/code/process/test","test",NULL);
  }
  wait(&status);
  for(int i = 0; i < 10; i++){
    printf("father process!\n");
  }
  return 0;
}
