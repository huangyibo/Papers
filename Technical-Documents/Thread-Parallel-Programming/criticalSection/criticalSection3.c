/**
  * 首先该段互斥程序能够正确的执行，使用命令gcc -o test criticalSection2.c -lpthread将该段代码编译，生成可执行文件test，接着运行./loop脚本即可在output中看到结果。
  * 正确的步骤如下：
  * 1. 申请全局的互斥量pthread_t mutex
  * 2. 在主线程（main函数）中初始化该互斥量 pthread_mutex_init(&mutex, NULL)
  * 3. 在互斥量使用前使用 pthread_mutex_lock(&mutex)加锁
  * 4. 使用完互斥量后释放锁 pthread_mutex_unlock(&mutex);
  * 5. 在主线程（main函数）中销毁互斥量 pthread_mutex_destroy(&mutex)
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>  //1. 包含semaphore头文件
#define N 40

int sum = 0;   //全局变量，由不同的应用程序调用可能会产生竞争，被称为临界区，也称为互斥量
int sub = 40;
sem_t mutex;    //2. 设置semaphore全局变量 

void* add(void* tid){
  int id = (int)tid;
  //printf("进入到线程%d.\n", id);
  sem_wait(&mutex);   //4. 进入临界区前使用sem_wait函数，判断mutex，如果是0，则等待，如果非0，则对mutex减1后进去临界区
  sum += 1;    //临界区数据发生变化
  sub -= 1;
  sem_post(&mutex);  //5. 完成临界区的访问后，调用sem_post，对mutex信号量的值加1，使得等待的线程能够正常运行
  return NULL;
}

int main(){
  sem_init(&mutex,0, 1);  //3. 初始化semaphore全局变量，并且设定初始值为1
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
  sem_destroy(&mutex);  //6. 释放信号量mutex
  return 0;
}
