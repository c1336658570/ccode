/*
    实现atoi函数
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
 
int myatoi(char *a)
{
    int n = 0;
    while(*a)
    {
        n *= 10;
        if(!isdigit(*a))
        {
            return 0;
        }
        n += *a - '0';
        a++;
    }
    return n;
}
 
int main()
{
    char a[101];
    gets(a);
    printf("%d\n", myatoi(a));
    return 0;
}