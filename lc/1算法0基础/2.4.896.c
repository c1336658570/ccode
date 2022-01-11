/*
如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。
 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。
示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false
*/
# include <stdbool.h>

bool isMonotonic1(int* nums, int numsSize){
    int i, j;
    for (i = 0; i < numsSize-1; ++i)
    {
        if (nums[i] < nums[i+1])
            break;
    }
    for (j = 0; j < numsSize-1; ++j)
    {
        if (nums[j] > nums[j+1])
            break;
    }
    if (i == numsSize-1 || j == numsSize-1)
        return true;
    return false;
}

//答案，一次便利
bool isMonotonic2(int* nums, int numsSize) {
    bool inc = true, dec = true;
    int n = numsSize;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            inc = false;
        }
        if (nums[i] < nums[i + 1]) {
            dec = false;
        }
    }
    return inc || dec;
}