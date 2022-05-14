#include <stdio.h>

int erfen(int *arr, int len, int num)
{
    if (arr == NULL || len == 0)
        return -1;

    int L = 0;
    int R = len - 1;
    int mid = 0;

    while (L <= R)
    {
        //mid = (L+R) / 2;
        //L 10亿 R 18亿 L+R会溢出，不安全
        //所以写mid = L + (R - L) / 2;
        //N/2 等价于 N >> 1
        mid = L + ((R - L) >> 1); // mid = (L + R) / 2
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] > num)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }

    return -1;
    
}