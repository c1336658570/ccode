/*
编写代码，要求：输入参数是一个正整数，输出该整数所对应的二进制数对应的字符串。

输入格式:
正整数

输出格式:
输入的正整数对应的二进制字符串“1001”

输入样例:
在这里给出一组输入。例如：

9
结尾无空行
输出样例:
在这里给出相应的输出。例如：

1001
*/
# include <stdio.h>

int main(void)
{
	int val, i, j, n, k;
	char arr[33], a;
	
	scanf("%d", &val);
	
	i = 0;
	n = val;
	while (n)
	{
		k = n%2;
		arr[i] =  k+48;
		i++;
		n /= 2;
	}
	
	arr[i] = '\0';
	i--;
	
	j = 0;
	while (j<i)
	{
		a = arr[j];
		arr[j] = arr[i];
		arr[i] = a;
		--i;
		++j;
	}
	
	printf("%s", arr);
	
	return 0;
} 
