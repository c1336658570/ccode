/*
1137. 第 N 个泰波那契数
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/

int tribonacci(int n){
    int t[38], i;
    t[0] = 0;
    t[1] = 1;
    t[2] = 1;

    for (i = 3; i <= n; ++i)
        t[i] = t[i-1] + t[i-2] + t[i-3];
    return t[n];

}