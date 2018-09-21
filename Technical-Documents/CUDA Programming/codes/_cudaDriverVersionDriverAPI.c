#include <stdio.h>
#include <cuda.h>

int main(){
  int driverVersion;
  cuInit(0);
  cuDriverGetVersion(&driverVersion);
  printf("CUDA Driver Version:%d.%d\n",driverVersion/1000,driverVersion/100);
  return 0;
}
