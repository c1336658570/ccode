/*
现有 N(N\le 1000)N(N≤1000) 名同学参加了期末考试，并且获得了每名同学的信息：
语文、数学、英语成绩（均为不超过 150 的自然数）。
如果某对学生 <i,j> 的每一科成绩的分差都不大于 5，且总分分差不大于 10，
那么这对学生就是“旗鼓相当的对手”。现在想知道这些同学中，有几对“旗鼓相当的对手”？
同样一个人可能会和其他好几名同学结对。

输入格式
第一行一个正整数 N。

接下来 NN 行，每行三个整数，其中第 i 行表示第 i 名同学的语文、数学、英语成绩。
最先读入的同学编号为 1。

输出格式
输出一个个整数，表示“旗鼓相当的对手”的对数。

输入 
3
90 90 90
85 95 90
80 100 91
输出
2
*/

# include <stdio.h>
# include <malloc.h>
# include <math.h>

int main(void)
{
    int n, i, j, k, t;
    scanf("%d", &n);
    int **arr = (int **)malloc(sizeof(int*) *n);
    int *sum = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int) * 3);
        sum[i] = 0;
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            scanf("%d", *(arr+i) + j);
            sum[i] += arr[i][j];
        }
    }

    t = 0;
    for(i = 0; i < n-1; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            for (k = 0; k < 3; k++)
            {
                if( abs(arr[i][k] -arr[j][k]) > 5|| abs(sum[i] - sum[j]) > 10)
                    break;
            }
            if (k == 3)
                t++;
        }
    }
    printf("%d\n", t);

    return 0;
}
