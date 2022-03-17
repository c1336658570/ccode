/*
二分查找
*/

# include <stdio.h>
int binary_search(int *a, int len, int n);


int main(void)
{
    int a[5] = {1, 3, 5, 7, 9};
    printf("%d\n", binary_search(a, 5, 3));

    return 0;
}

int binary_search(int *a, int len, int n)
{
    int low = 0;
    int high = len-1;
    int middle;

    while(low <= high)
    {
        middle = (low + high) / 2;
        if (a[middle] < n)
            low = middle+1;
        else if (a[middle] > n)
            high = middle-1;
        else return middle;
    }
    return -1;
}