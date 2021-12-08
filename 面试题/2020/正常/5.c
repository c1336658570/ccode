/*
    分析下面代码，推测并验证其作用
*/

# include <stdio.h>

int main(int argc, char *argv[])
{
	 int number;
	 unsigned mask;
	 mask = 1u << 31;
	 scanf("%d", &number);
	 while (mask)
	 {	
		 printf("%d", (number & mask) ? 1 : 0);
		 mask >>= 1;
         
	 }
	 return 0;
}