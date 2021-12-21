// #include "stdio.h"    
// #include "string.h"
// #include "ctype.h"      
// #include "stdlib.h"   
// #include "sys/io.h"  
// #include "math.h"  
// #include "time.h"

// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// #define MAXSIZE 20 /* 存储空间初始分配量 */

// typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
// typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

// typedef struct Node
// {
//     ElemType data;
//     struct Node *next;
// }Node;
// typedef struct Node *LinkList; /* 定义LinkList */

// Status visit(ElemType c);
// Status InitList(LinkList *L);
// Status ListEmpty(LinkList L);
// Status ClearList(LinkList *L);
// int ListLength(LinkList L);
// Status GetElem(LinkList L,int i,ElemType *e);
// int LocateElem(LinkList L,ElemType e);
// Status ListInsert(LinkList *L,int i,ElemType e);
// Status ListDelete(LinkList *L,int i,ElemType *e);
// Status ListTraverse(LinkList L);
// void CreateListHead(LinkList *L, int n);
// void CreateListTail(LinkList *L, int n);

// int main()
// {        
//     LinkList L;
//     ElemType e;
//     Status i;
//     int j,k;
//     i=InitList(&L);
//     printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
//     for(j=1;j<=5;j++)
//             i=ListInsert(&L,1,j);
//     printf("在L的表头依次插入1～5后：L.data=");
//     ListTraverse(L); 

//     printf("ListLength(L)=%d \n",ListLength(L));
//     i=ListEmpty(L);
//     printf("L是否空：i=%d(1:是 0:否)\n",i);

//     i=ClearList(&L);
//     printf("清空L后：ListLength(L)=%d\n",ListLength(L));
//     i=ListEmpty(L);
//     printf("L是否空：i=%d(1:是 0:否)\n",i);

//     for(j=1;j<=10;j++)
//             ListInsert(&L,j,j);
//     printf("在L的表尾依次插入1～10后：L.data=");
//     ListTraverse(L); 

//     printf("ListLength(L)=%d \n",ListLength(L));

//     ListInsert(&L,1,0);
//     printf("在L的表头插入0后：L.data=");
//     ListTraverse(L); 
//     printf("ListLength(L)=%d \n",ListLength(L));

//     GetElem(L,5,&e);
//     printf("第5个元素的值为：%d\n",e);
//     for(j=3;j<=4;j++)
//     {
//             k=LocateElem(L,j);
//             if(k)
//                     printf("第%d个元素的值为%d\n",k,j);
//             else
//                     printf("没有值为%d的元素\n",j);
//     }
    

//     k=ListLength(L); /* k为表长 */
//     for(j=k+1;j>=k;j--)
//     {
//             i=ListDelete(&L,j,&e); /* 删除第j个数据 */
//             if(i==ERROR)
//                     printf("删除第%d个数据失败\n",j);
//             else
//                     printf("删除第%d个的元素值为：%d\n",j,e);
//     }
//     printf("依次输出L的元素：");
//     ListTraverse(L); 

//     j=5;
//     ListDelete(&L,j,&e); /* 删除第5个数据 */
//     printf("删除第%d个的元素值为：%d\n",j,e);

//     printf("依次输出L的元素：");
//     ListTraverse(L); 

//     i=ClearList(&L);
//     printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
//     CreateListHead(&L,20);
//     printf("整体创建L的元素(头插法)：");
//     ListTraverse(L); 
    
//     i=ClearList(&L);
//     printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
//     CreateListTail(&L,20);
//     printf("整体创建L的元素(尾插法)：");
//     ListTraverse(L); 


//     return 0;
// }

// Status visit(ElemType c)
// {
//     printf("%d ",c);
//     return OK;
// }

// /* 初始化顺序线性表 */
// Status InitList(LinkList *L) 
// { 
//     *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
//     if(!(*L)) /* 存储分配失败 */
//             return ERROR;
//     (*L)->next=NULL; /* 指针域为空 */

