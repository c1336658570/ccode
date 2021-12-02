/*
    希尔排序
    最差时间复杂度O(N平方)
    平均时间复杂度O(N一点三次方)
    空间复杂度O(1)
    不稳定
*/

# include <stdio.h>

void shell_sort2(int *arr, int n);
void group_sort(int *arr, int len, int i, int gap);
void traver(int *arr, int len);

int main(void)
{
    int arr[5] = {3, 1, 4, 2, 5};

    shell_sort2(arr, 5);
    traver(arr, 5);

    return 0;
}

void traver(int *arr, int len)
{
	int i;

	for (i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void shell_sort2(int *arr, int len)
{
    int i, gap;

    //gap为步长，每次减为原来的一半
    for (gap = len/2; gap > 0; gap /= 2)
    {
        //共gap个组，对每一组都执行直接插入排序
        for (i = 0; i < gap; ++i)
        {
            group_sort(arr, len, i, gap);
        }
    }
}

//len--数组长度  i--数组的起始位置  gap--数组的步长
//将相隔gap个元素的数取出排序
void group_sort(int *arr, int len, int i, int gap)
{
    int j;

    for (j = i+gap; j < len; j+=gap)
    {
        //如果a[j] < arr[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移
        if (arr[j] < arr[j-gap])
        {
            int temp = arr[j];
            int k = j - gap;
            while (k >= 0 && arr[k] > temp)
            {
                arr[k+gap] = arr[k];
                k -= gap;
            }
            arr[k+gap] = temp;
        }
    }
}