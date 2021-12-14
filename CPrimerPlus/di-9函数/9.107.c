/*
    测试函数
*/

# include <stdio.h>

void salami(int num);

int main(int argc, char *argv[])
{
    salami(5);

    return 0;
}

void salami(num)
    //int num, count; //count 错误
    int num;
{
    int count;
    //int num, count; // 错误
    for (count = 1; count <= num; count++)
    {
        printf("O salami mio!\n");
    }
}