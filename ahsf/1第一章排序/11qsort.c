# include <stdio.h>
# include <stdlib.h>

int cmp(const void*e1,const void*e2)
{
    return ( ( *(int*)e1 )-*( (int*)e2) );
}

int main()
{
    int arr[]={5,4,3,2,1};
    qsort(arr,5,sizeof(arr[0]),cmp);
    for(int i=0;i<5;i++)
    printf("%d ",arr[i]);

    return 0;
}