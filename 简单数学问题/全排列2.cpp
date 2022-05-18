
//全排列问题衍生：1-n个数取n个数字全排列
#include <iostream>
#include <string.h>
using namespace std;
int dfs(int step, int n, int m, int *a, int *vis) //为什么是int类型的函数
{
    if (step == m + 1) //如果到达目的地，输出排列
    {
        for (int j = 1; j <= m; j++)
        {
            cout << "  " << a[j];
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && a[step - 1] < i) //向前一步走的通：没被用过
            {
                a[step] = i; //保存当前结果
                vis[i] = 1;  //这个格子标记为用过
                dfs(step + 1, n, m, a, vis);
                vis[i] = 0; //回溯
            }
        }
    }
    return 0;
}
int main()
{
    int a[10], vis[10]; // vis数组记录是否用过，用过为1，没用为0，a数组记录每次的具体情况
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    dfs(1, n, m, a, vis);
}