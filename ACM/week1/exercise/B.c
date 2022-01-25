/*
Description
小Q同学正在和糖老师一起打(d)牌(p)。这个游戏需要52张牌，分为四种花色（H表示红心，S表示黑桃，
C表示梅花，D表示方块），每种花色有A,K,Q,J,10,9,8,7,6,5,4,3,2这么多张牌，其中A是最大的，
2是最小的。游戏的第一轮从小Q同学开始，他会先展示一张牌，然后轮到糖老师展示一张牌。
双方都展示完手牌之后进入结算环节，展示较大的牌的人会获得这一轮的胜利
（如果两个人展示的牌大小相同那么先展示牌的人获胜），并且得到较大的牌对
应的分值，分值就是牌上的数字，比如J是11，Q是12，K是13，A是1。结算后扔掉这一轮展示的牌，
然后从上一轮的获胜者开始下一轮，游戏进行到双方打完所有牌为止。为了简单起见，现在每个人都只有两张牌，
并且全过程中双方都能看到对方的手牌，也就是明牌打。你需要求出两个人都使用最优策略的情况下，
小Q同学的得分减去糖老师的得分的最大值。
Input
第一行是一个正整数 T (1≤T≤10000)，表示测试数据的组数。
每组测试数据包含两行，每行有两张牌，分别表示小Q和糖老师手上的牌。每张牌会按照 XY 的格式给出，其中 X 
是A,K,Q,J,T(表示10),9,8,7,6,5,4,3,2,1之一， Y 是花色(H,S,C,D之一)。保证任何一张牌至多出现一次。
Output
对于每组测试数据，输出一个整数，表示结果。
Sample Input
2
AH 2S
3C 4D
2H 5S
3C 4D
Sample Output
-3
1
*/

# include <stdio.h>

int main(void)
{
    int i, j, k, n, sum, flag1, flag2;
    char q[2][2], t[2][2];
    
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; ++i)
    {
        sum = 0;
        for (j = 0; j < 2; ++j)
        {
            scanf("%c %c", &q[j][0], &q[j][1]);
            getchar();
            if ( 48 <= q[j][0] && q[j][0] <= 57)
                q[j][0] -= 48;
            else if (q[j][0] == 'A')
                q[j][0] = q[j][0] - 'A'+1;
            else if (q[j][0] == 'K')
                q[j][0] -= 'K'-13;
            else if (q[j][0] == 'Q')
                q[j][0] -= 'Q'-12;
            else if (q[j][0] == 'J')
                q[j][0] -= 'J'-11;
            else
                q[j][0] -= 'T'-10;
            scanf("%c %c", &t[j][0], &t[j][1]);
            if ( 48 <= t[j][0] && t[j][0] <= 57)
                t[j][0] -= 48;
            else if (t[j][0] == 'A')
                t[j][0] -= 'A'-1;
            else if (t[j][0] == 'K')
                t[j][0] -= 'K'-13;
            else if (t[j][0] == 'Q')
                t[j][0] -= 'Q'-12;
            else if (t[j][0] == 'J')
                t[j][0] -= 'J'-11;
            else
                t[j][0] -= 'T'-10;
            getchar();
        }
        if (q[0][0] < q[1][0])
            flag1 = 1;
        else 
            flag1 = 0;
        if (t[0][0] < t[1][0])
            flag2 = 1;
        else 
            flag2 = 0;
        if (q[0][0] == 1)
            flag1 = 0;
        else if (q[1][0] == 1)
            flag1 = 1;
        if (t[0][0] == 1)
            flag2 = 0;
        else if (t[1][0] == 1)
            flag2 = 1;

        if ( ( q[0][0] >= t[0][0] && q[1][0] >= t[1][0]) && ( q[0][0] >= t[1][0] && q[1][0] >= t[0][0]))
        {
            sum = q[0][0] + q[1][0];
        }
        else if (( q[0][0] < t[0][0] && q[1][0] < t[1][0]) && ( q[0][0] < t[1][0] && q[1][0] < t[0][0]))
        {
            sum = -(t[0][0]+t[1][0]);
        }
        else 
        {
            sum = q[flag1][0] - t[flag2][0];
        }
        printf("%d\n", sum);
    }
} 
