#include <iostream>
using namespace std;

int n, top;
const int maxn = 20;
int a[maxn];
int vis[maxn];
int stc[maxn];

void init()
{
    int i;
    for (i = 0; i < n; ++i)
    {
        vis[i] = 1;
    }
}

void dfs(int ith)
{
    if (ith == n)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            printf("%d", stc[i]);
        }
        putchar('\n');
        return;
    }
    int i;
    for (i = 0; i < n; ++i)
    {
        if (vis[i] == 1)
        {
            vis[i] = 0;
            stc[top++] = a[i];
            dfs(ith + 1);
            top--;
            vis[i] = 1;
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    init();
    top = 0;
    dfs(0);

    return 0;
}