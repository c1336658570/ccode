/*
    请输入学生的姓名和学号：
    张三 1
    李四 2
    王五 3
    马六 4
    某某 0

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：李四
    学号：2

    姓名：王五
    学号：3

    姓名：马六
    学号：4

    请输入学生的姓名和学号：
    张三 1
    李四 2
    王五 3
    马六 4
    某某 0

    **********学生信息如下**********
    姓名：马六
    学号：4

    姓名：王五
    学号：3

    姓名：李四
    学号：2

    姓名：张三
    学号：1
*/

/*
    请输入学生的姓名和学号：
    张三 1
    李四 2
    马六 4
    某某 0

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：李四
    学号：2

    姓名：马六
    学号：4

    请输入待添加学生的姓名和学号：
    王五 3

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：李四
    学号：2

    姓名：王五
    学号：3

    姓名：马六
    学号：4
*/

/*
    请输入学生的姓名和学号：
    张三 1
    李四 2
    王五 3
    马六 4
    某某 0

    **********删除第3个学生**********

    **********学生信息如下**********
    姓名：张三
    学号：1

    姓名：李四
    学号：2

    姓名：马六
    学号：4
*/

/*
    请输入学生的姓名和学号：
    张三 1
    李四 2
    王五 3
    马六 4
    某某 0

    **********查找的信息如下**********
    姓名： 李四
    学号： 2
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <malloc.h>

typedef struct Node
{
    char name[20]; // 姓名
    int number; // 学号
    struct Node *next; // next的类型是指向本结构体类型的指针类型
}NODE, *LinkList;

LinkList IninList();
void CreatByrear(LinkList head);
void CreatByhead(LinkList head);
void OutPut(LinkList head);
void Insert(LinkList head, int i);
void InsertHead(LinkList head);
void InsertRear(LinkList head);
void Delete(LinkList head, int pos);
NODE *Search(LinkList head, char name[]);

int main(void)
{
/*
    LinkList ha, hb;
    ha = IninList();
    CreatByrear(ha);
    OutPut(ha);
    hb = IninList();
    CreatByhead(hb);
    OutPut(hb);
*/

/*    
    LinkList ha;
    ha = IninList();
    CreatByrear(ha);
    OutPut(ha);
    Insert(ha, 3);
    OutPut(ha);
*/

/*
    LinkList ha;
    ha = IninList();
    CreatByrear(ha);
    Delete(ha, 3);
    OutPut(ha);
*/

    LinkList ha;
    NODE *p;
    ha = IninList();
    CreatByrear(ha);
    p = Search(ha, "李四");
    printf("\n**********查找的信息如下**********\n");
    printf("姓名： %s\n", p->name);
    printf("学号： %d\n", p->number);

    return 0;
}

LinkList IninList()
{
    LinkList head;
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    return head;
}

//尾插法
void CreatByrear(LinkList head)
{
    NODE *r, *s;
    char name[20];
    int number;

    r = head;
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
        r->next = s;
        r = s;
    }
    r->next = NULL;

    return;

}

//头插法
void CreatByhead(LinkList head)
{
    NODE *s;
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
        s->next = head->next;
        head->next = s;
    }

    return;
}

void OutPut(LinkList head)
{
    NODE *p;
    p = head->next;

    printf("\n**********学生信息如下**********\n");
    while(p)
    {
        printf("姓名：%s\n", p->name);
        printf("学号：%d\n\n", p->number);
        p = p->next;
    }
}

void Insert(LinkList head, int i)
{
    NODE *p, *s;
    int j;

    p = head;
    j = 0;

    while(p && j < i-1)
    {
        j++;
        p  = p->next;
    }

    if (!p || j > i-1)
        return;

    printf("请输入待添加学生的姓名和学号：\n");
    s = (NODE *)malloc(sizeof(NODE));
    if (s == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    scanf("%s", s->name);
    scanf("%d", &s->number);
    s->next = p->next;
    p->next = s;

}

void InsertHead(LinkList head)
{
    NODE *s;
    printf("请输入待添加学生的姓名和学号：\n");
    s = (NODE *)malloc(sizeof(NODE));
    scanf("%s", s->name);
    scanf("%d", &s->number);
    s->next = head->next;
    head->next = s;
}

void InsertRear(LinkList head)
{
    NODE *s, *p = head;

    while(p && p->next)
        p = p->next;
    if (p)
    {
        printf("请输入带添加学生的姓名和学号：\n");
        s = (NODE *)malloc(sizeof(NODE));
        scanf("%s", s->name);
        scanf("%d", &s->number);
        p->next = s;
        s->next = NULL;
    }
}

void Delete(LinkList head, int pos)
{
    NODE *p = head, *q;
    int j = 0;

    printf("\n**********删除第%d个学生**********\n", pos);
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

NODE *Search(LinkList head, char name[])
{
    NODE *p = head->next;
    while(p)
    {
        if (strcmp(p->name, name) != 0)
        {
            p = p->next;
        }
        else
        {
            break;
        }
    }
    if (p == NULL)
    {
        printf("没有找到值为%s的结点！", name);
    }
    return p;
}