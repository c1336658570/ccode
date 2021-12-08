/*
定义结构体struct stu，编写成绩排名函数:void sort(struct stu *ps,int n),
对结构体数组按成绩排名。 程序功能为读入整数N（N<100）,再读入N个学生的学号（整型）和成绩(实数)。
按样例输出排名。

输入格式:
见样例

输出格式:
第一列是名次，注意并列情况；第二列是学号，第三列是成绩（2位小数）。

输入样例:
5
101 99
102 100
103 50
104 80
105 99
输出样例:
1 102 100.00
2 101 99.00
2 105 99.00
4 104 80.00
5 103 50.00
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct student
{
    int num;
    float score;
}student;

void sort(student *ps,int n);

int main(void)
{
    int n, i, j, t;

    scanf("%d", &n);
    student *arr = (student *)malloc(sizeof(student) * n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %f", &arr[i].num, &arr[i].score);
    }
    sort(arr, n);
    for (i = 0; i < n; ++i)
    {
        t = 0;
        if (i == n-1)
            break;
        if (i == 0)
        {
            printf("%d %d %.2f\n", i + 1, arr[i].num, arr[i].score);
        }
        else
        {
            if (arr[i].score == arr[i-1].score)
            {
                for(j = i; j >= 0; --j)
                {
                    if (arr[j].score != arr[j-1].score)
                    {
                        break;
                    }
                    t++;
                }
                printf("%d %d %.2f\n", i + 1 - t, arr[i].num, arr[i].score);
            }
            else
            {
                printf("%d %d %.2f\n", i + 1, arr[i].num, arr[i].score);
            }
        }
    }
    t = 0;
    if (arr[i].score == arr[i-1].score)
        {
            for(j = i; j >= 0; --j)
            {
                if (arr[j].score != arr[j-1].score)
                {
                    break;
                }
                t++;
            }
            printf("%d %d %.2f", i + 1 - t, arr[i].num, arr[i].score);
        }
    else
    {
        printf("%d %d %.2f", i + 1, arr[i].num, arr[i].score);
    }
    free(arr);

    return 0;
}

void sort(student *ps,int n)
{
    int i, j;

    student p;

    for (i = 0; i < n-1; ++i)
    {
        for (j = i+1; j < n; j++)
        {
            if (ps[i].score < ps[j].score)
            {
                p = ps[i];
                ps[i] = ps[j];
                ps[j] = p;
            }
        }
    }
}