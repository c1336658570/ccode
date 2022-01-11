/*
9.运行下面代码，解释运行结果并谈谈自己的理解

int main(int argc, char *argv[])
{
	 int a[6] = {0x6f796958, 0x694c2075, 0x2078756e, 0x756f7247, 0x30322070,
	0};
	 printf("%d\n", printf("%s", (char *)a));
	 return 0;
}
*/

# include <stdio.h>

int main(int argc, char *argv[])
{
	 int a[6] = {0x6f796958, 0x694c2075, 0x2078756e, 0x756f7247, 0x30322070,
	0};
	 printf("%d\n", printf("%s", (char *)a));
	 return 0;
}