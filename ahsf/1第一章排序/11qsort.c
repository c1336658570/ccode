# include <stdio.h>
# include <stdlib.h>

int cmp(const void*e1,const void*e2)
{
    return ( ( *(int*)e1 )-*( (int*)e2) );
}

int cmp_int(const void* _a , const void* _b)  //参数格式固定
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *a - *b;
}

int cmp_char(const void* _a , const void* _b)  //参数格式固定
{
    char* a = (char*)_a;    //强制类型转换
    char* b = (char*)_b;
    return *a - *b;
}

int cmp_double(const void* _a , const void* _b)//参数格式固定
{
    double* a = (double*)a;    //强制类型转换
    double* b = (double*)_b;
    return *a > *b ? 1 : -1;  //特别注意
}

int main()
{
    int arr[]={5,4,3,2,1};
    qsort(arr,5,sizeof(arr[0]),cmp);
    for(int i=0;i<5;i++)
    printf("%d ",arr[i]);

    return 0;
}