/*
    第三章第一节
    xxx + yyy = zzz
*/
# include <stdio.h>

int a[10], book[10], total = 0;

int main(void)
{
    dfs(1);//首先站在第一个盒子面前

    printf("total = %d", total/2);

    return 0;
}

void dfs(int step) // step表示站在第几个盒子面前
{
    int i;
    if (step == 10) // 如果站在第10个盒子前，则表示前9个盒子已经放好扑克牌
    {
        //判断
        if (a[1]*100 + a[2]*10 + a[3]+a[4]*100 + a[5]*10 + a[6] == 
             a[7]*100 + a[8]*10 + a[9])
        {
            total++;
            printf("%d%d%d+%d%d%d = %d%d%d\n",
                    a[1], a[2], a[3], a[4], a[5], a[6],
                    a[7], a[8], a[9]);
        }

        return; //返回之前一步（最近一次调用dfs函数的地方）
    }

    //此时站在第step个盒子面前，应该放哪张牌呢？
    //按照1、2、3…n的顺序一一尝试
    for (i = 1; i <= 9; ++i)
    {
        //判断扑克牌i是否还在手上
        if(book[i] == 0) // book[i]等于0表示i号扑克牌在手上
        {
            //开始尝试使用扑克牌i
            a[step] = i; // 将i号扑克牌放入到第step个盒子中
            book[i] = 1; // 将book[i]设为1，表示i号扑克牌已经不在手上

            //第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前
            dfs(step + 1 ); // 通过递归
            book[i] = 0; // 这是非常重要的一步，将刚才扑克牌收回，然后才能进行下一次尝试
        }
    }
    return;

}