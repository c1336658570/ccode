// #include "string.h"
// #include "ctype.h"      
// #include "stdio.h"    
// #include "stdlib.h"   
// #include "sys/io.h"  
// #include "math.h"  
// #include "time.h"

// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// #define MAXSIZE 1000 /* 存储空间初始分配量 */

// typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
// typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

// /* 线性表的静态链表存储结构 */
// typedef struct 
// {
//     ElemType data;
//     int cur;  /* 游标(Cursor) ，为0时表示无指向 */
// } Component,StaticLinkList[MAXSIZE];

// Status visit(ElemType c);
// Status InitList(StaticLinkList space);
// int Malloc_SSL(StaticLinkList space);
// int ListLength(StaticLinkList L);
// Status ListInsert(StaticLinkList L, int i, ElemType e);
// Status ListDelete(StaticLinkList L, int i);
// void Free_SSL(StaticLinkList space, int k);
// Status ListTraverse(StaticLinkList L);

// int main()
// {
//     StaticLinkList L;
//     Status i;
//     i=InitList(L);
//     printf("初始化L后：L.length=%d\n",ListLength(L));

//     i=ListInsert(L,1,'F');
//     i=ListInsert(L,1,'E');
//     i=ListInsert(L,1,'D');
//     i=ListInsert(L,1,'B');
//     i=ListInsert(L,1,'A');

//     printf("\n在L的表头依次插入FEDBA后：\nL.data=");
//     ListTraverse(L); 

//     i=ListInsert(L,3,'C');
//     printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
//     ListTraverse(L); 

//     i=ListDelete(L,1);
//     printf("\n在L的删除“A”后：\nL.data=");
//     ListTraverse(L); 

//     printf("\n");

//     return 0;
// }

// Status visit(ElemType c)
// {
//     printf("%c ",c);
//     return OK;
// }

// /* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
// Status InitList(StaticLinkList space) 
// {
// 	int i;
// 	for (i=0; i<MAXSIZE-1; i++)  
// 		space[i].cur = i+1;
// 	space[MAXSIZE-1].cur = 0; /* 目前静态链表为空，最后一个元素的cur为0 */
// 	return OK;
// }


// /* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
// int Malloc_SSL(StaticLinkList space) 
// { 
// 	int i = space[0].cur;           		/* 当前数组第一个元素的cur存的值 */
// 	                                		/* 就是要返回的第一个备用空闲的下标 */
// 	if (space[0]. cur)         
// 	    space[0]. cur = space[i].cur;       /* 由于要拿出一个分量来使用了， */
// 	                                        /* 所以我们就得把它的下一个 */
// 	                                        /* 分量用来做备用 */
// 	return i;
// }

// /* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
// int ListLength(StaticLinkList L)
// {
//     int j=0;
//     int i=L[MAXSIZE-1].cur;
//     while(i)
//     {
//         i=L[i].cur;
//         j++;
//     }
//     return j;
// }

// /*  在L中第i个元素之前插入新的数据元素e   */
// Status ListInsert(StaticLinkList L, int i, ElemType e)   
// {  
//     int j, k, l;   
//     k = MAXSIZE - 1;   /* 注意k首先是最后一个元素的下标 */
//     if (i < 1 || i > ListLength(L) + 1)   
//         return ERROR;   
//     j = Malloc_SSL(L);   /* 获得空闲分量的下标 */
//     if (j)   
//     {   
// 		L[j].data = e;   /* 将数据赋值给此分量的data */
// 		for(l = 1; l <= i - 1; l++)   /* 找到第i个元素之前的位置 */
// 		   k = L[k].cur;           
// 		L[j].cur = L[k].cur;    /* 把第i个元素之前的cur赋值给新元素的cur */
// 		L[k].cur = j;           /* 把新元素的下标赋值给第i个元素之前元素的ur */
// 		return OK;   
//     }   
//     return ERROR;   
// }

// /*  删除在L中第i个数据元素   */
// Status ListDelete(StaticLinkList L, int i)   
// { 
//     int j, k;   
//     if (i < 1 || i > ListLength(L))   
//         return ERROR;   
//     k = MAXSIZE - 1;   
//     for (j = 1; j <= i - 1; j++)   
//         k = L[k].cur;   
//     j = L[k].cur;   
//     L[k].cur = L[j].cur;   
//     Free_SSL(L, j);   
//     return OK;   
// } 

