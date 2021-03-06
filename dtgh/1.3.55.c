/* 给出一个非负整数数组，你最初定位在数组的第一个位置。
数组中的每个元素代表你在那个位置可以跳跃的最大长度。
判断你是否能到达数组的最后一个位置。
数组A的长度不超过5000，每个元素的大小不超过5000

样例
样例 1：

输入：
A = [2,3,1,1,4]
输出：
true
解释：

0 -> 1 -> 4（这里的数字为下标）是一种合理的方案。

样例 2：

输入：
A = [3,2,1,0,4]
输出：
false
*/

# include <stdio.h>
# include <stdbool.h>

bool canJump(int* A, int n) {
    bool f[n]; int i, j; f[0] = true; 
    for (j = 1; j < n; ++j)
    {
        f[j] = false;
        for (i = 0; i < j; ++i)
        {
            if (f[i] && i+A[i] >= j)
            {
                f[j] = true;
                break;
            }
        }
    }
    return f[i-1];
}
