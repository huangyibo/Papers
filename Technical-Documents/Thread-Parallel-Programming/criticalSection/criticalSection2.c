/**
  * 该程序也是错误的，会出现下述结果：
  * sum = 40
  * sub = 0
  ***********************************
  * sum = 39
  * sub = 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 40

int sum = 0;   //全局变量，由不同的应用程序调用可能会产生竞争，被称为临界区，也称为互斥量
int sub = 40;

void* add(void* tid){
  int id = (int)tid;
  pthread_mutex_t mutex;    //1. 申请mutex变量
  pthread_mutex_init(&mutex, NULL); //2. 初始化mutex变量，第二个参数恒定为NULL
  //printf("进入到线程%d.\n", id);
  pthread_mutex_lock(&mutex); //3. 在访问临界区时加锁
  sum += 1;    //临界区数据发生变化
  sub -= 1;
  pthread_mutex_unlock(&mutex);   //4. 处理完临界区以后，释放锁
  pthread_mutex_destroy(&mutex);  //5. 释放掉mutex变量，必须要完成以上五步，否则不会得到正确的计算结果  
  return NULL;
}

int main(){
  pthread_t *pthread_handles;
  pthread_handles = malloc(N*sizeof(pthread_t));
  for (int i = 0 ; i < N; i++){
    pthread_create(&pthread_handles[i], NULL, add, (void*)i);
  }
  
  for (int i = 0 ; i < N; i++){
    pthread_join(pthread_handles[i],NULL);
  }

  free(pthread_handles);
  printf("sum = %d\n", sum);
  printf("sub = %d\n", sub);
  return 0;
}
