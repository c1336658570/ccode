/*
数组nums包含从0到n的所有整数，
但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

示例 1：

输入：[3,0,1]
输出：2
 
示例 2：

输入：[9,6,4,2,3,5,7,0,1]
输出：8
*/

//位运算
int missingNumber(int* nums, int numsSize){
    int i = 0, res = numsSize;

    for ( ; i < numsSize; ++i)
    {
        res ^= i;
        res ^= nums[i];
    }

    return res;
}

//求和
int missingNumber(int* nums, int numsSize){
    int sum, res = 0;

    sum = (1+numsSize)*numsSize / 2;
    
    numsSize -= 1;
    while (numsSize >= 0)
    {
        res += nums[numsSize];
        numsSize -= 1;
    }

    return (sum - res);
}