/*
1. 下面代码的输出是什么？试着解释原因，说出你的理解。
struct A {
long a;
int b;
};
int main(int argc, char* argv[])
{
struct A num = {0x6e694c756f796978,0x7875};
char ch = '0';
for(int i = 0; ch; i++)
{
ch = *((char *)&num + i);
printf("%c",ch);
}
printf("\n");
return 0;
}
*/

# include <stdio.h>

struct A {
    long a;
    int b;
};
int main(int argc, char* argv[])
{
    struct A num = {0x6e694c756f796978,0x7875}; //120
    char ch = '0';
    for(int i = 0; ch; i++)
    {
        ch = *((char *)&num + i);
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}