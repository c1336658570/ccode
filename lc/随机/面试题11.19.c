/*
    消失的两个数字

    给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
    以任意顺序返回这两个数字均可。

    示例 1:
    输入: [1]
    输出: [2,3]
    示例 2:

    输入: [2,3]
    输出: [1,4]
*/

int *missingTwo(int *nums,int numsSize,int *returnSize)
{
    (*returnSize) = 2;
    int *res = (int *)malloc(sizeof(int) *2);
    int book[numsSize+3];
    memset(book, 0, sizeof(int) * (numsSize+3));
    int i, j = 0;

    for (i = 0; i < numsSize; ++i)
    {
        book[nums[i]]++;
    }

    for (i = 1; i < numsSize+3; ++i)
    {
        if (book[i] == 0)
        {
            res[j] = i;
            j++;
        }
        if (j == 2)
            break;
    }
    return res;
}

int *missingTwo(int *nums,int numsSize,int *returnSize)
{
    int sum = 0;
    for (int i = 0;i < numsSize;i++)
    {
        sum += nums[i];
    }
    int original = numsSize + 2;
    int sumofTwo = (1 + original) * original / 2 - sum;
    int average = (sumofTwo) / 2;
    sum = 0;
    for (int i = 0;i < numsSize;i++)
    {
        if (nums[i] <= average)
        {
            sum += nums[i];
        }
    }
    int *result = (int *)malloc(sizeof(int) * 2);
    result[0] = (1 + average) * (average) / 2  - sum;
    result[1] = sumofTwo - result[0];
    *returnSize = 2;
    return result;
}