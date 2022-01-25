//玩具谜题
/*
有n个玩具小人，围城一圈，已知方向和职业（朝内/朝外）。现在第1个玩具小人告诉小南一个包含m条指令的
谜题，其中第i条指令形如“左数/右数第si个玩具小人”。你需要输出依次数完这些指令后，玩具小人的职业

输入格式
第一行n，m，表示玩具小人数和指令数
n行输入如一个整数一个字符串，以逆时针顺序给出每个小人朝向和职业。0表示朝内，1表示朝外。保证不会出现
其他数。字符串长度不超过10且由小写字母组成，字符串不为空，并且字符串两两不同。整数和字符串空格隔开。
m行，其中第i行包含俩书ai，si，表示第i条指令，ai=0，表示向左数si个人，ai=1，表示向右数si个人

输入：
7 3
0 singer
0 reader
0 mengbier
1 thinker
1 archer
0 writer
1 mogician 
0 3
1 1
0 2
输出：
writer
*/

/*
顺时针
0 0
1 1
逆时针
1 0
0 1
*/

# include <stdio.h>

struct data
{
    int v;
    char str[11];
};

int main(void)
{
    int n, m, i, a, b, t = 0;
    scanf("%d %d", &n, &m);
    struct data q[n];

    for (i = 0; i < n; ++i)
    {
        scanf("%d %s", &q[i].v, q[i].str);
        getchar();
    }
    for (i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        if (a == 0)
        {
            if(q[t].v == 0)
                t = (n+t-b)%n;
            else
                t = (t+b)%n;
        }
        else
        {
            if(q[t].v == 0)
                t = (t+b)%n;
            else
                t = (n+t-b)%n;
        }
    }
    printf("%s\n", q[t].str);

    return 0;
}
