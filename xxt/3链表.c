/*
链表合并。题目描述

题目内容：已知单链表LA=(a1，a2，…，am)和LB=(b1，b2，…，bn)，
编写程序按以下规则将它们合并成一个单链表LC，要求新表 LC利用原表的存储空间。

          LC=(a1，b1，…，am，bm，bm+1，…，bn)，m<=n

或者

      LC=(a1，b1，…，bn，an，an+1，…，am)，m>n

输入格式：一行内输入单链表LA中的数据（若干个正整数，之间用空格隔开，并以-1结束）

        一行内输入单链表LB的数据（若干个正整数，之间用空格隔开，并以-1结束）

输出格式：一行内输出合并后单链表LC的数据结果，之间用两个分隔符 -- 隔开，结束标志-1不输出。


输入样例：1 3 5 7 -1

        2 4 6 -1

输出样例：--1--2--3--4--5--6--7

测试用例

用例1

分数： 20

错误提示： 

用例2

分数： 20

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
PNODE Merge(PNODE HA, PNODE HB);

int main(void)
{   
    PNODE HA = NULL, HB = NULL;
    InitList(&HA);
    CreateList(HA);
    InitList(&HB);
    CreateList(HB);
    TraverseList(Merge(HA, HB));


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
}

//合并链表
PNODE Merge(PNODE HA, PNODE HB)
{
    PNODE HC, p, q, r;

    p = HA->next;
    q = HB->next;
    r = HC = HA;

    while(p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    if (p)
    {
        r->next = p;
    }
    if (q)
    {
        r->next = q;
    }
    free(HB);
    return HC;
}