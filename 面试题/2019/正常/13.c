/*
13.请简单叙述两种字节序（大端、小端）的概念，你的机器是什么字节序？试着写一个 C 语言程
序来验证，如果你没有思路，你可以尝试着使用联合体或者指针。
*/

# include <stdio.h>

union
{
    int i;
    char arr[4];
}p;

int main(void)
{
    p.i = 0x12345678;
    printf("%d %x %x %x %x\n", p.i, p.arr[0], p.arr[1], p.arr[2], p.arr[3]);

    return 0;
}