/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2022年01月22日 星期六 12时43分06秒
 ************************************************************************/

#include<stdio.h>
# include <string.h> 

# define N 1000

char a[N], b[N];
int next[N];

void Get_Next();
void KMP();

int main()
{
    scanf("%s", a+1);
    scanf("%s", b+1);
    Get_Next();
    KMP();
    for (int i = 1; b[i]; ++i)
        printf("%d ", next[i]);
    
    return 0;
}

void Get_Next()
{
    int i, j, n;
    n = strlen(b+1);
    for (i = 2, j = 0; i <= n; ++i)
    {
        while(j && b[j+1] != b[i])
            j = next[j];
        if (b[j+1] == b[i])
            ++j;
        next[i] = j;
    }
}

void KMP()
{
    int m = strlen(a+1), n = strlen(b+1);
    for (int i = 1, j = 0; i <= m; ++i)
    {
        while (j && b[j+1] != a[i])
            j = next[j];
        if (b[j+1] == a[i])
            ++j;
        if (j == n)
        {
            printf("%d\n", i-n+1);
            j = next[j];
        }
    }
}

