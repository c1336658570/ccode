/*
    迷走干
    小哼先拿出第一张牌放桌上，然后小哈再拿出第一张牌放桌上，以此类推
    若桌上有相同的，则把相同的牌和牌中间的所有牌拿走

    小哼：2 4 1 2 5 6
    小哈：3 1 3 5 6 4
    小哼小哈手中的牌仅有1-9

    输入：
        2 4 1 2 5 6
        3 1 3 5 6 4
    输出：
        小哼win
        小哼手里的牌是 5 6 2 3 1 4 6 5
        桌上的牌是 2 1 3 4

*/

# include <stdio.h>

struct queue
{
    int data[1000];
    int head;
    int tail;
};

//桌上最多只有9种不同牌面
struct stack
{
    int data[10];
    int top;
};

int main(void)
{
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i, t;

    //初始化队列
    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    //初始化栈
    s.top = 0;

    //初始化用来标记的数组，用来标记哪些牌已经在桌上
    for(i = 1; i <= 9; ++i)
    {
        book[i] = 0;
    }

    //依次向队列插入6个数
    //小哼手上的6张牌
    for (i = 1; i <= 6; ++i)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    //小哈手上的6张牌
    for (i = 1; i <= 6; ++i)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }

    while (q1.head < q1.tail && q2.head < q2.tail)//队列不为空执行循环
    {
        t = q1.data[q1.head];//小哼出一张牌

        //判断小哼当前打出的牌是否能赢牌
        if(book[t] == 0) // 表明桌上没有牌面为t的牌
        {
            //小哼此轮没有赢牌
            q1.head++; // 小哼已经打出一张牌，要打出的牌出队
            s.top++;
            s.data[s.top] = t; // 再把打出的牌放到桌上，即入栈
            book[t] = 1; // 标记桌上现在已经有牌面为t的牌
        }
        else
        {
            //小哼此轮可以赢牌
            q1.head++; //小哼已经打出一张牌，将打出的牌出队
            q1.data[q1.tail] = t; //将打出的牌放到手中牌的末尾
            q1.tail++;
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0; // 取消标记
                q1.data[q1.tail] = s.data[s.top];//依次放入队尾
                q1.tail++;
                s.top--; //栈中少一张牌，栈减1
            }
        }

        t = q2.data[q2.head]; // 小哈出一张牌
        if(book[t] == 0) // 桌面上无t这张牌
        {
            //小哈此轮没有赢牌
            q2.head++;//小哈已经打出一张牌，将打出的牌出队
            s.top++;
            s.data[s.top] = t;// 再把打出的牌放到桌上，即入栈
            book[t] = 1; // 标记桌上现在已经有牌面为t的牌
        }
        else
        {
            //小哈此轮可以赢牌
            q2.head++;//小哈已经打出一张牌，将打出的牌出队
            q2.data[q2.tail] = t;//将打出的牌放到手中牌的末尾
            q2.tail++;

            while (t != s.data[s.top])
            {
                book[s.data[s.top]] = 0; // 取消标记
                q2.data[q2.tail] = s.data[s.top];//依次放入队尾
                q2.tail++;
                s.top--;//栈中少一张牌，栈减1
            }
        }
    }
    if (q2.head == q2.tail)
    {
        printf("小哼win\n");
        printf("小哼手里的牌是");
        for (i = q1.head; i < q1.tail; ++i)
        {
            printf(" %d", q1.data[i]);
        }
        if (s.top > 0) //如果桌上有牌则依次输出桌上的牌
        {
            printf("\n桌上的牌是");
            for (i = 1; i <= s.top; i++)
            {
                printf(" %d", s.data[i]);
            }
        }
        else
        {
            printf("\n桌上已经没有牌了");
        }
    }
    else
    {
        printf("小哈win\n");
        printf("小哈手里的牌是");
        for (i = q2.head; i < q2.tail; ++i)
        {
            printf(" %d", q2.data[i]);
        }
        if (s.top > 0)//如果桌上有牌则依次输出桌上的牌
        {
            for (i = 1; i <= s.top; ++i)
            {
                printf(" %d", s.data[i]);
            }
        }
        else
        {
            printf("\n桌上已经没有牌了");
        }

    }
    printf("\n");
    getchar();

    return 0;
}