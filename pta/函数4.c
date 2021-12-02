/*
编写一个函数，用于判断用户输入的字符串是否由小写字母和数字构成。

输入格式:
输入一个字符串

输出格式:
如果输入的字符串由小写字母和数字构成，输出“全是数字和小写字母”，否则输出”不全是数字和小写字母“

输入样例1:
在这里给出一组输入。例如：

abc123
结尾无空行
输出样例1:
在这里给出相应的输出。例如：

全是数字和小写字母
结尾无空行
*/


# include <stdio.h>
# include <stdbool.h>
# include <string.h>

bool f(char *arr);

int main(void)
{
    char arr[50];
    fgets(arr, 50, stdin);
    if(f(arr))
    {
        printf("全是数字和小写字母");
    }
    else
    {
        printf("不全是数字和小写字母");
    }
    
    return 0;
}

bool f(char *arr)
{
    int i = 0;
    
    for (i = 0; i < strlen(arr) - 1; ++i)
    {
        if (arr[i] < '0' || (arr[i] > '9' && arr[i] < 'a') || arr[i] > 'z')
            return false;
    }
    return true;
}