/*
在一行中输入一个英文句子(不超过80个字符)，输出这个句子中单词的个数，
单词之间以空格分隔，除空格外都认为是单词（包括符号）。

输入样例:
This  is  a  C  program.  <<<  =22=   ,,,   END
结尾无空行
输出样例:
9
*/

# include <stdio.h>

int main(void)
{
    char arr[80][10];
    int i = 0;

    while(scanf("%s",arr[i]) == 1)
    {
        i++;
    }
    
    printf("%d", i);

    return 0;
}