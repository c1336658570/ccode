/*
爬楼梯。题目内容：可爱的小明特别喜欢爬楼梯，他有的时候一次爬一个台阶，有的时候一次爬两个台阶，
有的时候一次爬三个台阶。如果这个楼梯有n个台阶，小明一共有多少种爬法呢？n值从键盘输入。

输入格式：输入一个整数n,(1<=n<46)。

输出格式：输出当楼梯阶数是n时的上楼方式总数。

输入样例：1

输出样例：1

输入样例：4

输出样例：7

输入样例：24

输出样例：1389537

时间限制：500ms内存限制：32000kb

*/

# include <stdio.h>

int main(void)
{
	int i, j, k, n, n1, n2, n3, n4, count;
	
	scanf("%d", &n);
	
	count = 0;
	n1 = 1;
	n2 = 2;
	n3 = 4;
	
	if (n == 1)
		n4 = n1;
	else if(n == 2)
		n4 = n2;
	else if(n == 3)
		n4 = n3;
	else
	{
		for (i=3; i<n; ++i)
		{
			n4 = n1+n2+n3;
			n1 = n2;
			n2 = n3;
			n3 = n4;
		}
	}
	
	printf("%d\n", n4);
	
	return 0; 
}


// 递归  
/*# include <stdio.h>

int f(int );

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d\n", f(n));
	
	return 0; 
}

int f(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if(n == 2)
	{
		return 2;
	}
	else if(n == 3)
	{
		return 4;
	}
	else
	{
		return f(n-1) + f(n-2) + f(n-3);
	}
}
*/

