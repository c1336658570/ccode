/*
    输入：
        9
        2 3 5 8 9 10 18 26 32
        6
    输出：
        2 3 5 6 8 9 10 18 26 32
*/

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//创建一个结构体用来表示链表的节点类型
struct node
{
    int data;
    struct node * next;
};

int main(void)
{
    struct node *head, *p, *q, *t;
    int i, n, a;

    scanf("%d", &n);
    head = NULL; //头指针初始为空
    for (i = 1; i <= n; ++i) //循环读入n个数
    {
        scanf("%d", &a);
        //动态申请一个空间，存放一个节点，并让p指向该节点
        p = (struct node *)malloc(sizeof(struct node));
        if (p == NULL)
        {
            printf("动态内存分配失败！\n");
            exit(-1);
        }
        p->data = a; //将数据存到当前节点数据域中
        p->next = NULL; //让该节点指针域为空
        if ( head == NULL)
        {
            head = p; //若是第一个节点，则将头指针指向这个节点
        }
        else
        {
            q->next = p;//不是第一个节点，让上一个节点指向该节点
        }
        q = p;
    }
    //插入一个数a
    scanf("%d", &a); //读取待插入数
    t = head; //从链表头部开始便利
    while(t != NULL) //没到尾部时循环
    {
        if(t->next->data > a) // 若当前节点的下一个节点的值大于待插入数，则将待插入数方中间
        {
            p = (struct node *)malloc(sizeof(struct node));
            if (p == NULL)
            {
                printf("动态内存分配失败！\n");
                exit(-1);
            }
            p->data = a; 
            p->next = t->next; //新增节点的后继指针指向当前节点的后继指针所指向的节点
            t->next = p; //当前节点的后继指针指向新增节点
            break; //插入完毕退出
        }
        t = t->next; //继续下一个节点
    }

    //输出链表中的所有数
    t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    //释放内存
    t = head;
    while (t != NULL)
    {
        q = t->next;
        free(t);
        t = q;
    }

    return 0;
}