/*
	冒泡排序
	时间复杂度O(N平方)
	空间复杂度O(1)
	稳定
*/

# include <stdio.h>

void traver(int *arr, int len);
void sort1(int *arr, int len);
void sort2(int *arr, int len);
void sort3(int *arr, int len);

int main(void)
{
	int arr[5] = {1, 3, 2, 5, 4};

	sort4(arr, 5);
	
	traver(arr, 5);

	return 0;
}

//输出
void traver(int *arr, int len)
{
	int i;

	for (i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort1(int *arr, int len)
{
	int i, j;

	for (i = 0; i < len-1; ++i)
	{
		for (j = 0; j < len-1-i; ++j)
		{
			if (arr[j] < arr[j+1])
			{
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
		}
	}
}

//优化1
void sort2(int *arr, int len)
{
	int i, j;
	int flag;

	for (i = 0; i < len-1; ++i)
	{
		flag = 0;
		for (j = 0; j < len-1-i; ++j)
		{
			if (arr[j] < arr[j+1])
			{
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

//优化2
void sort3(int *arr, int len)
{
	int i, j, k;
	int flag, pos;

	k = len - 1;
	pos = 0;
	for (i = 0; i < len-1; ++i)
	{
		flag = 0;
		for (j = 0; j < k; ++j)
		{
			if (arr[j] < arr[j+1])
			{
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
				flag = 1;
				pos = j;
			}
		}
		k = pos;
		if (flag == 0)
		{
			return;
		}
	}
}