/*
分析下面代码，理解二级指针。

#include<stdio.h>
int main(){
    int n,*p,**pp;
    n=10;       p=&n;        pp=&p;
    printf("n=%d,n=%d,n=%d\n",n,*p,**pp);
    printf("%x,%x,%x\n",&n,&p,&pp);
    printf("%x,%x\n",&n,p);
    printf("%x,%x\n",&p,pp);
    return 0; 
}
执行程序，输出：
n=10,n=10,n=10
28febc,28feb8,28feb4（此部分输出可能不同）
28febc,28febc
28feb8,28feb8
输入样例:
结尾无空行
输出样例:
0
结尾无空行
*/

# include <stdio.h>
int main(){
    printf("0");
    return 0; 
}