//gcc -o p2 -fPIE program2.c ./Lib.so
#include "Lib.h"

int main(){
  foobar(2);
  return 0;
}
