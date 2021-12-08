/*
编程读入若干整数（不超过50个）到数组中，然后倒序输出，遍历数组时用指针实现。

输入样例:
1 5 25 18 -299
结尾无空行
输出样例:
-299 18 25 5 1
结尾无空行
*/

/*# include <stdio.h>

void put(int *arr, int len);

int main()
{
    int arr[50], i;

    i = 0;
    while(scanf("%d", arr+i) != EOF)
    {
        i++;
    }
    
    put(arr, i);

    return 0;
}

void put(int *arr, int len)
{
    for(len-=1; len>0; --len)
    {
        printf("%d ", arr[len]);
    }
    printf("%d", arr[len]);
}
*/

#include<stdio.h>
int main(void)
{
	int m[50],i=0,j;
	char a = 1;
	
	while((int)a!=10)
	{
		scanf("%d%c",&m[i],&a);
		++i;
    }
   
    int *p=m+i-1;

	for(; p >= m; p--)
		printf("%d ",*p);
}