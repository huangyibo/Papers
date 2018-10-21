//gcc -o p1 -fPIE program1.c Lib.so  产生地址无关可执行文件，这是重要的地址无关代码技术的一种重要应用
//gcc -o test program1.c -L. -lfoo   编译时，-lfoo会去-L参数指令的路径下寻找libxxx.so的库，这两个参数组合很重要，对于静态链接和动态链接，编译源代码的方式一样，都是采用这条命令
#include "Lib.h"

int main(){
  foobar(1);
  return 0;
}
