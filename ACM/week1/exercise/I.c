/*
百钱买百鸡问题：公鸡五文钱一只，母鸡三文钱一只，小鸡三只一文钱，用 100 文钱买 100 只鸡，
公鸡、母鸡、小鸡各买多少只？
本程序要求解的问题是：给定一个正整数 n，用n 文钱买 n 只鸡，问公鸡、母鸡、小鸡各买多少只？

输入格式
输入一个正整数n。
输出格式
如果有解，依次输出公鸡、母鸡、小鸡的个数（用正整数表示）。
如果无解，输出"No Answer."。

数据范围
1≤n≤200。

Sample Input
100
Sample Output
0 25 75
4 18 78
8 11 81
12 4 84
*/

# include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int i, j, k, flag = 0;

    for (i = 0; i*5 <= n; ++i)  //公鸡个数
    {
        for (j = 0; j*3 <= n - i*5; ++j)  //母鸡个数
        {
            k = (n - i*5 - j*3)*3;
            if (i+k+j == n)
            {
                printf("%d %d %d\n", i, j, k);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("No Answer.");

    return 0;
}