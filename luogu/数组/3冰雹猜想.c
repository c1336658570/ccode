/*
给出一个正整数 n(n≤100)n(n\le 100)n(n≤100)，然后对这个数字一直进行下面的操作：
如果这个数字是奇数，那么将其乘 3 再加 1，否则除以 2。经过若干次循环后，最终都会回到 1。
经过验证很大的数字（7×10117\times10^{11}7×1011）都可以按照这样的方式比变成 1，
所以被称为“冰雹猜想”。例如当 nnn 是 20，变化的过程是 [20, 10, 5, 16, 8, 4, 2, 1]。

根据给定的数字，验证这个猜想，并从最后的 1 开始，倒序输出整个变化序列。
输入格式

无
输出格式

无

输入：
20
输出：
1 2 4 8 16 5 10 20
*/

//用栈实现
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void InitStack(PSTACK pS);
void PushStack(PSTACK pS, int val);
void TraverseStack(PSTACK pS);

# include <stdio.h>

int main(void)
{
    STACK s;
    int n, val;

    scanf("%d", &n);
    InitStack(&s);

    PushStack(&s, n);
    val = n;
    while(val != 1)
    {
        if (val % 2)
        {
            val = val * 3 + 1;
            PushStack(&s, val);
        }
        else
        {
            val /= 2;
            PushStack(&s, val);
        }
    }
    TraverseStack(&s);

    return 0;
}

void InitStack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (pS->pTop == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    pS->pBottom = pS->pTop;
    pS->pTop->pNext = NULL;
}

void PushStack(PSTACK pS, int val)
{
    PNODE p = (PNODE)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    p->data = val;
    p->pNext = pS->pTop;
    pS->pTop = p;
}

void TraverseStack(PSTACK pS)
{
    PNODE p = pS->pTop;

    while(p != pS->pBottom)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
}

/*
# include <stdio.h>

int main(void)
{
    int n, val, i, a[1100];

    scanf("%d", &n);

    i = 0;
    a[i++] = n;
    val = n;
    while(val != 1)
    {
        if (val % 2)
        {
            val = val * 3 + 1;
            a[i++] = val;
        }
        else
        {
            val /= 2;
            a[i++] = val;
        }
    }

    for (i -= 1; i >= 0; --i)
    {
        printf("%d ", a[i]);
    }

}
*/