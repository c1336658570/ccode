/*
11.下面程序的输出结果是什么，若取消第三行const注释，
a数组还能被修改吗？如果取消6，8行注释，程序还能运行吗？试解释说明
*/

# include <stdio.h>

int main(int argc, char *argv[])
{
	 /*const*/ char a[] = "XiyouLinux\0";
	 char *b = "XiyouLinux\0";
	 a[5] = '\0';
	 // b[5] = '\0';
	 printf("%s\n", a);
	 // printf("%s\n",b);
	 return 0;
}