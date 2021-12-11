# include <stdio.h>

int main(void)
{
    int n, i, j, k;

    scanf("%d", &n);
    int flag[n];
    int min[n+1];
    char name[n][101];

    min[n] = 1000000;
    for (i = 0; i < n; ++i)
    {
        flag[i] = 0;
        scanf("%s %d", name[i], &min[i]);
        while(getchar() != '\n')
            continue;
    }
    for (i = 0; i < n; ++i)
    {
        k = n;
        for (j = 0; j < n; ++j)
        {
            if (min[k] > min[j] && flag[j] == 0)
            {
                k = j;
            }
        }
        flag[k] = 1;
        printf("%s", name[k]);
    }

    return 0;
}