/*
案例拓展 编写函数输出一个十进制整数的十六进制形式 编写函数，函数的参数是整数N，
在函数中输出整数N的十六进制形式（递归方法实现）。主函数中输入整数a和b,输出从a到b的所有整数的十六进制形式。
具体输出格式参考样例。

输入样例:
200 210
结尾无空行
输出样例:
C8 C9 CA CB CC CD CE CF D0 D1 D2
结尾无空行
输入样例:
20000 20010
结尾无空行
输出样例:
4E20 4E21 4E22 4E23 4E24 4E25 4E26 4E27 4E28 4E29 4E2A
结尾无空行
*/

# include <stdio.h>

int main(void)
{
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    for (;n1 <= n2; ++n1)
        {
            f(n1);
            if (n1 == n2)
                break;
            printf(" ");
        }
}

void f(int n)
{
    if (n == 0)
        return;
    else
    {
        f(n/16);
        if (n%16 > 9)
            printf("%c", n%16-10+'A');
        else
            printf("%d", n%16);
    }
}