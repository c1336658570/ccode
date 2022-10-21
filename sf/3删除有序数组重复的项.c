//删除有序数组重复的项并返回新长度
//[0, 1, 2, 2, 3, 3, 4]
//返回5
#include <stdio.h>

int arrdel(int *arr, int len);

int main(void)
{
  int arr[] = {0, 1, 2, 2, 3, 3, 4, 5, 5, 6};
  int len = arrdel(arr, sizeof(arr) / sizeof(arr[0]));
  printf("len = %d\n", len);

  return 0;
}

//双指针，空间复杂度O(1)
int arrdel(int *arr, int len) {
 if (len == 0 || arr == NULL)
  return 0;

  int i = 0, j;
  for (j = 1; j < len; j++) {
    if (arr[j] != arr[i]) {
      i++;
      arr[i] = arr[j];
    } else {

    }

  }
  return i + 1; 
}