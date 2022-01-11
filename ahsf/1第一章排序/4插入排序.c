/*
	插入排序
	最好时间复杂度(N)
	最差时间复杂度(N平方)
	平均时间复杂度O(N平方)
	空间复杂度O(1)
	稳定
*/

# include <stdio.h>

void sort(int *arr, int len);
void traver(int *arr, int len);

int main(void)
{
    int arr[5] = {3, 2, 4, 1, 5};

	sort(arr, 5);
	traver(arr, 5);

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

void sort(int *arr, int len)
{
	int i, j, k;

	for (i = 1; i < len; ++i)
	{
		//为arr[i]在前面[0,i-1]有序区间找一个合适的位置
		for (j = i-1; j >= 0; --j)
		{
			if (arr[j] < arr[i])
			{
				break;
			}
		}

		//如果找到合适位置
		if (j != i-1)
		{
			int temp = arr[i];

			//所有元素后移一位
			for (k = i-1; k > j; k--)
			{
				arr[k+1] = arr[k];
			}
			arr[k+1] = temp;
		}
	}
}
