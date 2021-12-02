/*
已知Fibonacci数列的规律是1，1，2，3，5，8，…，即数列的前两项是1，
其后的每一项都是其前两项的和。输出Fibonacci数列的前n（1<=n<=40）项。
要求定义并调用含静态变量的函数Fibonacci(n)计算Fibonacci数列的第n项。

输入格式:
输入n值

输出格式:
以每行4个的格式输出Fibonacci数列的前n项。每项占10位列宽并左对齐。

输入样例:
在这里给出一组输入。例如：

10
结尾无空行
输出样例:
在这里给出相应的输出。例如：

1         1         2         3         
5         8         13        21        
34        55        
结尾无空行
*/

# include <stdio.h>

int Fibonacci(int n);

int main(void)
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i=1; i<=n; ++i)
    {
        printf("%-10d", Fibonacci(i));
        if (i == n)
        {
            break;
        }
        if (i%4 == 0)
            printf("\n");
    }
    printf("\n");
    
    return 0;
}

int Fibonacci(int n)
{  
    int f1, f2, f3, i;
    
    f1 = 1;
    f2 = 1;
    if (n == 1)
    {
        f3 = f1;
    }
    if (n == 2)
    {
        f3 = f2;
    }
    for (i = 3; i <= n; ++i)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}