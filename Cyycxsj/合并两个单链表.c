/*
    两个带头结点的学生链表，每个节点包含姓名，学号和成绩
    链表按学号升序排列，将它们合并为一个按升序排列的链表
*/

typedef struct node
{
    char name[20];
    int number;
    int score;
    struct node * next;    
}NODE, *LinkList;

void Merge(LinkList HA, LinkList HB)
{
    LinkList HC;
    NODE *p, *q, *r;

    p = HA->next;
    q = HB->next;
    r = HC =HA;
    while(p && q)
    {
        if (p->number <= q->number)
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
        r->next = p;
    if (q)
        r->next = q;
    free(HB);
}