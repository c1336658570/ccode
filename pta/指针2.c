/*
    交换俩数
*/

# include <stdio.h>

void swap(int *pa, int *pb){    
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
}
int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);

    return 0;
}