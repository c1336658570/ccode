/*
正向建立单链表。题目描述

题目内容：输入若干个正整数（输入-1为结束标志），要求按输入数据的逆序建立单链表并输出。


输入格式：一行内输入若干个正整数，之间用空格隔开，并以-1结束。

输出格式：一行内输出建立的单链表数据结果，之间用两个分隔符 -- 隔开，结束标志-1不输出。


输入样例：2 4 6 8 10 -1

输出样例：--2--4--6--8--10

测试用例

用例1

分数： 25

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

int main(void)
{   
    PNODE head = NULL;
    InitList(&head);
    CreateList(head);
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
}
