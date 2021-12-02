/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

示例 1：

输入：n = 1
输出：true
解释：20 = 1
示例 2：

输入：n = 16
输出：true
解释：24 = 16
示例 3：

输入：n = 3
输出：false
示例 4：

输入：n = 4
输出：true
示例 5：

输入：n = 5
输出：false
*/
# include <stdbool.h>

//1
bool isPowerOfTwo1(int n){
    if (n == 0)
    {
        return false;
    }
    int x = (int)(log2(n) + 1e-8);
    return fabs( n - pow(2, x) ) < 1e-8;
}

//官方题解1
bool isPowerOfTwo2(int n){
    return n > 0 && ( (n & (n-1)) == 0 );
}


bool isPowerOfTwo3(int n){
    return n > 0 && ( (n & (-n)) == n);
}

//官方题解2
/*
除了使用二进制表示判断之外，还有一种较为取巧的做法。
在题目给定的 32 位有符号整数的范围内，最大的 2 的幂为 2^{30} = 10737418242 
我们只需要判断 n是否是 2^{30}的约数即可。
*/

const int BIG = 1<<30;
bool isPowerOfTwo3(int n){
    return n > 0 && BIG % n == 0;
}