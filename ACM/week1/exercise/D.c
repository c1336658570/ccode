/*
在n×n的格子上有m个地毯。
给出这些地毯的信息，问每个点被多少个地毯覆盖。

输入格式
第一行，两个正整数 n(1<=n<=1000)、m(1≤m≤105)，意义如题所述。
接下来 m 行，每行两个坐标 (x1,y1)(x2, x2),代表一块地毯 

输出格式
输出n行，每行n个正整数。

第i行第j列的正整数表示(i,j)(i,j) 这个格子被多少个地毯覆盖。

Sample Input
4 3
1 1 3 3
2 2 4 4
3 1 4 3
Sample Output
1 1 1 0
1 2 2 1
2 3 3 1
1 2 2 1
*/

// # include <stdio.h>

// # define N 1001
// int arr[N][N];

// int main(void)
// {
//     int n, m, a, b, c, d, i, j;
//     scanf("%d %d", &n, &m);
//     for (i = 0; i < m; ++i)
//     {
//         scanf("%d %d %d %d", &a, &b, &c, &d);
//         for (; a <= c; a++)
//         {
//             for(j = b; j <= d; j++)
//             {
//                 ++arr[a][j];
//             }
//         }
//     }
//     for (i = 1; i <= n; ++i)
//     {
//         for (j = 1; j <= n; ++j)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

# include <stdio.h>

int cf[1005][1005];
int main()
{
    int n,m;
    int a, b, c, d;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i=a;i<=c;i++)
        {
            cf[i][b]++;
            cf[i][d+1]--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cf[i][j]+=cf[i][j-1];
            printf("%d ",cf[i][j]);
        }
        printf("\n");
    }
    return 0;
}