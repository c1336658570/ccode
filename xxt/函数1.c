/*
最大公约数与最小公倍数。题目内容：编写两个函数，分别求两个整数的最大公约数和最小公倍数，
并用主函数调用这两个函数，然后输出结果。两个整数由键盘输入。约定最大公约数为正整数，两数里有负的则最小公倍数就为负的。



输入格式：输入均不为0的整数n和m(n与m的乘积还在整数范围内)（两数之间用英文,隔开）

输出格式：输出这两个整数的最大公约数和最小公倍数（两结果之间用英文,隔开）



输入样例：24,36

输出样例：12,72


输入样例：-48,128

输出样例：16,-384

时间限制：500ms内存限制：32000kb
*/ 

# include <stdio.h> 

int f(int , int );
int g(int , int );

int main(void)
{
	int m, n;
	
	scanf("%d,%d", &m, &n);
	printf("%d,%d\n", f(m, n), g(m, n));
	
	return 0;
}

int f(int m, int n)
{
	int i, j, min;
	
	min = m;
	if (abs(min) > abs(n))
		min = n;
	
	for (i=1; i<abs(min); ++i)
	{
		if (m%i == 0 && n%i == 0)
		{
			j = i;	
		}
	}
	return j;
}

int g(int m, int n)
{
	int i, j, max;
	
	max = m;
	if (abs(max) < abs(n))
	{
		max = n;
	}
	
	for (i=abs(max); ; ++i)
	{
		if (i%m == 0 && i%n == 0)
		{
			j = i;
			break; 
		}
	}
	if (m<0 || n<0)
	{
		j = -j;
	}
	return j;
	
}
