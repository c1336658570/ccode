/*
10.执行下面程序段，其输出结果是什么，并解释
int main(int argc, char *argv[])
{
	 int a = 1;
	 printf("%d\n", *(char *)&a);
}
*/

# include <stdio.h>

int main(int argc, char *argv[])
{
	 int a = 1;
	 printf("%d\n", *(char *)&a);
}