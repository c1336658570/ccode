/*
读入整数N，再读入N个整数存入数组，排序后输出。对数组排序请使用函数实现（冒泡法）。

输入样例:
10
72 29 5 91 63 32 68 40 57 11
结尾无空行
输出样例:
5 11 29 32 40 57 63 68 72 91
结尾无空行
*/

# include <stdio.h>

void swap(int *a, int *b);
void sort(int *arr, int len);
void put(int *arr, int len);

int main(void)
{
    int n, i;

    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", arr+i);
    }
    sort(arr, n);
    put(arr, n);
    free(arr);
}

void sort(int *arr, int len)
{
    int i, j, k, flag, pos;

    k = pos = len-1;
    for (i = 0; i < len-1; ++i)
    {
        flag = 0;
        for (j = 0; j < k; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                flag = 1;
                pos = j;
                swap(arr+j, arr+j+1);
            }
        }
        k = pos;
        if (flag == 0)
        {
            return;
        }
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void put(int *arr, int len)
{
    int i;
    for (i = 0; i < len-1; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", *(arr+i));
}