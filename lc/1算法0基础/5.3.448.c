/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
示例 2：

输入：nums = [1,1]
输出：[2]
*/

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int i, j = 0;
    int arr[numsSize+1];
    
    memset(arr, 0, sizeof(arr));

    for (i = 1; i <= numsSize; ++i)
    {
        arr[nums[i-1]]++;
    }
    for (i = 1; i <= numsSize; ++i)
    {
        if (arr[i] == 0)
        {
            arr[j] = i;
            j++;
        }
    }
    (*returnSize) = j;
    int *res = (int *)malloc(sizeof(int) * j);
    for (i = 0; i < j; ++i)
    {
        res[i] = arr[i];
    }
    return res;
}

//时间复杂度：O(n)，空间复杂度O(1)，未使用第三方数组
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) *numsSize);
    int x, i;
    for (i = 0; i < numsSize; ++i)
    {
        x = (nums[i]-1) % numsSize;
        nums[x] += numsSize;
    }
    (*returnSize) = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] <= numsSize)
            res[(*returnSize)++] = i+1;
    }
    return res;
}