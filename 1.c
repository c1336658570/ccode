#include<stdio.h>
#include<math.h>
 
int main(void) {
  int cnt = 0, i = 0;
	double x, y, z;

	for (y = 1.5; y > -1.5; y -= 0.1) {
    cnt++;
    if (cnt <= 3) {
      continue;
    }
		for (x = -1.5; x < 1.5; x += 0.05) {
			z = x * x + y * y - 1;
      if (z * z * z - x * x * y * y * y <= 0.0) {
        printf("\e[31m%c\e[0m", '*');
      }
      else {
        printf("%c", ' ');
      }
		}
		putchar('\n');
    if (cnt == 12) {
      break;
    }
	}
  printf("        ");
  for (i = 0; i < 20; ++i)
  {
    printf("\e[31m*\e[0m");
  }
  printf("\e[34m高晓玉\e[0m");
  for (i = 0; i < 19; ++i)
  {
    printf("\e[31m*\e[0m");
  }
  printf("\n");

  cnt = 0;
  int cnt2 = 0;
  for (y = 1.5; y > -1.5; y -= 0.1) {
    cnt++;
    if (cnt < 13) {
      continue;;
    }
		for (x = -1.5; x < 1.5; x += 0.05) {
			z = x * x + y * y - 1;
      if (z * z * z - x * x * y * y * y <= 0.0) {
        printf("\e[31m%c\e[0m", '*');
      }
      else {
        printf("%c", ' ');
      }
		}
    cnt2++;
    if (cnt2 == 13) {
      break;
    }
		putchar('\n');
	}

	return 0;
}