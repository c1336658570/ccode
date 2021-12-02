/*
编写程序输出m-n以内能被3整除且不能被5整除的所有整数，并计算输出这样的数有多少个。

输入格式:
输入整数m、n，m<=n

输出格式:
第一行输出符合条件的数，用一个空格分隔。 第二行输出数据 个数。

输入样例:
在这里给出一组输入。例如：

100 130
结尾无空行
输出样例:
在这里给出相应的输出。例如：

102 108 111 114 117 123 126 129 
count=8
结尾无空行
*/
# include<stdio.h>

int main(void)
{
	int m, n, i, count;
	
	scanf("%d %d", &m, &n);
	
	count = 0;
	for (i=m; i<=n; ++i)
	{
		if (i%3 == 0 && i%5 != 0)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount=%d", count);
	
	return 0;
 } 
