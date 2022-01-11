/*
    将第一个元素输出第二个放最后面以此类推
    输出：
        6 1 5 9 4 7 2 8 3
*/

# include <stdio.h>

int main(void)
{
    int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
    int i;

    head = 1;
    tail = 10;

    while(head < tail)
    {
        printf("%d ",q[head]);
        head++;
        q[tail] = q[head];
        tail++;
        head++;
    }

    printf("\n");

    return 0;
}