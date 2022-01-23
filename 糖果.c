# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(void)
{
    int i, k, day = 0, sum = 0;

    scanf("%d", &k);

    for (i = 1; ; ++i)
    {
        day += i;
        if (day >= k)
            break;
    }
    if (day == k)
    {
        for (; i >= 1; --i)
        {
            sum += i * i;
        }
    }
    else
    {
        sum += (k - (day - i) ) * i;
        for (i = i-1; i >= 1; --i)
        {
            sum += i*i;
        }
    }
    printf("%d\n", sum);
}
