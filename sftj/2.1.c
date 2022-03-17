/*
选择排序
*/

# include <stdio.h>

void sort(int *a, int len);

int main(void)
{
    int a[5] = {5, 3, 6, 2, 10};
    int i;
    
    for (i = 0; i < 5; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    sort(a, 5);
    for (i = 0; i < 5; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void sort(int *a, int len)
{
    int i, j;
    for (i = 0; i < len-1; ++i)
    {
        for (j = i+1; j < len; ++j)
        {
            if (a[i] < a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}