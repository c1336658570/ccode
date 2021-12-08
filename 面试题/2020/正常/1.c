/*
1.运行下面代码，输出什么结果，请解释说明
int i;
int main(int argc, char *argv[])
{
	 i--;
	 if (i > sizeof(i))
	 {
		 printf(">\n");
	 }
	 else
	 {
		 printf("<\n");
	 }
	 return 0;
}
*/
# include <stdio.h>

int i;
int main(int argc, char *argv[])
{
	 i--;
	 if (i > sizeof(i))
	 {
		 printf(">\n");
	 }
	 else
	 {
		 printf("<\n");
	 }
	 return 0;
}