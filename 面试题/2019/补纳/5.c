/*
 - [ ] 5.解释以下代码的输出结果。

```c
#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)
int main(int argc, char* argv[])
{
	printf("%s\n", h(f(1,2)));
	printf("%s\n", g(f(1,2)));
	return 0;
}
*/

# include<stdio.h>
#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

int main(int argc, char* argv[])
{
	printf("%s\n", h(f(1,2)));
	printf("%s\n", g(f(1,2)));
	return 0;
}