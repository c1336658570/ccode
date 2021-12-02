/*
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x
示例 1：
输入：n = 16
输出：true
示例 2：
输入：n = 5
输出：false
示例 3：
输入：n = 1
输出：true
*/

# include <stdbool.h>

bool isPowerOfFour1(int n){
    if(n == 0)
        return false;
    int x = (int)(log2(n)/log2(4) + 1e-8);
    return fabs(n - pow(4, x)) < 1e-8;
}

//官方题解
bool isPowerOfFour2(int n){
    return n > 0 && ((n & (n - 1) ) == 0) && ((n & 0xaaaaaaaa) == 0);
}

bool isPowerOfFour3(int n){
    return n > 0 && ((n & (-n) ) == n) && (n % 3 == 1);
}