/*
    桶排序
*/

/*# include <stdio.h>

//输入5 3 5 2 8
int main(void)
{
    int a[11], i, j, t;
    
    for (i = 0; i < 11; ++i)
    {
        a[i] = 0;
    }

    for (i = 1; i <= 5; ++i)
    {
        scanf("%d", &t);
        a[t]++;
    }

    for (i = 0; i < 11; ++i)
    {
        for (j = 0; j < a[i]; ++j)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
*/

/*
    输入：
        10
        8 100 50 22 15 6 1 1000 999 0

    输出：
        1000 999 100 50 22 15 8 6 1 0 

*/

# include <stdio.h>

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