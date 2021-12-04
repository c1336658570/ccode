/*
yyy 的学校要求早上 8 点前到达。学校到 yyy 的家一共有 s(s≤10000) 米，
而 yyy 可以以 v(v<10000)米每分钟的速度匀速走到学校。
此外在上学路上它还要额外花 10 分钟时间进行垃圾分类。
请问为了避免迟到 yyy 最晚什么时候出门？输出 HH:MM 的时间格式，不足两位时补零。由于路途遥远，
 yyy 可能不得不提前一天出发，不过不可能提前超过一天。

输入格式
两个正整数 s,v，意思已经在题目中给定。

输出格式
hh:mm 表示最晚离开家的时间（时:分，必须输出两位，不足两位前面补0）

输入输出样例
输入 #1复制
100 99
输出 #1复制
07:48
*/

# include <stdio.h>
# include <math.h>

int main(void)
{
    float s, v, t;
    int h, min;
    
    scanf("%f %f", &s, &v);
    
    t = s/v + 10;
    
    if (t > 8*60)
    {
        t -= 8*60;
        if (fabs(t - (int)t) )
            min = 60 - (int)t % 60 - 1;
        else
            min = 60 - (int)t % 60;
        if (min)
            h = 24 - (int)(t / 60) - 1;
        else
            h = 24 - (int)(t / 60);
    }
    else
    {
        if (fabs(t - (int)t) )
            min = 60 - (int)t % 60 - 1;
        else
            min = 60 - (int)t % 60;
        if (min)
            h = 8 - (int)(t / 60) - 1;
        else
            h = 8 - (int)(t / 60);
    }
    printf("%02d:%02d", h, min);
    
    return 0;
}