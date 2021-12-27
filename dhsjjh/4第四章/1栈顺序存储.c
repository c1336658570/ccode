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

// typedef int Status; 
// typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

// /* 顺序栈结构 */
// typedef struct
// {
//         SElemType data[MAXSIZE];
//         int top; /* 用于栈顶指针 */
// }SqStack;

// Status visit(SElemType c);
// Status InitStack(SqStack *S);
// Status ClearStack(SqStack *S);
// Status StackEmpty(SqStack S);
// int StackLength(SqStack S);
// Status GetTop(SqStack S,SElemType *e);
// Status Push(SqStack *S,SElemType e);
// Status Pop(SqStack *S,SElemType *e);
// Status StackTraverse(SqStack S);

// int main()
// {
//         int j;
//         SqStack s;
//         int e;
//         if(InitStack(&s)==OK)
//                 for(j=1;j<=10;j++)
//                         Push(&s,j);
//         printf("栈中元素依次为：");
//         StackTraverse(s);
//         Pop(&s,&e);
//         printf("弹出的栈顶元素 e=%d\n",e);
//         printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
//         GetTop(s,&e);
//         printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
//         ClearStack(&s);
//         printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        
//         return 0;
// }

// Status visit(SElemType c)
// {
//         printf("%d ",c);
//         return OK;
// }

// /*  构造一个空栈S */
// Status InitStack(SqStack *S)
// { 
//         /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
//         S->top=-1;
//         return OK;
// }

// /* 把S置为空栈 */
// Status ClearStack(SqStack *S)
// { 
//         S->top=-1;
//         return OK;
// }

// /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
// Status StackEmpty(SqStack S)
// { 
//         if (S.top==-1)
//                 return TRUE;
//         else
//                 return FALSE;
// }

// /* 返回S的元素个数，即栈的长度 */
// int StackLength(SqStack S)
// { 
//         return S.top+1;
// }

// /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
// Status GetTop(SqStack S,SElemType *e)
// {
//         if (S.top==-1)
//                 return ERROR;
//         else
//                 *e=S.data[S.top];
//         return OK;
// }

// /* 插入元素e为新的栈顶元素 */
// Status Push(SqStack *S,SElemType e)
// {
//         if(S->top == MAXSIZE -1) /* 栈满 */
//         {
//                 return ERROR;
//         }
//         S->top++;				/* 栈顶指针增加一 */
//         S->data[S->top]=e;  /* 将新插入元素赋值给栈顶空间 */
//         return OK;
// }

// /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
// Status Pop(SqStack *S,SElemType *e)
// {                            
//         if(S->top==-1)
//                 return ERROR;
//         *e=S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
//         S->top--;				/* 栈顶指针减一 */
//         return OK;
// }

// /* 从栈底到栈顶依次对栈中每个元素显示 */
// Status StackTraverse(SqStack S)
// {
//         int i;
//         i=0;
//         while(i<=S.top)
//         {
//                 visit(S.data[i++]);
//         }
//         printf("\n");
//         return OK;
// }

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAXSIZE 20

typedef int SElemType;
typedef struct
{
        SElemType data[MAXSIZE];
        int top;
}SqStack;

bool visit(SElemType c); //输出一个元素
bool InitStack(SqStack *S); //初始化栈
bool ClearStack(SqStack *S); //清空栈
bool StackEmpty(SqStack S); //判断栈是否为空
int StackLength(SqStack S); //求栈的长度
bool GetTop(SqStack S,SElemType *e); //获取栈顶元素
bool Push(SqStack *S,SElemType e); //压栈
bool Pop(SqStack *S,SElemType *e); //弹出栈
bool StackTraverse(SqStack S); //从栈底元素依次输出栈

int main()
{
        int j;
        SqStack s;
        int e;
        if(InitStack(&s) == true)
                for(j = 1; j <= 10; j++)
                        Push(&s, j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s, &e);
        printf("弹出的栈顶元素 e=%d\n", e);
        printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
        GetTop(s, &e);
        printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
        
        return 0;
}

//输出一个元素
bool visit(SElemType c)
{
        printf("%d", c);

        return true;
}

//初始化栈
bool InitStack(SqStack *S)
{
        S->top = -1;

        return true;
}

//清空栈
bool ClearStack(SqStack *S)
{
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top = -1;

        return true;
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
        if (S.top == -1)
                return true;
        else 
                return false;
}

//求栈长度
int StackLength(SqStack S)
{
        return (S.top + 1);
}

//获取栈顶元素
bool GetTop(SqStack S,SElemType *e)
{
        if ( StackEmpty(S) )
                return false;
        *e = S.data[S.top];
        return true;
}

//压栈
bool Push(SqStack *S,SElemType e)
{
        if (S->top == MAXSIZE - 1)
                return false;
        
        S->top++;
        S->data[S->top] = e;
        return true;
}

//弹出栈
bool Pop(SqStack *S,SElemType *e)
{
        if (S->top == -1)
                return false;

        *e = S->data[S->top];
        S->top--;
        return true;
}

//从栈底依次输出每个元素
bool StackTraverse(SqStack S)
{
        int i = 0;
        
        while (i <= S.top)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return true;
}