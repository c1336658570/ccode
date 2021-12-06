/*
2. 改写代码，在不改变 const 的情况下尝试使用更多的方法改变b的值。
int main(int argc, char* argv[])
{
const int b = 10;
// 自行添加语句，改变变量b的值
return 0;
}
*/

# include <stdio.h>

int main(int argc, char* argv[])
{
    
    const int b = 10;
    // 自行添加语句，改变变量b的值
    int a = 15;
    int *p = (int *)&b;
    *p = 15;
    printf("%d\n", b);

    int *q = &a;
    q[-1] = 20;

    printf("%d\n", b);
    return 0;
}