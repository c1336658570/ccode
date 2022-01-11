/*
    构造函数，求a的b次方，使用递归
*/
# include <stdio.h>

double power(double a, double b);

int main(int argc, char *argv[])
{
    double a, b;

    while ( scanf("%lf %lf", &a, &b) == 2)
    {
        printf("%.2f\n", power(a, b));
    }

    return 0;
}

double power(double a, double b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b < 0)
    {
        b = -b;
        a = 1 / a;
        return power(a, b-1)*a;
    }
    else
    return power(a, b-1) * a;
}