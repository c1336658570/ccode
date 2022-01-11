/*
    判断一个字符串是否是回文字符串
*/
# include <stdio.h>
# include<string.h>

int main(void)
{
    char a[101], s[101];
    int i, len, mid, next, top;

    gets(a);
    len = string(a);
    mid = len/2 - 1; // 求字符串中点
    top = 0; // 栈的初始化

    for (i = 0; i <= mid; ++i)
    {
        s[++top] = a[i];
    }

    if (len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }

    for (i = next; i <= len-1; ++i)
    {
        if (a[i] != s[top])
        {
            break;
        }
        top--;
    }

    //如果top==0，则说明栈内所有的字符都被一一匹配了
    if (top == 0)
    {
        printf("Yes!\n");
    }
    else
    {
        printf("No!\n");
    }
    printf("\n");

    return 0;
}