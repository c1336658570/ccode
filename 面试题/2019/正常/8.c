/*
8.请解释下面代码段中每一句的效果。
int val = 2018;
int *pi = 2019;
pi = &val;
*pi = 0;
*/

# include <stdio.h>

int main(void)
{
    int val = 2018;
    int *pi = 2019;
    printf("%d", *pi);
    pi = &val;
    *pi = 0;

    return 0;
}
