#include <stdio.h>
#include <stdbool.h>

int primes1(int n);
int primes2(int n);

int main(void)
{
  int n = primes1(100);
  printf("primes: %d\n", n);
  n = primes2(100);
  printf("primes: %d\n", n);

  return 0;
}

//埃式筛选
int primes1(int n) {
  bool isPrime[n+1]; //true代表素数
  int i, j, count;

  for (i = 0; i < n+1; i++) {
    isPrime[i] = true;
  }

  count = 0;
  for (i = 2; i < n; i++) {
    if (isPrime[i]) {
      count++;
      for (j = 2 * i; j < n; j+=i) {
        isPrime[j] = false;
      }
    }
  }

  return count;
}

int primes2(int n) {
  bool isPrime[n+1]; //true代表素数
  int i, j, count;

  for (i = 0; i < n+1; i++) {
    isPrime[i] = true;
  }

  count = 0;
  for (i = 2; i < n; i++) {
    if (isPrime[i]) {
      count++;
      for (j = i * i; j < n; j+=i) { //优化，只需要从i * i开始即可
        isPrime[j] = false;
      }
    }
  }

  return count;
}