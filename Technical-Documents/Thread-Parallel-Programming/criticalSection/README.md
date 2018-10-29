### 代码说明

1. criticalSection1.c 代码的执行结果是错误的，使用loop.sh脚本会执行非常多的次数会发现问题
2. criticalSection1-1.c  代码要针对criticalSection1.c提出的问题，采用读写锁校正程序，使得程序能够正常运行
3. criticalSection1-1-1.c  代码测试了使用信号量也不能解决不同线程之间互斥访问临界区的问题，所以只能采用读写锁
3. criticalSection2.c 代码采用pthread_mutex_t互斥量控制不同线程对临界区的访问，代码不存在任何问题
4. criticalSection2-2.c 代码采用循环忙等待的方式解决临界区的访问出错问题，循环忙等待比互斥量存在的优势是：循环忙等待保证了线程的顺序。但是循环忙等待一直在轮训，浪费CPU资源
5. criticalSection3.c 代码采用semaphore信号量解决了临界区访问存在的问题，semaphore的使用方法和pthread_mutex_t互斥量的使用方法一样
