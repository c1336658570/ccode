/*
求 1+2+...+n ，要求不能使用乘除法、
for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//官方
//递归
int sumNums1(int n){
    n && (n += sumNums(n-1));
    return n;
}

//快速乘
//俄罗斯乘法
int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}

/*
1+2+⋯+n 等价于 n(n+1)/2，对于除以 2我们可以用右移操作符来模拟，
那么等式变成了 n(n+1)>>1，剩下不符合题目要求的部分即为 n(n+1)，
根据上文提及的快速乘，我们可以将两个数相乘用加法和位运算来模拟，
但是可以看到上面的 C++ 实现里我们还是需要循环语句，
有没有办法去掉这个循环语句呢？答案是有的，那就是自己手动展开，
因为题目数据范围 n 为 [1,10000]，所以 n 二进制展开最多不会超过 14 位，
我们手动展开 14 层代替循环即可，至此满足了题目的要求，具体实现可以参考下面给出的代码
*/

int sumNums2(int n) {
    int ans = 0, A = n, B = n + 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    (B & 1) && (ans += A);
    A <<= 1;
    B >>= 1;

    return ans >> 1;
}