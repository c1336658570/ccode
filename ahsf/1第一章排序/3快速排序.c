/*
	快速排序
	最差时间复杂度O(N平方)
	平均时间复杂度O(NlogN)
	空间复杂度O(N)
	不稳定
*/

# include <stdio.h>

int FindPos(int *arr, int low, int high);
void Quick_sort1(int *arr, int low, int high);
void Quick_sort2(int *arr, int low, int high);
void Quick_sort3(int *arr, int low, int high);
void traver(int *arr, int len);

int main(void)
{
	int arr[5] = {3, 2, 4, 1, 5};

	Quick_sort3(arr, 0, 4);
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

void Quick_sort2(int *arr, int low, int high)
{
	if (low < high)
	{
		int i, j, temp;

		i = low;
		j = high;
		temp = arr[i];
		while (i < j)
		{
			while(i < j && arr[j] >= temp)
				j--;
			arr[i] = arr[j];
			while(i < j && arr[i] <= temp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = temp;
		Quick_sort2(arr, low, i-1);
		Quick_sort2(arr, i+1, high);
	}
	else
		return;
}

void Quick_sort3(int *arr, int low, int high)
{
	int i, j, t, temp;

	if (low > high)
		return;
	else
	{
		temp = arr[low];
		i = low;
		j = high;

		while(i != j)
		{
			while(i < j && arr[j] >= temp);
				j--;
			while(i < j && arr[i] <= temp)
				i++;
			
			if (i < j)
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
		arr[low] = arr[i];
		arr[i] = temp;

		Quick_sort3(arr, low, i-1);
		Quick_sort3(arr, i+1, high);
	}
}