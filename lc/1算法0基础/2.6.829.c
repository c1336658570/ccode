/*
    连续整数求和
    定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

示例 1:
输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:

输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
示例 3:

输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
*/

//太强了，利用N=(x+1)+(x+2)+⋯+(x+k) = kx+k*(k+1)/2 ， 
//减去1累加到k的和后能被k整除，即得到了一组x,k； 再将公式转换为2N=k(2x+k+1) 
//可以得出k < 根号下2N，减少时间复杂度
int consecutiveNumbersSum(int n){
    int i, j = 0;
    for (i = 1; i < sqrt(2 * n); ++i)
    {
        if ((n - i * (i + 1) / 2) % i == 0)
            j++;
    }
    return j;
}

//同上
int consecutiveNumbersSum(int n){
    int ans=0;
    int max=0;
    int onetonplus=0;
    while(onetonplus<n){
        if((n-onetonplus)%(max+1)==0){ans++;}
        max++;
        onetonplus+=max;
    }
    return ans;
}

//同上， 我的习惯写法
int consecutiveNumbersSum(int n){
    int ans=0;
    int max=1;
    int onetonplus=0;
    while(onetonplus<n){
        if((n-onetonplus)%(max)==0){
            ans++;
        }
        onetonplus+=max;
        max++;
    }
    return ans;
}