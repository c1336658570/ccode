/*
坐标型
最长上升子序列
描述
给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。
（最长上升连续子序列可以定义为从右到左或从左到右的序列。）

样例 1：
输入：[5, 4, 2, 1, 3]
输出：4
解释：
给定 [5, 4, 2, 1, 3]，其最长上升连续子序列（LICS）为 [5, 4, 2, 1]，返回 4。
样例 2：
输入：[5, 1, 2, 3, 4]
输出：4
解释：
给定 [5, 1, 2, 3, 4]，其最长上升连续子序列（LICS）为 [1, 2, 3, 4]，返回 4。
挑战
使用 O(n) 时间和 O(1) 额外空间来解决
*/

//动态规划
int longestIncreasingContinuousSubsequence2(int* A, int n) 
{
    if (n == 0 || n == 1)
        return n;
    int i, t = 0;
    int f[n];
    int g[n];
    f[0] = g[0] = 1;
    for (i = 1; i < n; ++i)
    {  
        if (A[i-1] < A[i])
            f[i] = f[i-1] + 1;
        else
            f[i] = 1;
        if (f[i] > t)
            t = f[i];
    }
    for (i = 1; i < n; ++i)
    {
        if (A[i-1] >= A[i])
            g[i] = g[i-1]+1;
        else
            g[i] = 1;
        if (g[i] > t)
            t = g[i];
    }

    return t;
}

int longestIncreasingContinuousSubsequence2(int* A, int n) 
{
    if (n == 0 || n == 1)
        return n;
    int i, j = 1, t = 0;
    for (i = 1; i < n; ++i)
    {  
        if (A[i-1] < A[i])
            j++;
        else
            j = 1;
        if (j > t)
            t = j;
    }
    j = 1;
    for (i = 1; i < n; ++i)
    {
        if (A[i-1] >= A[i])
            j++;
        else
            j = 1;
        if (j > t)
            t = j;
    }

    return t;
}
