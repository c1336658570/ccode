/*
给出不同面额的硬币以及一个总金额. 写一个方法来计算给出的总金额可以换取的最少的硬币数量. 
如果已有硬币的任意组合均无法与总金额面额相等, 那么返回 -1.

你可以假设每种硬币均有无数个
总金额不会超过10000
硬币的种类数不会超过500, 每种硬币的面额不会超过100

样例1

输入：
[1, 2, 5]
11
输出： 3
解释： 11 = 5 + 5 + 1
样例2

输入： 
[2]
3
输出： -1
*/

# include <stdio.h>

int max(a, b);

int coinChange(int* coins, int amount, int n){
    int f[amount+1];
    int i, j;
    f[0] = 0;

    for (i = 1; i <= amount; ++i)
    {
        f[i] = __INT_MAX__;
        for (j = 0; j < n; ++j)
        {
            if (i >= coins[j] && f[i-coins[j]] != __INT_MAX__ && f[i - coins[j]]+1 < f[i])
                f[i] = f[i-coins[j]] + 1;

            // if (i >= coins[j] && f[i-coins[j]] != __INT_MAX__)
            //     f[i] = max(f[i], f[i-coins[j]] + 1);
        }
    }
    if (f[amount] == __INT_MAX__)
        return -1;
    return f[amount];
}

int max(a, b)
{
    return a > b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount){
    int f[amount+1];
    f[0] = 0;
    int i, j;
    for (i = 1; i <= amount; ++i)
    {
        f[i] = 0x7fffffff;
        for (j = 0; j < coinsSize; ++j)
        {
            if (i-coins[j] >= 0 && f[i-coins[j]] != 0x7fffffff && f[i] > f[i-coins[j]]+1)
                f[i] = f[i-coins[j]]+1;
        }
    }
    if (f[amount] == 0x7fffffff)
        return -1;
    return f[amount];
}