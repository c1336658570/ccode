/*
	选择排序
	时间复杂度O(N平方)
	空间复杂度O(1)
	不稳定
*/

# include <stdio.h>

void sort1(int *arr, int len);
void sort2(int *arr, int len);
void traver(int *arr, int len);
void swap(int *a, int *b);
void sort3(int *a, int len);

int main(void)
{
	int arr[5] = {3, 2, 4, 5, 1};

	sort3(arr, 5);
	
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

void sort1(int *arr, int len)
{
	int i, j;

	for (i = 0; i < len-1; ++i)
	{
		for (j = i+1; j < len; ++j)
		{
			if (arr[i] < arr[j])
			{
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];
			}
		}
	}
}

//优化1
void sort2(int *arr, int len)
{
    int i, j;
	int flag = 0;

	for (i = 0; i < len-1; ++i)
	{
		flag = i;
		for (j = i+1; j < len; ++j)
		{
				if (arr[flag] < arr[j])
				{
						flag = j;
				}
		}
		if (i != flag)
		{
			arr[i] = arr[i] ^ arr[flag];
			arr[flag] = arr[i] ^ arr[flag];
			arr[i] = arr[i] ^ arr[flag];

		}
	}
}

void sort3(int *a, int len)
{
	int begin, end, i, t;

	begin = 0;
	end = len - 1;

	while(begin < end)
	{
		int maxi, mini;

		maxi = mini = begin;
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(&a[mini], &a[begin]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[end]);
		end--;
		begin++;
	}
	
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}