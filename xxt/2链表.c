/*
逆置单链表。题目描述

题目内容：一个单链表L=(a1 , a2 , … , an-1 , an)，
其逆单链表定义为L’=( an , an-1 , … , a2 , a1)，编写算法将单链表L逆置，
要求逆单链表仍占用原单链表的空间。


输入格式：一行内输入原单链表中的数据（若干个正整数，之间用空格隔开，并以-1结束）

输出格式：一行内输出建立的原单链表数据结果，之间用两个分隔符 -- 隔开，结束标志-1不输出。

        下一行内输出逆置后的单链表数据结果，之间用两个分隔符 -- 隔开。


输入样例：2 4 6 8 10 -1

输出样例：--2--4--6--8--10

        --10--8--6--4--2


测试用例

用例1

分数： 30

错误提示： 

题目运行时间限制： 500ms

题目运行内存限制： 32000kb

*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE;

void InitList(PNODE *head);
void CreateList(PNODE head);
void TraverseList(PNODE head);
void ReverseList(PNODE head);

int main(void)
{   
    PNODE head = NULL;
    InitList(&head);
    CreateList(head);
    TraverseList(head);
    ReverseList(head);
    TraverseList(head);

    return 0;
}

//初始化链表
void InitList(PNODE *head)
{
    *head = (PNODE)malloc(sizeof(NODE));
    if (*head == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    (*head)->next = NULL;
}

//尾插法创建链表
void CreateList(PNODE head)
{
    PNODE s, p;
    int val;

    p = head;
    while(scanf("%d", &val) && val != -1)
    {
        s = (PNODE)malloc(sizeof(NODE));
        if (s == NULL)
        {
            printf("动态内存分配失败！\n");
            exit(-1);
        }
        s->data = val;
        p->next = s;
        s->next = NULL;
        p = s;
    }
}

//输出链表
void TraverseList(PNODE head)
{
    PNODE p = head->next;

    while (p)
    {
        printf("--%d", p->data);
        p = p->next;
    }
    printf("\n");
}

//逆置链表
void ReverseList(PNODE head)
{
    PNODE p, q;

    p = head->next;
    head->next = NULL;
    while (p)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}