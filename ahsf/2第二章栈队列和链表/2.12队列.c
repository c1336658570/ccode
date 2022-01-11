/*
    输入：
        6 3 1 7 5 8 9 2 4
    输出：
        6 1 5 9 4 7 2 8 3 
*/
# include <stdio.h>

typedef struct queue
{
    int data[100];
    int head;
    int tail;
}QUEUE;

int main(void)
{
    QUEUE q;
    int i;

    q.head = 1;
    q.tail = 1;

    for (i = 1; i <= 9; ++i)
    {
        //依次向队列插入9个数
        scanf("%d", &q.data[i]);
        q.tail++;
    }

    while(q.head < q.tail)
    {
        printf("%d ", q.data[q.head]);
        q.head++;

        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }
    printf("\n");

    return 0;
}