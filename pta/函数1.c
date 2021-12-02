/*
将一个整数n转换成字符串。例如；输入483，应得到字符串"483"。其中，
要求用一个递归函数实现把一个正整数转换为字符串。

输入格式:
首先输入测试组数T，然后输入T组测试数据。每组测试数据输入一个整数n（-2^31≤n≤2^31-1）。

输出格式:
对于每组测试，输出转换后的字符串。

输入样例:
1
1234
输出样例:
1234
*/

# include <stdio.h>
# include <malloc.h>

void f(int val);

int main()
{
    int n, i;

    scanf("%d",&n);

    int * a = (int *)malloc(sizeof(int) * n);

    for (i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (i=0; i<n; ++i)
    {
        f(a[i]);
        printf("\n");
    }

    free(a);
    
    return 0;
}

void f(int val)
{
    if (val < 0)
    {
        printf("-");
        val = -val;
    }

    if (val/10> 0)
    {
        f(val/10);
    }
    printf("%c", val%10+48);
}