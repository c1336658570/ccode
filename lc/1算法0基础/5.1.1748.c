/*
给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
请你返回 nums 中唯一元素的 和 。

示例 1：

输入：nums = [1,2,3,2]
输出：4
解释：唯一元素为 [1,3] ，和为 4 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：0
解释：没有唯一元素，和为 0 。
示例 3 ：

输入：nums = [1,2,3,4,5]
输出：15
解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
*/

int sumOfUnique(int* nums, int numsSize){
    int i, j, res[numsSize], sum = 0;
    for (i = 0; i < numsSize; ++i)
    {
        res[i] = 0;
    }
    for (i = 0; i < numsSize-1; ++i)
    {
        for (j = i+1; j < numsSize; ++j)
        {
            if (nums[i] == nums[j])
            {
                res[i] = res[j] = 1;
            }
        }
        if (res[i] == 0)
            sum += nums[i];
    }
    if (res[numsSize - 1] == 0)
        sum += nums[numsSize - 1];
    return sum;
}

int sumOfUnique(int* nums, int numsSize){
    int i, res[101], sum = 0;
    
    memset(res, 0, sizeof(res));

    for (i = 0; i < numsSize; ++i)
    {
        res[nums[i]]++;
    }
    for (i = 0; i < numsSize; ++i)
    {
        if (res[nums[i]] == 1)
            sum += nums[i];
    }

    return sum;
}