// /*  将下标为k的空闲结点回收到备用链表 */
// void Free_SSL(StaticLinkList space, int k) 
// {  
//     space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
//     space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
// }

// Status ListTraverse(StaticLinkList L)
// {
//     int j=0;
//     int i=L[MAXSIZE-1].cur;
//     while(i)
//     {
//             visit(L[i].data);
//             i=L[i].cur;
//             j++;
//     }
//     return j;
//     printf("\n");
//     return OK;
// }

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAXSIZE 1000

typedef char ElemType;

typedef struct
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];

bool visit(ElemType c); //输出静态链表的一个元素
bool InitList(StaticLinkList space); //静态链表初始化，游标为下一个元素的下标，最后一个元素的下标为第一个有效元素的下标，所以为0
int Malloc_SSL(StaticLinkList space); //找到静态链表第一个空闲元素的下标
int ListLength(StaticLinkList L); //求静态链表的长度
bool ListInsert(StaticLinkList L, int i, ElemType e); //在静态链表第i个元素前插入e
bool ListDelete(StaticLinkList L, int i); //删除静态链表第i个元素
void Free_SSL(StaticLinkList L, int i); //将第i个元素的空间回收，当作下一次分配的第一个空闲元素
bool ListTraverse(StaticLinkList L); //输出静态链表的元素

int main()
{
    StaticLinkList L;
    bool i;
    i=InitList(L);
    printf("初始化L后：L.length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n在L的删除“A”后：\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}

//输出静态链表的一个元素
bool visit(ElemType c)
{
    printf("%c", c);
    return true;
}

//静态链表初始化，游标为下一个元素的下标，最后一个元素的下标为第一个有效元素的下标，所以为0
bool InitList(StaticLinkList space)
{
    int i;

    for (i = 0; i < MAXSIZE; ++i)
    {
        space[i].cur = i+1; //让每个元素指向下一个元素串成一串
    }
    space[MAXSIZE-1].cur = 0; //最后一个元素保存第一个有效元素下标，目前无有效元素，所以为0

    return true;
}

//找到静态链表第一个空闲元素的下标
int Malloc_SSL(StaticLinkList space)
{
    int i;

    i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur; //将space[0].cur下移一个(即将space[0].cur更新为下一个空闲元素的下标)，即space[0].cur = space[space[0].cur].cur
    }

    return i; //返回首空闲元素的下标
}

//求静态链表的长度
int ListLength(StaticLinkList L)
{
    int i = L[MAXSIZE-1].cur; //i为第一个有效元素的下标
    int j = 0;

    while (i) //当i不为0时，进入循环(因为最后一个有效元素的游标为0，判断是否到了最后一个元素)
    {
        j++; //j每次加1，计数
        i = L[i].cur; //更新i
    }

    return j;
}

//在静态链表第i个元素前插入e
bool ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    
    if (i < 1 || i > ListLength(L) + 1)
        return false; //可以在1 - ListLength(L)+1之间插入，在ListLength(L)+1插入，即在最后一个元素后面插入
    k = L[MAXSIZE-1].cur; //让k指向第一个元素
    j = Malloc_SSL(L); //找到静态链表第一个空闲元素的下标

    if (j) //j不为0进入
    {
        for (l = 1; l < i - 1; ++l)
        {
            k = L[k].cur; //循环i-2次，让k为第i-1个元素的下标
        }
        L[j].data = e; //让j的数据域保存e
        L[j].cur = L[k].cur; //j的游标为k的游标，即第i个与元素的下标
        L[k].cur = j; //更新k的游标为插入元素的下标
        return true;
    }

    return false;
}

//删除静态链表第i个元素
bool ListDelete(StaticLinkList L, int i)
{
    int j, k;

    if (i < 1 || i > ListLength(L))
    {
        return false;
    }
    k = MAXSIZE - 1;

    for (j = 1; j <= i - 1; ++j)
    {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j); //回收第下标为j的这个元素

    return true;
}

//将第i个元素的空间回收，当作下一次分配的第一个空闲元素
void Free_SSL(StaticLinkList L, int i)
{
    L[i].cur = L[0].cur;
    L[0].cur = i;
}

//输出静态链表的元素
bool ListTraverse(StaticLinkList L)
{
    int i;
    if ( !(ListLength(L)) )
        return false;

    i = L[MAXSIZE-1].cur;
    while (i)
    {
        visit(L[i].data);
        i = L[i].cur;
    }
    printf("\n");

    return true;
}