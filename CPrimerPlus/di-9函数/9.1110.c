/*
    将一个整数以m进制输出
*/
# include <stdio.h>

void to_base_n(unsigned long n, int m);

int main(int argc, char *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    to_base_n(n, m);

    return 0;
}

void to_base_n(unsigned long n, int m) // 2 <= m <= 10
{
    char r;
    r = n % m;
    if (n >= m)
        to_base_n(n/m, m);
    printf("%c", r + '0');
}