/*
1711. 大餐计数
大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。
你可以搭配 任意 两道餐品做一顿大餐。
给你一个整数数组 deliciousness ，其中 deliciousness[i] 
是第 i​​​​​​​​​​​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 10的9次方 + 7 取余。
注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

示例 1：
输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。

示例 2：
输入：deliciousness = [1,1,1,3,3,3,7]
输出：15
解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。

1 <= deliciousness.length <= 10的5次方
0 <= deliciousness[i] <= 2的20次方
*/

//时间复杂度O(nc)
int countPairs(int* deliciousness, int deliciousnessSize){
    int cnt[ (1<<21) + 1 ];
    int i, sum, other, t = 0;
    memset(cnt, 0, sizeof(cnt));

    for (i = 0; i < deliciousnessSize; ++i){
        for (sum = 1; sum <= (1<<21); sum <<= 1)
        {
            other = sum - deliciousness[i];
            if (other < 0)
                continue;
            t += cnt[other];
            t %= 1000000007;
        }
        cnt[deliciousness[i]]++;
    }

    return t;
}