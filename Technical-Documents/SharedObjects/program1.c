//gcc -o p1 -fPIE program1.c Lib.so  产生地址无关可执行文件，这是重要的地址无关代码技术的一种重要应用
#include "Lib.h"

int main(){
  foobar(1);
  return 0;
}
