// #include "stdio.h"    
// #include "stdlib.h"   
// #include "sys/io.h"  
// #include "math.h"  
// #include "time.h"

// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0

// #define MAXSIZE 20 /* 存储空间初始分配量 */

// typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
// typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

// typedef struct
// {
// 	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
// 	int length;                                /* 线性表当前长度 */
// }SqList;

// Status visit(ElemType c);
// Status InitList(SqList *L);
// Status ListEmpty(SqList L);
// Status ClearList(SqList *L);
// int ListLength(SqList L);
// Status GetElem(SqList L,int i,ElemType *e);
// int LocateElem(SqList L,ElemType e);
// Status ListInsert(SqList *L,int i,ElemType e);
// Status ListDelete(SqList *L,int i,ElemType *e);
// Status ListTraverse(SqList L);
// void unionL(SqList *La,SqList Lb);


// int main(void)
// {
        
//     SqList L;
// 	SqList Lb;
    
//     ElemType e;
//     Status i;
//     int j,k;
//     i=InitList(&L);
//     printf("初始化L后：L.length=%d\n",L.length);
//     for(j=1;j<=5;j++)
//             i=ListInsert(&L,1,j);
//     printf("在L的表头依次插入1～5后：L.data=");
//     ListTraverse(L); 

//     printf("L.length=%d \n",L.length);
//     i=ListEmpty(L);
//     printf("L是否空：i=%d(1:是 0:否)\n",i);

//     i=ClearList(&L);
//     printf("清空L后：L.length=%d\n",L.length);
//     i=ListEmpty(L);
//     printf("L是否空：i=%d(1:是 0:否)\n",i);

//     for(j=1;j<=10;j++)
//             ListInsert(&L,j,j);
//     printf("在L的表尾依次插入1～10后：L.data=");
//     ListTraverse(L); 

//     printf("L.length=%d \n",L.length);

//     ListInsert(&L,1,0);
//     printf("在L的表头插入0后：L.data=");
//     ListTraverse(L); 
//     printf("L.length=%d \n",L.length);

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

// 	//构造一个有10个数的Lb
// 	i=InitList(&Lb);
//     for(j=6;j<=15;j++)
//             i=ListInsert(&Lb,1,j);

// 	unionL(&L,Lb);

// 	printf("依次输出合并了Lb的L的元素：");
//     ListTraverse(L); 

//     return 0;
// }

// Status visit(ElemType c)
// {
//     printf("%d ",c);
//     return OK;
// }


// /* 初始化顺序线性表 */
// Status InitList(SqList *L) 
// { 
//     L->length=0;
//     return OK;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
// Status ListEmpty(SqList L)
// { 
// 	if(L.length==0)
// 		return TRUE;
// 	else
// 		return FALSE;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
// Status ClearList(SqList *L)
// { 
//     L->length=0;
//     return OK;
// }

// /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
// int ListLength(SqList L)
// {
// 	return L.length;
// }

// /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
// /* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
// Status GetElem(SqList L,int i,ElemType *e)
// {
//     if(L.length==0 || i<1 || i>L.length)
//             return ERROR;
//     *e=L.data[i-1];

//     return OK;
// }

// /* 初始条件：顺序线性表L已存在 */
// /* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
// /* 若这样的数据元素不存在，则返回值为0 */
// int LocateElem(SqList L,ElemType e)
// {
//     int i;
//     if (L.length==0)
//             return 0;
//     for(i=0;i<L.length;i++)
//     {
//             if (L.data[i]==e)
//                     break;
//     }
//     if(i>=L.length)
//             return 0;

//     return i+1;
// }


// /* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
// /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
// Status ListInsert(SqList *L,int i,ElemType e)
// { 
// 	int k;
// 	if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
// 		return ERROR;
// 	if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
// 		return ERROR;

// 	if (i<=L->length)        /* 若插入数据位置不在表尾 */
// 	{
// 		for(k=L->length-1;k>=i-1;k--)  /* 将要插入位置之后的数据元素向后移动一位 */
// 			L->data[k+1]=L->data[k];
// 	}
// 	L->data[i-1]=e;          /* 将新元素插入 */
// 	L->length++;

// 	return OK;
// }

// /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
// /* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
// Status ListDelete(SqList *L,int i,ElemType *e) 
// { 
//     int k;
//     if (L->length==0)               /* 线性表为空 */
// 		return ERROR;
//     if (i<1 || i>L->length)         /* 删除位置不正确 */
//         return ERROR;
//     *e=L->data[i-1];
//     if (i<L->length)                /* 如果删除不是最后位置 */
//     {
//         for(k=i;k<L->length;k++)/* 将删除位置后继元素前移 */
// 			L->data[k-1]=L->data[k];
//     }
//     L->length--;
//     return OK;
// }

