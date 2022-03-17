/*
学生成绩查找系统是一个根据姓名查找学生成绩的系统。系统可以录入是学生的姓名和成绩，
录完之后可以输入查找条件，即学生的姓名，查找该生的成绩，如果存在该生的信息，则输出该生成绩，
否则给出查无此人的提示信息。

输入:题目输入包括录入学生信息和输入查找条件以及输入结束标志。insert语句表示录入学生信息，
格式为字符insert+空格+字符串+空格+数字+换行符 ，例如 insert xiaohua 99 ，
表示录入姓名为xiaohua的学生，其成绩为99 。 find语句表示查找某学生的信息，
格式为字符find+空格+字符串+换行符。例如 find xiaohua。end语句表示输入结束，格式为字符end
输出：对应每一条find语句都应该有一条输出语句。对于find xiaohua这条输入语句，
因为已经插入过xiaohua的成绩 需要输出 99+换行符，否则查找不到输出-1+换行符。

Sample Input
insert zhangsan 90
insert lisi 78
insert xiaoming 86
find xiaoming
find Jack
end
Sample Output
86
-1
*/

# include <stdio.h>
# include <string.h>


struct Student
{
    char name[30];
    int score;
}st[1000];

int main(void)
{
    int i = 0, j;
    char judge[10];
    char find[30];
    while(scanf("%s", judge) && strcmp(judge, "end"))
    {
        getchar();
        if ( !strcmp(judge, "insert") )
        {
            scanf("%s %d", st[i].name, &st[i].score);
            i++;
            getchar();
        }
        if ( !strcmp(judge, "find") )
        {
            scanf("%s", find);
            getchar();
            for (j = 0; j < i; ++j)
            {
                if ( !strcmp(st[j].name, find) )
                {
                    printf("%d\n", st[j].score);
                    break;
                }
            }
            if (j == i)
                printf("-1\n");
        }
    }

    return 0;
}