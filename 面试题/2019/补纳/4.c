/*
4.解释以下代码的输出结果。

void func(char* a)
{
	printf("%lu\n", sizeof(a)) ;
	printf("%lu\n", strlen(a)) ;
}
int main(int argc, char* argv[])
{
	char a[] = "hello world";
	char* b = "hello world";
	printf("%s", b);
	func(a);
	printf("%lu\n", sizeof(a));
	printf("%lu\n", strlen(a));
	return 0;
}
*/

# include <stdio.h>
# include <string.h>

void func(char* a)
{
	printf("%lu\n", sizeof(a)) ;
	printf("%lu\n", strlen(a)) ;
}
int main(int argc, char* argv[])
{
	char a[] = "hello world";
	char* b = "hello world";
	printf("%s", b);
	func(a);
	printf("%lu\n", sizeof(a));
	printf("%lu\n", strlen(a));
	return 0;
}