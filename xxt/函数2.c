/*
100以内的素数。题目内容：求100以内的全部素数，每行输出10个。素数就是只能被1和自身整除的正整数，
1不是素数，2是素数。要求定义和调用函数prime(m)判断m是否为素数，当m为素数时返回1，否则返回0。

输入格式：没有输入数据。

输出格式：输出100以内的素数，每行输出10个

                 提示：可使用输出语句printf("%6d",m);来控制素数之间的输出间隔。



输出样例：

     2     3     5     7    11    13    17    19    23    29

    31    37    41    43    47    53    59    61    67    71

    73    79    83    89    97

时间限制：500ms内存限制：32000kb

*/

# include <stdio.h>
# include <math.h>
# include <stdbool.h>

_Bool prime(int );

int main(void)
{
	int i, count;
	
	count = 0;
	for (i=2; i<100; ++i)
	{
		if (prime(i))
		{
			printf("%6d", i);
			++count;
		}
		if (count%10 == 0)
		{
			printf("\n");
		}
	}
	
	return 0;
}

bool prime(int m)
{
	int i;
	
	for (i=2; i<=sqrt(m); ++i)
	{
		if (0 == m%i)
		{
			return false;
		}
	}
	return true;
}
