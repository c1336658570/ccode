/*
学校全体员工分为教师和行政人员两类。教师的数据包括：编号，姓名，职业(t)，
职称(教授professor,副教授associate professor,讲师lecturer等)；行政人员的数据包括：
编号，姓名，职业(w)，部门号(100,200,300等)。要求输入若干人员的数据并能输出他们的资料，
同时统计教师(tcount)和行政人员(wcount)的数量。使用动态内存分配函数实现。

输入格式:
输入第一行给出正整数n，随后给出n个员工的信息。

输出格式:
输出指定数量的员工信息，并在最后一行输出教师和行政人员的数量。

输入样例:
5
10000 jack t professor
20000 rose t associate professor
30000 mike w 100
40000 robin w 200
50000 lina t lecturer
结尾无空行
输出样例:
10000 jack t professor
20000 rose t associate professor
30000 mike w 100
40000 robin w 200
50000 lina t lecturer
tcount = 3, wcount = 2
结尾无空行
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

typedef struct staff
{
    int number;
    char name[40];
    char profession;
    union
    {
        char job[40];
        int num;
    }s;
}staff;

int main(void)
{
    int n, i, tcount = 0, wcount = 0;
    
    scanf("%d", &n);
    staff * arr = (staff *)malloc(sizeof(staff) * n);
    if (arr == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    for (i = 0; i < n; ++i)
    {
        scanf("%d %s %c", &arr[i].number, arr[i].name, &arr[i].profession);
        if (arr[i].profession == 't')
        {
            gets(arr[i].s.job);
            printf("%d %s %c%s\n", arr[i].number, arr[i].name, arr[i].profession, arr[i].s.job);
            tcount++;
        }
        else
        {
            scanf("%d", &arr[i].s.num);
            printf("%d %s %c %d\n", arr[i].number, arr[i].name, arr[i].profession, arr[i].s.num);
            wcount++;
        }
    }
    printf("tcount = %d, wcount = %d", tcount, wcount);

    free(arr);
    arr = NULL;

    return 0;
}