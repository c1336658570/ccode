//Find which digit is 1 in a hexadecimal number(求一个十六进制数哪一位是1)
#include <stdio.h>

unsigned Letter(unsigned x)
{
  // x3 x2 x1 x0 -- hex
  // 0  1  0  0 & - hex constant -0 x2
  // 0  x2 0  0
  //0x22222222 & a

  unsigned x1 = x & 0x22222222;
  unsigned x2 = x & 0x44444444;
  unsigned x3 = x & 0x88888888;
  // x3 * (x1 + x2) <==> x3 & (x1 + x2)
  //1000  0001 >> 3
  //0100  0001 >> 2 
  //0010  0001 >> 1

  return (x3 >> 3) & ((x2 >> 2) | (x1 >> 1));
}

int main(void)
{
  unsigned n = 7;
  
  printf("%#x, is letter %#x\n", 0xabcdefab, Letter(0xabcdefab));
  printf("%#x, is letter %#x\n", 0x11111111, Letter(0x11111111));
  printf("%#x, is letter %#x\n", 0xa111c1f1, Letter(0xa111c1f1));

  return 0;
}