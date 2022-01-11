/*
    编写函数读入单词，丢弃前面所有空白，和空白后面所有字符
*/

# include <stdio.h>

char *Input(char *arr);

int main(void)
{


    return 0;
}

char *Input(char *arr)
{
    char ch, *p = arr;
    while( (ch = getchar()) < ' ' )
        continue;
    while(ch > ' ')
    {
        *arr = ch;
        ch = getchar();
        arr++;
    }
    *arr = '\0';
    return p;
}