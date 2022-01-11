/*
输入10个整数，倒序输出。（不用定义数组，用动态内存实现）

输入样例:
1 2 3 4 5 6 7 8 9 10
结尾无空行
输出样例:
10 9 8 7 6 5 4 3 2 1
结尾无空行
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

void traver(int *arr, int len);

int main(void)
{
    int *arr = (int *)malloc(sizeof(int) * 10);
    int i;

    for (i = 0; i < 10; ++i)
    {
        scanf("%d", arr+i);
    }
    traver(arr, 10);
}

void traver(int *arr, int len)
{
    for (len-=1; len > 0; -- len)
    {
        printf("%d ", *(arr+len));
    }
    printf("%d", arr[len]);
}