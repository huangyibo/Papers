// gcc -fPIC -shared -o Lib.so Lib.c
//上述指令生成Lib.so文件之后，Lib.c文件就可以移除，当Lib.c实现改变之后，值需要重新生成Lib.so即可。这样做的前提是接口没有变化，只是接口的实现发生了变化。
//gcc -fPIC -shared -o libfoo.so.1.0.0 Lib.c 将共享库编译为标准格式libxxx.so.1.0.0   
//ln -s libfoo.so.1.0.0 libfoo.so    建立符号链接，将其指向最新版本的共享库
#include <stdio.h>

void foobar(int i){
  printf("Printing from Lib.so %d\n",i);
}
