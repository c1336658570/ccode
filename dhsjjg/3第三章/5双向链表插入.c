/*
    双向链表插入一个元素
    双向链表删除一个元素
*/

typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
}NODE, *PNODE;

void Insert(PNODE p)
{
    PNODE s = (PNODE)malloc(sizeof(NODE));
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
}

void Delete(PNODE p)
{
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}