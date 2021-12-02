/*
    排序+去重
    输入：
        10
        20 40 32 67 40 20 89 300 400 15
    输出：
        15 20 32 40 67 89 300 400 
*/

# include <stdio.h>

void Quick_sort1(int *arr, int low, int high);
int FindPos(int *arr, int low, int high);

int main(void)
{
    int a[101], n, i, j, t;

    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    Quick_sort1(a, 1, n);

    printf("%d ", a[1]);

    for (i=2; i <= n; ++i)
    {
        if (a[i] != a[i-1])
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n");


    return 0;
}

void Quick_sort1(int *arr, int low, int high)
{
	int pos;
	if (low >= high)
	{
		return;
	}
	else
	{
		pos = FindPos(arr, low, high);
		Quick_sort1(arr, low, pos-1);
		Quick_sort1(arr, pos+1, high);
	}
}

int FindPos(int *arr, int low, int high)
{
	int temp = arr[low];

	while (low < high)
	{
		while (low < high && arr[high] >= temp)
			high--;
		arr[low] = arr[high];
		while (low < high && arr[low] <= temp)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = temp;
	return low;
}
