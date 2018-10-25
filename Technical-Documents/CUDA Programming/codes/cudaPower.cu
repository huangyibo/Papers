#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 1048576     //该数值随便指定
int data[DATA_SIZE];    //全局data数组，要计算数组中数据的平方和

/*
  * @author Junpeng Zhu
  * @功能  为当前程序设置一个合适的GPU，当然还有其它的方式能够实现该功能，比如设置环境变量
*/
bool InitCUDA(){
  int count;
  cudaGetDeviceCount(&count);   //统计计算机中支持CUDA的显卡的个数
  if (count == 0){
    fprintf(stderr, "There is no device!\n");
    return false;
  }
  
  int i;
  for (i = 0; i < count; i++){
    cudaDeviceProp prop;
    if (cudaGetDeviceProperties(&prop,i) == cudaSuccess){
      if (prop.major >= 1 and prop.minor >= 0){
        break;
      }
    }
  }
  if (i == count){
    fprintf(stderr,"There is no device support CUDA 1.x.\n");
    return false;
  }

  cudaSetDevice(i);   //设定满足>=1.0的计算设备为当前程序需要的计算设备
  return true;
}

/*
  * @author Junpeng Zhu
  * @功能  随机数生成函数，生成0-9的以内的整数
*/
void GenerateNumbers(int *number, int size){
  for (int i =0; i < size; i++){
    number[i] = rand() % 10;
  }
}


int main(){
  if (!InitCUDA()){
    return 0;
  }else{
    printf("CUDA initialized.\n");
    GenerateNumbers(data, DATA_SIZE);   //生成指定规模的随机数据，所有数据范围均在0-9
    int *gpudata, *result;
    cudaMalloc((void**) &gpudata, sizeof(int) * DATA_SIZE); //在device上分配一块linear地址空间，地址为&gpudata，每个单元大小为int，总共DATA_SIZE个单元
    cudaMalloc((void **) &result, sizeof(int));  //在device上分配内存，大小为int
    cudaMemcpy(gpudata, data, sizeof(int) * DATA_SIZE, cudaMemcpyHostToDevice);   //从host的data中将DATA_SIZE个单元的数据复制到device的gpudata中，这是输入数据，需要从host中获取
    
    
    return 0;
  }
}
