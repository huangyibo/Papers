#include <stdio.h>
#include <cuda_runtime.h>
#include <stdbool.h> 
void printDeviceProp(const cudaDeviceProp &prop)
{
    printf("Device Name : %s.\n", prop.name);
    printf("totalGlobalMem : %d.\n", prop.totalGlobalMem);
    printf("sharedMemPerBlock : %d.\n", prop.sharedMemPerBlock);
    printf("regsPerBlock : %d.\n", prop.regsPerBlock);
    printf("warpSize : %d.\n", prop.warpSize);
    printf("memPitch : %d.\n", prop.memPitch);
    printf("maxThreadsPerBlock : %d.\n", prop.maxThreadsPerBlock);
    printf("maxThreadsDim[0 - 2] : %d %d %d.\n", prop.maxThreadsDim[0], prop.maxThreadsDim[1], prop.maxThreadsDim[2]);
    printf("maxGridSize[0 - 2] : %d %d %d.\n", prop.maxGridSize[0], prop.maxGridSize[1], prop.maxGridSize[2]);
    printf("totalConstMem : %d.\n", prop.totalConstMem);
    printf("major.minor : %d.%d.\n", prop.major, prop.minor);
    printf("clockRate : %d.\n", prop.clockRate);
    printf("textureAlignment : %d.\n", prop.textureAlignment);
    printf("deviceOverlap : %d.\n", prop.deviceOverlap);
    printf("multiProcessorCount : %d.\n", prop.multiProcessorCount);
}
 
bool InitCUDA()
{
    //used to count the device numbers
    int count;
 
    // get the cuda device count
    cudaGetDeviceCount(&count);
    printf("cuda device count: %d\n",count);
    if (count == 0) {
        fprintf(stderr, "There is no device.\n");
        return 1;
    }
 
    // find the device >= 1.X
    int i;
    for (i = 0; i < count; ++i) {
        cudaDeviceProp prop;
        if (cudaGetDeviceProperties(&prop, i) == cudaSuccess) {
            if (prop.totalGlobalMem >= 1000) {
                printDeviceProp(prop);
                cudaSetDevice(i);
                return 0;
            }
        }
    }
 
    // if can't find the device
    if (i == count) {
        fprintf(stderr, "There is no device supporting CUDA 1.x.\n");
        return 1;
    }
 
    return 0;
}
 
int main(int argc, char const *argv[])
{
    if (InitCUDA()) {
        printf("CUDA initialized.\n");
    }
 
    return 0;
}
