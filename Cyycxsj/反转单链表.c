/*
    单链表的逆置
*/
# include <stdio.h>

typedef struct node
{
    char name[20];
    int number;
    int score;
    struct node * next;    
}NODE, *LinkList;

void Reverse(LinkList head)
{
    NODE *p, *q;
    p = head->next;
    head->next = NULL;

    while(p)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}