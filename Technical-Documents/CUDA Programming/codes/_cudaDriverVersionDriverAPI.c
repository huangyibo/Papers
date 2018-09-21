//gcc -o test -I/usr/local/cuda/include -L/usr/local/cuda/lib64 _cudaDriverVersionDriverAPI.c -lcuda
#include <stdio.h>
#include <cuda.h>

int main(){
  int driverVersion;
  cuInit(0);
  cuDriverGetVersion(&driverVersion);
  printf("CUDA Driver Version:%d.%d\n",driverVersion/1000,driverVersion/100);
  return 0;
}
