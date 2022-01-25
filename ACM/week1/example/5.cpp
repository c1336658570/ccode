# include <iostream>
# include <cstring>

using namespace std;
const int N = 1e5 + 10;
int n, m;
struct data
{
    int v;
    char str[15];
}q[N];

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int t;
        char s[15];
        cin >> t >> s;
        q[i].v = t;
        strcpy(q[i].str, s);
    }
    int cur = 0;
    while (m--)
    {
        int a, s;
        cin >> a >> s;
        if (a != q[cur].v)
            cur = (cur + s) % n;
        else
            cur = (cur - s + n) % n;
    }
    cout << q[cur].str << endl;

    return 0;
}