#include <stdio.h>

#define SWAP(a, b, t) t = a; a = b; b = t
#define SQUARE(a) a * a 
#define SWAPWHEN(a, b, t ,cond) if (cond) SWAP(a, b, t)

int main(void) {
  int tmp;
  int x = 1;
  int y = 2;
  int z = 3;
  int w = 3;

  SWAP(x, y, tmp);
  printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);

  if (x > y) SWAP(x, y, tmp);
  printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);

  SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);
  printf("x = %d, y = %d\n", x, y);
  
  printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);

  return 0;
}

// #define SWAP(a, b, t) \
//     t = a;            \
//     a = b;            \
//     b = t
// #define SWAPWHEN(a, b, t, cond) \
//     if (cond) SWAP(a, b, t)
// #define SQUARE(a) a *a
// int main() {
//     int tmp;
//     int x = 1;
//     int y = 2;
//     int z = 3;
//     int w = 3;
//     SWAP(x, y, tmp);
//     printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
//     if (x > y) SWAP(x, y, tmp);
//     printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
//     SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);
//     printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
//     printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);
// }