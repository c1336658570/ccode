/*
有如下代码段所示的函数 f，当我们执行该函数时，会产生什么样的输出结果？在同一程序中
多次执行该函数，输出结果是否一致？
void f() {
    static int a = 0;
    int b = 0;
    printf("%d, %d\n", ++a, ++b);
}

*/
# include <stdio.h>


void f() {
    static int a = 0;
    int b = 0;
    printf("%d, %d\n", ++a, ++b);
}

int main(void)
{
    f();
    f();
}