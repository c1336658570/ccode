# include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    double arr1[8], arr2[8];

    for (i = 0; i < 8; i++)
    {
        scanf("%lf", arr1+i);
    }

    arr2[0] = arr1[0];
    printf("%.2lf ", arr1[0]);
    for (i = 1; i < 8; ++i)
    {
        printf("%.2lf ", arr1[i]);
        arr2[i] = arr2[i-1] + arr1[i];
    }
    puts("\n");
    for (i = 0; i < 8; ++i)
    {
        printf("%.2lf ", arr2[i]);
    }

    return 0;
}