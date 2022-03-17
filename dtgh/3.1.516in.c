/*
序列型
房屋染色
这里有n个房子在一列直线上，现在我们需要给房屋染色，共有k种颜色。
每个房屋染不同的颜色费用也不同，你希望每两个相邻的房屋颜色不同
费用通过一个nxk 的矩阵给出，比如cost[0][0]表示房屋0染颜色0的费用，
cost[1][2]表示房屋1染颜色2的费用。找到油漆所有房子的最低成本。
所有费用都是正整数

样例1
输入:
costs = [[14,2,11],[11,14,5],[14,3,10]]
输出: 10
说明:
三个屋子分别使用第1,2,1种颜色，总花费是10。
样例2
输入:
costs = [[5]]
输出: 5
说明：
只有一种颜色，一个房子，花费为5
用O(nk)的时间复杂度解决
*/

//O(NK平方)
# include <stdio.h>

int minCostII(int **costs, int size, int *colsize) {
    // write your code here
    if (costs == NULL || size == 0 || *colsize == 0)
        return 0;
    int m = size;
    int n = colsize[0];
    int f[m+1][n];
    int i, j, k;
    int result = __INT_MAX__;
    if (m == 1 && n == 1)
    {
        return costs[0][0];
    }
    for (i = 0; i <= m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            f[i][j] = __INT_MAX__;
            if (i == 0)
            {
                f[i][j] = 0;
                continue;
            }
            
            for (k = 0; k < n; ++k)
            {
                if (j == k )
                    continue;
                if (f[i][j] > f[i-1][k] + costs[i-1][j])
                    f[i][j] = f[i-1][k] + costs[i-1][j]; 
            }
        }
    }
    for (i = 0; i < n; ++i)
    {
        if (result > f[m][i])
            result = f[m][i];
    }
    return result;
}

//O(NK)
/*
去掉一个元素，找最小值，只需要找到最小的和次小的就可以，当不去掉最小值时，最小的就是自己
去掉最小值以后，最小的就是次小的
*/
int minCostII(int **costs, int size, int *colsize) {
    // write your code here
    if (costs == NULL || size == 0 || *colsize == 0)
        return 0;
    int m = size;
    int n = *colsize;
    int f[m+1][n];
    int i, j;
    int j1 = 0, j2 = 0;  //j1存最小值下标，j2存次小值下标
    int min1, min2;  // min1存最小值，min2存次小值

    for (i = 0; i < n; ++i)
    {
        f[0][i] = 0;
    }
    for (i = 1; i <= m; ++i)
    {
        min1 = min2 = __INT_MAX__;
        for (j = 0; j < n; ++j)
        {
            if (f[i-1][j] < min1)
            {
                min2 = min1;
                j2 = j1;
                min1 = f[i-1][j];
                j1 = j;
            }
            else
            {
                if (f[i-1][j] < min2)
                {
                    min2 = f[i-1][j];
                    j2 = j;
                }
            }
        }
        for (j = 0; j < n; ++j)
        {
            if (j != j1)
            {
                f[i][j] = f[i-1][j1] + costs[i-1][j];
            }
            else
            {
                f[i][j] = f[i-1][j2] + costs[i-1][j];
            }
        }
    }
    int result = __INT_MAX__;
    for (i = 0; i < n; ++i)
    {
        if (f[m][i] < result)
            result = f[m][i];
    }
    return result;
}