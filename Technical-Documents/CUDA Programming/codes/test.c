#include <stdio.h>

int main(){
  int a = 100;
  int* p = &a;
  int** q = &p;
  printf("%ld %ld %ld\n", q, p, &a);
  return 0;
}
