/*
输入一个单字符的运算符（+ - * / % > & =)，输出它的优先级。+- 优先级是 4，
 * ，/， % 优先级 3，> 和< 优先级6，&优先级8，=优先级14。 如果是其它符号，结果-1.

输入格式:
一个字符

输出格式:
一个整数

输入样例:
*
结尾无空行
输出样例:
在这里给出相应的输出。例如：

3

*/


# include <stdio.h>

int main(void)
{
    char ch;
    
    scanf("%c", &ch);
    
    if (ch == '+' || ch == '-')
    {
        printf("%d", 4);
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        printf("%d", 3);
    }
    else if (ch == '>' || ch == '<')
    {
        printf("%d", 6);
    }
    else if(ch == '&')
    {
        printf("%d", 8);
    }
    else if(ch == '=')
    {
        printf("%d", 14);
    }
    else
    {
        printf("%d", -1);
    }
    
    return 0;
}