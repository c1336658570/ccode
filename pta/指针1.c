/*
有m个选手n个评委，每个评委给所有选手打分。最后得分的计算规则为去掉一个最高分，
去掉一个最低分后取平均分为最后得分。要求按得分从高到低排出名次，公布获奖名单。
本题要求用行指针实现。1≤m,n≤10。请务必用冒泡排序。

输入格式:
输入共m+1行，第一行是m和n两个整数，其他行是m×n个整数。

输出格式:
输出一行，表示选手编号的一种排列（用%3d格式），这种排列代表得分从高到低的选手顺序。

输入样例:
8 5
7 8 9 7 8
8 9 7 9 8
8 9 8 8 7
8 9 9 9 8
7 6 8 9 7
6 7 8 9 9
6 7 8 7 8
7 8 7 6 7
结尾无空行
输出样例:
  4  2  3  6  1  5  7  8
结尾无空行
*/

# include <stdio.h>
# include <malloc.h>

int main(void)
{
    int m, n, i, j, k, t;
    
    scanf("%d %d", &m, &n);

    int **arr = (int **)malloc(sizeof(int *) * m);
    int * sum = (int *)malloc(sizeof(int) * m);
    int * book = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < m; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }
    for (i = 0; i < m; ++i)
    {
        sum[i] = 0;
        book[i] = 1;
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n-1; ++j)
        {
            for (k = 0; k < n-1-j; ++k)
            {
                if (arr[i][k] > arr[i][k+1])
                {
                    t = arr[i][k];
                    arr[i][k] = arr[i][k+1];
                    arr[i][k+1] = t;
                }
            }
        }
    }

    for (i = 0; i < m; ++i)
    {
        for (j = 1; j < n-1; ++j)
        {
            sum[i] += arr[i][j];
        }
    }

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (i == j)
                continue;
            if (sum[i] < sum[j] || (sum[i] == sum[j] && i > j))
                book[i]++;
                
        }
    }

    t = 0;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            for (k = 0; k < m; ++k)
            {
                if (book[j] > book[k])
                    break;
            }
            if (k == m)
            {
                printf("%3d", j+1);
                book[j] = m;
                t++;
            }
        }
        if (t == m)
            break;
    }
    for (i = 0; i < m; ++i)
    {
        free(arr[i]);
    }
    free(sum);
    free(arr);
    free(book);


    return 0;
}