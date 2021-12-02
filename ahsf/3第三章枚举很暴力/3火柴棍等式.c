/*
    小哼有m根火柴（m <= 24）
    拼出A+B=C
    + = 各两根火柴

输入
    18
输出
    0+4 = 4
    0+11 = 11
    1+10 = 11
    2+2 = 4
    2+7 = 9
    4+0 = 4
    7+2 = 9
    10+1 = 11
    11+0 = 11
    可以拼出不同的等式数量是9
*/

#include<stdio.h>
int fun(int x)
  {
    int num = 0;
    int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    while(x/10 != 0) //x至少两位
    {
        num += f[x%10];
        x = x/10;
    }
    num += f[x];
    return num;
   }
int main()
{
    int a, b, c, m, i, sum=0;
    scanf("%d", &m);//输入火柴棍个数
    for(a=0; a<11111; a++)
    {
        for(b=0; b<11111; b++)
        {
           c = a+b;
           if(fun(a)+fun(b)+fun(c) == m-4)
            {
               printf("%d+%d = %d\n", a, b, c);
               sum++;
            }
        }
    }
    printf("可以拼出不同的等式数量是%d\n",sum);
    getchar();
    getchar();
    return 0;
}