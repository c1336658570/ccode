# include <stdio.h>
# include <time.h>
# include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return ( *( (int*)b ) - *( (int*)a ) );
}


int main(int argc, char *argv[])
{
    int arr[100], i = 0;

    srand(time(0));
    while (i < 100)
    {
        arr[i] = rand()%10+1;
        ++i;
    }
    qsort(arr, 100, sizeof(arr[0]), cmp);
    for (i = 0; i < 100; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}