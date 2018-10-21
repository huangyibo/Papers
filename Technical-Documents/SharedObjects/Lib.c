// gcc -fPIC -shared -o Lib.so Lib.c
//上述指令生成Lib.so文件之后，Lib.c文件就可以移除，当Lib.c实现改变之后，只需要重新生成Lib.so即可。这样做的前提是接口没有变化，只是接口的实现发生了变化。

/** 通常情况下动态链接库应该有版本的要求，该段编译属于标准编译方法
gcc -fPIC -shared -o libfoo.so.1.0.0 Lib.c 将共享库编译为标准格式libxxx.so.1.0.0   
ln -s libfoo.so.1.0.0 libfoo.so    建立符号链接，将其指向最新版本的共享库
*/
/** 将Lib.c编译成为静态库，需要使用下面两条命令
1. gcc -c -fPIC -o libfoo.o Lib.c  首先生成Object文件
2. ar rcs libfoo.a libfoo.o    将Object文件编译成.a文件，即静态库文件
*/
#include <stdio.h>

void foobar(int i){
  printf("Printing from Lib.so %d\n",i);
}
