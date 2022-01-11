/*
2.执行下面代码段，输出结果和你预想的一样吗，谈谈你对宏的理解

#define A 2 + 2
#define B 3 + 3
#define C A * B
int main(int argc, char *argv[])
{
	 printf("%d\n", C);
	 return 0;
}
*/

# include <stdio.h>
#define A 2 + 2
#define B 3 + 3
#define C A * B

int main(int argc, char *argv[])
{
    printf("%d\n", C);
    return 0;
}