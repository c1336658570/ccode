/*
    去重+排序
    桶排序
    输入：
        10
        20 40 32 67 40 20 89 300 400 15
    输出：
        15 20 32 40 67 89 300 400 
*/


# include <stdio.h>

int main(void)
{
    int a[1001], n, i, t;

    for(i = 0; i < 1001; ++i)
        a[i] = 0;

    scanf("%d", &n); // 读如数据的个数
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        a[t] = 1;
    }

    for (i = 1; i < 1001; ++i)
    {
        if (a[i] == 1)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}