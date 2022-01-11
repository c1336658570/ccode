# include <stdio.h>

void f(int n)
{
	if (n == 1)
		printf("哈哈\n");
	else
		f(n-1);
}

int main(void)
{
	f(3);

	return 0;
}