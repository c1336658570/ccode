/*
    合并两个循环链表
    rearA和rearB分别指向两个链表的最后一个元素
*/

typedef struct NODE
{
    int data;
    struct NODE * next;
}NODE, *PNODE;

void hebing(PNODE rearA, PNODE rearB)
{
    PNODE p = rearA->next;
    rearA->next = rearB->next->next;
    PNODE q = rearB->next;
    rearB->next = p;
    free(q);
}