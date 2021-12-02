/*
请编写程序，输入一系列单词，然后按字典顺序排序，最后输出结果。

输入格式
第一行为单词的数量 n (0<n<10000)，后面有 n 行，每行一个英文单词(均由小写字母组成，且长度均不超过15个英文字母)

输出格式
共 n 行，每行一个英文单词(按字典顺序排列)

输入样例
3
stick
stock
stack
结尾无空行
输出样例
stack
stick
stock
*/ 

# include <stdio.h>
# include <string.h>
# include <malloc.h>

int main(void)
{
	int n, i, j, k;
	char c[16];
	
	scanf("%d", &n);
	
	char **arr = (char**)malloc(sizeof(char*) * n);
	
	for (i=0; i<n; ++i)
	{
		arr[i] = (char*)malloc(sizeof(char) *16);
		scanf("%s", arr[i]);
	}
	
	for (i=0; i<n-1; ++i)
	{
		k = i;
		for (j=i+1; j<n; ++j)
		{
			if (strcmp(arr[k], arr[j]) > 0)
			{
				k = j;
			}
		}
		
		if (k != i)
		{
			strcpy(c, arr[k]);
			strcpy(arr[k], arr[i]);
			strcpy(arr[i], c);
		}
	}
	
	for (i=0; i<n; ++i)
	{
		printf("%s", arr[i]);
		free(arr[i]);
		if (i == n-1)
			break;
		printf("\n");
	}
	free(arr);
	
	return 0;
}
