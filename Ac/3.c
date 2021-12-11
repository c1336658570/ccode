# include <stdio.h>

int main(void)
{
    int m, n, i, j;
    printf("%d %d", &m, &n);

    char arr[m][n];

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
            scanf("%c", &arr[i][j]);
    }

    return 0;
}