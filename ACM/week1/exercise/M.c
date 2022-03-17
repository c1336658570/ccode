/*
形如 a^3= b^3 + c^3 + d^3的等式被称为完美立方等式。
例如 12^3= 6^3 + 8^3 + 10^3
编写一个程序，对任给的正整数N(N≤100)，寻找所有的四元组 (a, b, c, d)
使得 a^3 = b^3 + c^3 + d^3a ，其中 a,b,c,d大于1，小于等于N，b≤c≤d。

输入格式
一个正整数 N(N≤100)。
输出格式
每行输出一个完美立方。输出格式为：
Cube = a, Triple = (b,c,d)
其中 a,b,c,d所在位置分别用实际求出四元组值代入。
请按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则b值小的优先输出；
仍相同则c值小的优先输出；再相同则d值小的先输出。

Sample Input
24
Sample Output
Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)
*/

# include <stdio.h>

int main(void)
{
    int a, b, c, d, n;
    scanf("%d", &n);

    for (a = 2; a <= n; ++a)
    {
        for (b = 2; b <= a; ++b)
        {
            for (c = b; c <= a; ++c)
            {
                for (d = c; d <= a; ++d)
                {
                    if (a*a*a == b*b*b + c*c*c + d*d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }

    return 0;
}