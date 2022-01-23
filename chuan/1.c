/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2022年01月22日 星期六 12时30分10秒
 ************************************************************************/

#include<stdio.h>
# include <string.h>
# define N 1000

void Get_Next(char *, char *);

int main(void)
{
    int i;
    char a[N], b[N];
    char next1[N], next2[N];

    memset(a, 0, sizeof(next1));
    memset(b, 0, sizeof(next2));

    scanf("%s %s", a+1, b+1);

    Get_Next(a, next1);
    Get_Next(b, next2);

    for (i = 1; i <= strlen(a+1); ++i)
        printf("%d\t", next1[i]);
    printf("\n");
    for (i = 1; i <= strlen(b+1); ++i)
        printf("%d\t", next2[i]);
    printf("\n");

    return 0;
}

void Get_Next(char *a, char *next)
{
    int n, i, j;
    n = strlen(a+1);
    for (i = 2, j = 0; i <= n; ++i)
    {
        while(j && a[j+1] != a[i])
            j = next[j];
        if (a[j+1] == a[i])
            ++j;
        next[i] = j;
    }
}

