/*
序列型
打家劫舍
假设你是一个专业的窃贼，准备沿着一条街打劫房屋。每个房子都存放着特定金额的钱。你面临的唯一约束条件是：
相邻的房子装着相互联系的防盗系统，且 当相邻的两个房子同一天被打劫时，该系统会自动报警。
给定一个非负整数列表，表示每个房子中存放的钱， 算一算，如果今晚去打劫，在不触动报警装置的情况下,
你最多可以得到多少钱 。

样例 1:
输入: [3, 8, 4]
输出: 8
解释: 仅仅打劫第二个房子.
样例 2:
输入: [5, 2, 1, 3] 
输出: 8
解释: 抢第一个和最后一个房子
挑战
O(n) 时间复杂度 且 O(1) 存储。
*/

int rob(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int f[numsSize+1][2];  // f[i][0]存不偷第i-1栋房子，f[i][1]表示偷第i-1栋房子
    int i, j;
    f[0][0] = f[0][1] = 0;
    for (i = 1; i <= numsSize; ++i)
    {
        f[i][0] = f[i][1] = __INT_MAX__;

        f[i][0] = f[i-1][0] > f[i-1][1] ? f[i-1][0] : f[i-1][1];
        
        f[i][1] = f[i-1][0] + nums[i-1];
    }
    if (f[numsSize][0] > f[numsSize][1])
        return f[numsSize][0];
    return f[numsSize][1];
}

int rob(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int f[numsSize+1]; // 当第i-1栋房子偷时结果为f[i-1]+nums[i-2]，不偷时结果为f[i-1]
    int i, j;
    f[0] = 0;
    f[1] = nums[0];
    for (i = 2; i <= numsSize; ++i)
    {
        f[i] = __INT_MAX__;

        f[i] = f[i-1] > f[i-2]+nums[i-1] ? f[i-1] : f[i-2]+nums[i-1];

    }
    return f[numsSize];
}