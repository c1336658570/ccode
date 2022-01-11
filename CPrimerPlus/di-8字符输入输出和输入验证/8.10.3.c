/*
    通过重定向统计字符数，输出到文件
*/
# include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;
    int t;

    while( (ch = getchar()) != EOF )
    {
        t++;
    }
    printf("%d", t);

    return 0;
}