/*
蒜头君家的暖气经常出问题，每当暖气坏了，蒜头君就会持续感冒 m 天
（从坏的那天算起，两次感冒时间重叠不会累加）。蒜头君去寻求预言家的帮助，预言家告诉他接下来n
次暖气片坏掉的时间。根据这个时间，蒜头君就能知道他未来获得感冒的总天数。

输入格式
第一行两个整数 n,m，表示暖气片坏掉的次数以及每次感冒的持续天数。
第二行n个整数ai，表示暖气片坏掉的日期。
数据范围： 1≤n≤10000，1 <= m,ai <= 10的9次方，保证a i是严格递增的。

输出格式
一个整数，表示蒜头君感冒的总天数。

Sample Input
4 3
1 2 4 8
Sample Output
9
*/

# include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j, a, sum = 0, old = 0, new = 0;
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        old = new;
        new = a;
        if (i > 0 && new - old < m)
        {
            sum -= m-(new-old);
        }
        sum += m;
    }
    printf("%d\n", sum);

    return 0;
}