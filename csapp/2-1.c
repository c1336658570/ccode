//int转float

#include <stdio.h>
#include <stdint.h>

uint32_t uint2float(uint32_t u) {
  if (u == 0) {
    return 0;
  }

  uint32_t s = u & 0x80000000; // 获取符号位
  uint32_t f; //尾数
  uint32_t e; //指数
  u = u & 0x7fffffff;

  int n = 0; //保存最高位的1所在位数0-31
  int i;

  //查找最高位的1， 0 <= n <= 31
  for (i = 0; i < 32; ++i) {
    if ((u >> i) == 0x1) {
      n = i;
      break;
    }
  }

  if (n <= 23) {
    // 不需要近似

    f = u & (0xffffffff >> (32 - n)); //将最高位的1变为0;IEE754尾数规范
    f = f << (22 - n); //将f转为IEE754规范
    e = n + 127;


    return s | (e << 23) | f;
  } else {
    // 需要近似
  }

}

int main(void) {
  uint32_t f = uint2float(0x00000001);
  
  float ff = 1;
  //printf("%#x %f %lu\n", (float)1.0, (float)1.0, sizeof(float));
  printf("%d %x %f\n", ff, ff, ff);
  uint32_t a = 0x1ac50248;
  printf("%f\n", a);
  printf("%x\n", f);

  return 0;
}