/*
 7.以下程序段运行结果是什么，你知道怎么判断两个浮点数是否相同吗

int main(int argc, char *argv[])
{
	 double a = 3.14;
	 float b = a;
	 if ((float)a == b)
	 {
	 	printf("Xiyou");
	 }
	 if (a != b)
	 {
	 	printf("LinuxGroup\n");
	 }
	 return 0;
}
*/

# include <stdio.h>

int main(int argc, char *argv[])
{
	 double a = 3.14;
	 float b = a;
	 if ((float)a == b)
	 {
	 	printf("Xiyou");
	 }
	 if (a != b)
	 {
	 	printf("LinuxGroup\n");
	 }
	 return 0;
}