//     return OK;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
// Status ListEmpty(LinkList L)
// { 
//     if(L->next)
//             return FALSE;
//     else
//             return TRUE;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
// Status ClearList(LinkList *L)
// { 
// 	LinkList p,q;
// 	p=(*L)->next;           /*  p指向第一个结点 */
// 	while(p)                /*  没到表尾 */
// 	{
// 		q=p->next;
// 		free(p);
// 		p=q;
// 	}
// 	(*L)->next=NULL;        /* 头结点指针域为空 */
// 	return OK;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
// int ListLength(LinkList L)
// {
//     int i=0;
//     LinkList p=L->next; /* p指向第一个结点 */
//     while(p)                        
//     {
//         i++;
//         p=p->next;
//     }
//     return i;
// }

// /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
// /* 操作结果：用e返回L中第i个数据元素的值 */
// Status GetElem(LinkList L,int i,ElemType *e)
// {
// 	int j;
// 	LinkList p;		/* 声明一结点p */
// 	p = L->next;		/* 让p指向链表L的第一个结点 */
// 	j = 1;		/*  j为计数器 */
// 	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
// 	{   
// 		p = p->next;  /* 让p指向下一个结点 */
// 		++j;
// 	}
// 	if ( !p || j>i ) 
// 		return ERROR;  /*  第i个元素不存在 */
// 	*e = p->data;   /*  取第i个元素的数据 */
// 	return OK;
// }

// /* 初始条件：顺序线性表L已存在 */
// /* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
// /* 若这样的数据元素不存在，则返回值为0 */
// int LocateElem(LinkList L,ElemType e)
// {
//     int i=0;
//     LinkList p=L->next;
//     while(p)
//     {
//         i++;
//         if(p->data==e) /* 找到这样的数据元素 */
//                 return i;
//         p=p->next;
//     }

//     return 0;
// }


// /* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
// /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
// Status ListInsert(LinkList *L,int i,ElemType e)
// { 
// 	int j;
// 	LinkList p,s;
// 	p = *L;   
// 	j = 1;
// 	while (p && j < i)     /* 寻找第i个结点 */
// 	{
// 		p = p->next;
// 		++j;
// 	} 
// 	if (!p || j > i) 
// 		return ERROR;   /* 第i个元素不存在 */
// 	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
// 	s->data = e;  
// 	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
// 	p->next = s;          /* 将s赋值给p的后继 */
// 	return OK;
// }

// /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
// /* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
// Status ListDelete(LinkList *L,int i,ElemType *e) 
// { 
// 	int j;
// 	LinkList p,q;
// 	p = *L;
// 	j = 1;
// 	while (p->next && j < i)	/* 遍历寻找第i个元素 */
// 	{
//         p = p->next;
//         ++j;
// 	}
// 	if (!(p->next) || j > i) 
// 	    return ERROR;           /* 第i个元素不存在 */
// 	q = p->next;
// 	p->next = q->next;			/* 将q的后继赋值给p的后继 */
// 	*e = q->data;               /* 将q结点中的数据给e */
// 	free(q);                    /* 让系统回收此结点，释放内存 */
// 	return OK;
// }

// /* 初始条件：顺序线性表L已存在 */
// /* 操作结果：依次对L的每个数据元素输出 */
// Status ListTraverse(LinkList L)
// {
//     LinkList p=L->next;
//     while(p)
//     {
//         visit(p->data);
//         p=p->next;
//     }
//     printf("\n");
//     return OK;
// }

// /*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
// void CreateListHead(LinkList *L, int n) 
// {
// 	LinkList p;
// 	int i;
// 	srand(time(0));                         /* 初始化随机数种子 */
// 	*L = (LinkList)malloc(sizeof(Node));
// 	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
// 	for (i=0; i<n; i++) 
// 	{
// 		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
// 		p->data = rand()%100+1;             /*  随机生成100以内的数字 */
// 		p->next = (*L)->next;    
// 		(*L)->next = p;						/*  插入到表头 */
// 	}
// }

// /*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
// void CreateListTail(LinkList *L, int n) 
// {
// 	LinkList p,r;
// 	int i;
// 	srand(time(0));                      /* 初始化随机数种子 */
// 	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
// 	r=*L;                                /* r为指向尾部的结点 */
// 	for (i=0; i<n; i++) 
// 	{
// 		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
// 		p->data = rand()%100+1;           /*  随机生成100以内的数字 */
// 		r->next=p;                        /* 将表尾终端结点的指针指向新结点 */
// 		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
// 	}
// 	r->next = NULL;                       /* 表示当前链表结束 */
// }

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

