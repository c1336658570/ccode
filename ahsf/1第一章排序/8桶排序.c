/*
    桶排序
    最好时间复杂度(n+m)
    最差时间复杂度((n+m)*k)
    时间复杂度O((n+m)*k)
    空间复杂度O(n+m)
    稳定
*/

/*
    输入：
        10
        8 100 50 22 15 6 1 1000 999 0

    输出：
        1000 999 100 50 22 15 8 6 1 0

*/

#include <stdio.h>

int main(void)
{
    int book[1001], i, j, t, n;

    for (i = 0; i < 1001; ++i)
    {
        book[i] = 0;
    }
    scanf("%d", &n); // n表示读入n个数

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        book[t]++;
    }

    for (i = 1000; i >= 0; --i)
    {
        for (j = 0; j < book[i]; ++j)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

void bucketSort(int *arr, int len, int max)
{
    int i, j;
    int buckets[max];

    memset(buckets, 0, sizeof(buckets));
}