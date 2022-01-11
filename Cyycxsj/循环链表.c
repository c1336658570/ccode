/*
    循环链表创建
*/

# include <stdio.h>

typedef struct node
{
    char name[20];
    int number;
    int score;
    struct node * next;    
}NODE, *LinkList;

void CreateByRear(LinkList head)
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
        strcpy(s->name, name);
        s->number = number;
        r->next = s;
        r = s;
    }
    r->next = head;
}