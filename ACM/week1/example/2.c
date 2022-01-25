/*
定义S(x)为x的每位数字之和，如，S(9) = 9，S(10) = 1，S(123) = 6.
若S(x+1) < s(x)。则称x是有趣的。
每组输入一个n统计[1,n]有多少个数字有趣

输入：
5
1
9
10
34
880055535

输出：
0
1
1
3
88005553
*/

# include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d", &i);
    while(i--)
    {
        scanf("%d", &n);
        printf("%d\n", (n+1)/10);
    }
}