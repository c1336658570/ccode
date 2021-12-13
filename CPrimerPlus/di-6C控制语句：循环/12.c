# include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, s = -1, p = 1, n;
    float sum1 = 1, sum2 = 1;

    scanf("%d", &n);

    for (i = 2; i <= n; i++)
    {
        sum1 += (float)p/i;
        sum2 += (float)s/i;
        s = -s;
    }
    printf("%f\n", sum1);
    printf("%f\n", sum2);

    return 0;
}