// /* 初始条件：顺序线性表L已存在 */
// /* 操作结果：依次对L的每个数据元素输出 */
// Status ListTraverse(SqList L)
// {
// 	int i;
//     for(i=0;i<L.length;i++)
//             visit(L.data[i]);
//     printf("\n");
//     return OK;
// }

// void unionL(SqList *La,SqList Lb)
// {
// 	int La_len,Lb_len,i;
// 	ElemType e;
// 	La_len=ListLength(*La);
// 	Lb_len=ListLength(Lb);
// 	for (i=1;i<=Lb_len;i++)
// 	{
// 		GetElem(Lb,i,&e);
// 		if (!LocateElem(*La,e))
// 			ListInsert(La,++La_len,e);
// 	}
// }


# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */
typedef struct
{
    ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
    int length; /* 线性表当前长度 */
}SqList;

bool visit(ElemType c);  // 输出一个元素
bool InitList(SqList *L); //初始化线性顺序表
bool ListEmpty(SqList L); /* 顺序线性表L已存在，若L为空表，则返回TRUE，否则返回FALSE */
bool ClearList(SqList *L); /* 顺序线性表L已存在，将L重置为空表 */
int ListLength(SqList L); /* 顺序线性表L已存在，返回L中数据元素个数 */
bool GetElem(SqList L,int i,ElemType *e); /* 用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
int LocateElem(SqList L,ElemType e); // 若线性表L中有元素e，返回那个元素是第几个，否则返回0
bool ListInsert(SqList *L,int i,ElemType e); //在线性表第i个元素前插入e
bool ListDelete(SqList *L,int i,ElemType *e); //删除线性表第i个元素，并将其保存到*e中
bool ListTraverse(SqList L); //将线性表输出
void unionL(SqList *La,SqList Lb); //将La和Lb中不重复的元素插入到La中（若La中没Lb中那个元素则插入，若La中已经有则不插入）

int main(void)
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    int i;
    int j,k;
    i=InitList(&L);

    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
    {
        i=ListInsert(&L,1,j);
    }
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
    {
            ListInsert(&L,j,j);
    }
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

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

	//构造一个有10个数的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}

bool visit(ElemType c)
{
    printf("%d", c); // 输出一个元素
    return true; // 返回真
}

bool InitList(SqList *L)
{
    L->length = 0; //线性表初始化
    return true;
}

bool ListEmpty(SqList L)
{
    if (L.length == 0) //判断线性表是否为空
        return true;
    else
        return false;
}

bool ClearList(SqList *L)
{
    L->length = 0; //清空线性表
    return true;
}

int ListLength(SqList L)
{
    return L.length; //返回线性表长度
}

bool GetElem(SqList L,int i,ElemType *e)
{
    if (i < 1 || i > L.length || L.length == 0)
        return false; //线性表元素从1-L->length，所以i必须>=1，且 i<=L.length，线性表为空也不能查找是否有e这个元素
    *e = L.data[i-1];
    return true;
}

int LocateElem(SqList L,ElemType e)
{
    if (L.length == 0)
        return 0;

    int i = 0;
    for (i = 0; i < L.length;i++)
    {
        if (L.data[i] == e) //没找到，即当i == L.length，循环终止
            break ;//若在线性表中找到e则返回他的下标，终止循环返回下标加1即第几个元素
    }
    if (i >= L.length)
        return 0;

    return i+1;
}

/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
bool ListInsert(SqList *L,int i,ElemType e)
{
    if (i < 1 || i > L->length+1 || L->length == MAXSIZE) //线性表满则无法插入
        return false; // 线性表从i-L->length,可以在L->length+1前插入，即在最后一个元素后插入
    if (i  <= L->length)
    {
        int k;
        for (k = L->length-1; k >= i-1; k--)
            L->data[k+1] = L->data[k];
    }

    L->data[i-1] = e;
    L->length++;

    return true;
}

//删除第i个元素，并将其存到*e中
bool ListDelete(SqList *L,int i,ElemType *e)
{
    if (i < 1 || i > L->length || L->length == 0)
        return false; //线性表从i-L->length，所以i必须>=1，且i<=L->length，线性表空无法删除

    *e=L->data[i-1];

    if (i < L->length)
    {
        int k;
        for (k = i-1; k < L->length-1; ++k)
        {
            L->data[k] = L->data[k+1];
        }
    }

    L->length--;
    return true;
}

//输出线性表
bool ListTraverse(SqList L)
{
    if (L.length == 0)
        return false;

    int i;
    for (i = 0; i < L.length; ++i)
    {
        visit(L.data[i]);
    }
    printf("\n");

    return true;
}

void unionL(SqList *La,SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = Listlength(Lb);

    for (i = 1; i <= Lb_len; ++i)
    {
        GetElem(Lb, i, &e);
        if (! LocateElem(*La, e))
            ListInsert(La, ++La_len, e);
    }
}