typedef int ElemType;
typedef struct
{
    ElemType data;
    struct Node *next;
}Node;

typedef Node * LinkList;

bool visit(ElemType c);
bool InitList(LinkList *L); //初始化线性顺序表
bool ListEmpty(LinkList L); //若L为空表，则返回true，否则返回false
bool ClearList(LinkList *L); //清空线性链表
int ListLength(LinkList L); //求链表长度
bool GetElem(LinkList L,int i,ElemType *e); //找到第i个节点，并将其数据域保存到*e中
int LocateElem(LinkList L,ElemType e); //找到数据域为e的这个节点，返回第一次出现的那个节点是第几个节点，否则返回0
bool ListInsert(LinkList *L,int i,ElemType e); //在第i个节点前插入一个节点，该节点的值为e
bool ListDelete(LinkList *L,int i,ElemType *e); //删除单链表第i个节点，并将其保存到*e中
bool ListTraverse(LinkList L); //输出单链表
void CreateListHead(LinkList *L, int n); //头差法创建单链表
void CreateListTail(LinkList *L, int n); //尾插法创建单链表

int main()
{        
    LinkList L;
    ElemType e;
    bool i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==false)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}

//输出一个基本类型的元素
bool visit(ElemType c)
{
    printf("%d", c);
    return true;
}

//初始化链表
bool InitList(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));
    if ( !(*L) )
    {
        printf("动态内存分配失败！\n");
        return false;
    }
    (*L)->next = NULL;

    return true;
}

//判断链表是否为空
bool ListEmpty(LinkList L)
{
    if (L->next == NULL)
        return true;
    
    return false;
}

//清空链表
bool ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }

    return true;
}

//求链表长度
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;

    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    
    return i;
}

//找到第i个节点，并将其数据域保存到*e中
bool GetElem(LinkList L,int i,ElemType *e)
{
    LinkList p = L->next;
    int j = 1;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i)
    {
        return false;
    }
    (*e) = p->data;

    return true;
}

//找到数据域为e的这个节点，返回第一次出现的那个节点是第几个节点，否则返回0
int LocateElem(LinkList L,ElemType e)
{
    int i = 1;
    LinkList p = L->next;

    while (p != NULL)
    {
        if (p->data == e)
            return i;
        i++;
        p = p->next;
    }
    return 0;
}

//在第i个节点前插入一个节点，该节点的值为e
bool ListInsert(LinkList *L,int i,ElemType e)
{
    int j = 1;
    LinkList p = *L;

    while (p && j < i)
    {
        p = p->next;
        i++;
    }
    if (p == NULL || j > i)
    {
        return false;
    }
    LinkList q = (LinkList)malloc(sizeof(Node));
    q->next = p->next;
    p->next = q;
    q->data = e;
    
    return true;
}

//删除单链表第i个节点，并将其保存到*e中
bool ListDelete(LinkList *L,int i,ElemType *e) 
{
    LinkList p = *L, q;
    int j = 1;

    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i)
        return false;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}

//输出单链表
bool ListTraverse(LinkList L)
{
    LinkList p = L->next;

    while (p != NULL)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");

    return true;
}

//头差法创建单链表
void CreateListHead(LinkList *L, int n)
{
    srand(time(NULL));
    LinkList p, q;
    int i = 0;
    *L = (LinkList)malloc(sizeof(Node));
    p = (*L);
    p->next = NULL;

    for (i = 0; i < n; ++i)
    {
        q = (LinkList)malloc(sizeof(Node));
        q->data = rand()%100 + 1;
        q->next = p->next;
        p->next = q;
    }
}

//尾插法创建单链表
void CreateListTail(LinkList *L, int n)
{
    srand(time(NULL));
    LinkList p, q;
    int i = 0;
    (*L) = (LinkList)malloc(sizeof(Node));
    p = *L;

    for (; i < n; ++i)
    {
        q = (LinkList)malloc(sizeof(Node));
        if (q == NULL)
        {
            printf("动态内存分配失败！\n");
            exit(-1);
        }
        q->data = rand()%100+1;
        p->next = q;
        p = q;
    }
}