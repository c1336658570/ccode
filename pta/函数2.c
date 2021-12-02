/*
给你一个正整数，你能算出它的阶乘是多少吗？

输入描述:
若干行，每行一个整数n(1<=n<=20)。

输出描述:
按顺序输出每个整数的阶乘，一个结果占一行。

输入样例1
2
6
结尾无空行
输出样例1
2
720
结尾无空行
输入样例2
5
1
3
结尾无空行
输出样例2
120
1
6
结尾无空行
*/

# include <stdio.h>

long f(int val);

int main(void)
{
    int i, j, val;
    long arr[100];
    
    i = 0;
    while ( scanf("%d", &val) != EOF)
    {
        arr[i] = f(val);
        i++;
    }
    for (j=0; j<i-1; ++j)
        printf("%ld\n", arr[j]);
    printf("%ld", arr[j]);
    
    return 0;
}

long f(int val)
{
    if (val == 0 || val == 1)
        return 1;
    else
        return f(val-1)*val;
}