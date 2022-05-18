
//全排列问题衍生：1-n个数取n个数字全排列
#include <iostream>
using namespace std;
int a[10], vis[10]; // vis数组记录是否用过，用过为1，没用为0，a数组记录每次的具体情况
int n, m;
int dfs(int step) //为什么是int类型的函数
{
    if (step == m + 1) //如果到达目的地，输出排列
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0) //向前一步走的通：没被用过
            {
                a[step] = i; //保存当前结果
                vis[i] = 1;  //这个格子标记为用过
                dfs(step + 1);
                vis[i] = 0; //回溯
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    dfs(1);
}
