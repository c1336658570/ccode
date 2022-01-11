/*
    请输入学生的姓名和学号：
    李四 2
    王五 3
    某某 0

    **********学生信息如下**********
    姓名：李四
    学号：2

    姓名：王五
    学号：3

    请输入待添加学生的姓名和学号：
    张三 1

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：李四
    学号：2

    姓名：王五
    学号：3


    **********删除第2个学生**********

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：王五
    学号：3
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Node
{
    char name[20]; // 姓名
    int number; // 学号
    int score; // 成绩
    struct Node *next; // next的类型是指向本结构体类型的指针类型
}NODE, *LinkList;

LinkList CreatByrear();
void OutPut(LinkList head);
LinkList Insert(LinkList head, int i);
LinkList Delete(LinkList head, int pos);

int main(void)
{
    LinkList ha = NULL;
    ha = CreatByrear(ha);
    OutPut(ha);
    ha = Insert(ha, 1);
    OutPut(ha);
    ha = Delete(ha, 2);
    OutPut(ha);

    return 0;
}

LinkList CreatByrear()
{
    LinkList head = NULL;
    NODE *r, *s;
    char name[20];
    int number;

    printf("请输入学生的姓名和学号：\n");
    while(1)
    {
        scanf("%s", name);
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        }
        s = (NODE *)malloc(sizeof(NODE));
        if (s == NULL)
        {
            printf("动态内存分配失败！\n");
            exit(-1);
        }
        strcpy(s->name, name);
        s->number = number;
        s->next = NULL;
        if (head == NULL)
        {
            head = s;
            r = head;
        }
        else
        {
            r->next = s;
            r = s;
        }
    }
    return head;

}

void OutPut(LinkList head)
{
    NODE *p;
    p = head;

    printf("\n**********学生信息如下**********\n");
    while(p)
    {
        printf("姓名：%s\n", p->name);
        printf("学号：%d\n\n", p->number);
        p = p->next;
    }
}

LinkList Insert(LinkList head, int i)
{
    NODE *p, *s;
    int j;
    printf("请输入待添加学生的姓名和学号：\n");
    s = (NODE *)malloc(sizeof(NODE));
    if (s == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    scanf("%s", s->name);
    scanf("%d", &s->number);
    if (i == 1)
    {
        s->next = head;
        head = s;
    }
    else
    {
        p = head;
        j = 1;

        while(p && j < i-1)
        {
            j++;
            p  = p->next;
        }

        if (!p || j>i-1)
        {
        }
        else
        {
        s->next = p->next;
        p->next = s;
        }
    }
    return head;

}

LinkList Delete(LinkList head, int pos)
{
    NODE *p = head, *q;

    printf("\n**********删除第%d个学生**********\n", pos);
    if (head == NULL)
    {
        printf("the pos is ERROR!");
        return;
    }

    if (pos == 1)
    {
        q = head;
        head = head->next;
        free(q);
    }
    else
    {
        int j = 1;

        while(p && j < pos - 1)
        {
            p = p->next;
            j++;
        }
        if (p == NULL || p->next == NULL || j > pos-1)
        {
            printf("the pos is ERROR!");
        }
        else
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }

    return head;
}