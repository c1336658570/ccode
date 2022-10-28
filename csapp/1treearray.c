#include <stdio.h>

//get the lowest 1
unsigned LowBit(unsigned x)
{
  unsigned a = x & (-x);
  return a;
}

int main(void)
{
  unsigned n = 7;
  
  printf("S[%u] = \n", n);
  printf("   T[%u]\n", n);
  n = n - LowBit(n);
  printf("+  T[%u]\n", n);
  n = n - LowBit(n);
  printf("+  T[%u]\n", n);
  n = n - LowBit(n);
  printf("+  T[%u]\n", n);
  

  return 0;
}