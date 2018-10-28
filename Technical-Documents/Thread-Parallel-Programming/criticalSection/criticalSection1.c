/**
  * @author Junpen Zhu
  * 代码实现功能：假设A现在有1500元(sum1)，B现在有500元(sum2)，紧接着A将调用add代码，给B转钱，每次转走200元，相应的自己就减少200元，钱可以为负值
  * 上述过程持续N次，等待结束完成之后，B会调用sub函数，再给自己加300元
  * 这段代码是错误的，设计到生产者消费者的问题
  * sum1 = -6500
    sum2 = -6200
  **********************************************
    sum1 = -6500
    sum2 = -6500
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 40

int sum1 = 1500;
int sum2 = 500;

void* add(void* tid){
  int id = (int)tid;
  pthread_mutex_t mutex1;    //1. 申请mutex变量
  pthread_mutex_init(&mutex1, NULL); //2. 初始化mutex变量，第二个参数恒定为NULL
  //printf("进入到线程%d.\n", id);
  pthread_mutex_lock(&mutex1); //3. 在访问临界区时加锁
  sum2 = sum1 - 200;    //临界区数据发生变化
  sum1 = sum1 - 200;
  pthread_mutex_unlock(&mutex1);   //4. 处理完临界区以后，释放锁
  //pthread_mutex_destroy(&mutex);  //5. 释放掉mutex变量，必须要完成以上五步，否则不会得到正确的计算结果  
  return NULL;
}

void* sub(void* tid){
  int id = (int)tid;
  pthread_mutex_t mutex2;    //1. 申请mutex变量
  pthread_mutex_init(&mutex2, NULL); //2. 初始化mutex变量，第二个参数恒定为NULL
  //printf("进入到线程%d.\n", id);
  pthread_mutex_lock(&mutex2); //3. 在访问临界区时加锁
  sum2 += 300;
  pthread_mutex_unlock(&mutex2);   //4. 处理完临界区以后，释放锁
  //pthread_mutex_destroy(&mutex);  //5. 释放掉mutex变量，必须要完成以上五步，否则不会得到正确的计算结果  
  return NULL;

}

int main(){
  pthread_t* sumPthread;
  sumPthread = malloc(N*sizeof(pthread_t));
  pthread_t subPthread;
  for (int i = 0; i < N; i++){
    pthread_create(&sumPthread[i], NULL, add, (void*)i);
  }
  pthread_create(&subPthread, NULL, sub, (void*)1);
 
  for (int i = 0; i < N; i++){
    pthread_join(sumPthread[i],NULL);
  }
 
  pthread_join(subPthread,NULL);

  printf("sum1 = %d\n", sum1);
  printf("sum2 = %d\n", sum2);

  return 0;
}
