# include <stdio.h>

int main(void)
{
    char a[20][21]; // 假设这里的地图大小不超过20*20
    int i, j, sum, map = 0, p, q, x, y, n, m;
    
    //读入n和m，n表示有多少行，m表示有多少列
    scanf("%d %d", &n, &m);

    //读入n行字符
    for (i = 0; i <= n-1; ++i)
    {
        scanf("%s", a[i]);
    }

    //用两重循环枚举地图上的每一点
    for (i = 0; i <= n-1; ++i)
    {
        for (j = 0; j <= m-1; ++j)
        {
            //首先判断这个点是不是平地， 是平地才可以被放置炸弹
            if (a[i][j] == '.')
            {
                sum = 0; // sum用来计数（可以消灭的敌人数）

                //向上统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                    {
                        sum++;
                    }
                    x--;
                }

                //向下统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                    {
                        sum++;
                    }
                    x++;
                }

                //向左统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                    {
                        sum++;
                    }
                    y--;
                }

                //向右统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                    {
                        sum++;
                    }
                    y++;
                }

                if (sum > map)
                {
                    map = sum;
                    p = i;
                    q = j;
                }
            }
        }
    }

    printf("将炸弹放置在（%d，%d），最多可以消灭%d个敌人\n", p, q, map);

    return 0;
}