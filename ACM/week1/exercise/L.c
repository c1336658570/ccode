/*
历经旷日持久的战争之后，百纳瑞王国（The Kingdom of Binary）终于迎来了胜利的曙光。
于是国王决定在胜利日这一天为在战争中奋战的将领们授勋。
已经需要为N位将领授勋，他们每人有一个功勋值p[i]。国王准备了不同种类的勋章，
它们分别代表1,2,4,8,16......（即2的幂次）的功勋值。国王将用与每位将领功勋值对等数值的勋章授予他们，
并且每位将领只会被授予一枚同种勋章。

现在请你帮助国王算出，对于每一位将领，他需要准备多少枚勋章？

Input
第一行输入一个数N，表示将领人数； 之后N行，每行输入一个数，分别表示每位将领的功勋值。
Output
输出N行，每行一个数表示需要授予该将领的勋章数。
Sample Input
3
15
1
22
Sample Output
4
1
3
*/

# include <stdio.h>
# include <math.h>

int main(void)
{
    int sum;
    int i, n, val;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        sum = 0;
        scanf("%d", &val);
        while (val)
        {
            if (val % 2 == 1)
                sum++;
            val/=2;
        }
        printf("%d\n", sum);
        
    }

    return 0;
}