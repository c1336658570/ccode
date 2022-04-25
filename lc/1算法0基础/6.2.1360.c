/*
请你编写一个程序来计算两个日期之间隔了多少天。
日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。

示例 1：
输入：date1 = "2019-06-29", date2 = "2019-06-30"
输出：1

示例 2：
输入：date1 = "2020-01-15", date2 = "2019-12-31"
输出：15
*/

#include <stdbool.h>

bool isLeepYear(int year)
{
    return ( (year % 4 == 0 && year % 100) || year % 400 == 0);
}


int daysBetweenDates(char * date1, char * date2)
{
    int i, sum = 0;
    int year1 = atoi(date1);
    int month1 = atoi(date1+5);
    int day1 = atoi(date1+8);
    int year2 = atoi(date2);
    int month2 = atoi(date2+5);
    int day2 = atoi(date2+8);
    int monthday1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthday2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    monthday1[2] = isLeepYear(year1) ? 29 : 28;
    monthday2[2] = isLeepYear(year2) ? 29 : 28;

    //也可以写，只要year1 > year2，就交换year1和year2的所有信息（year，month，day，monthday1，monthday2）
    if (year1 < year2)
    {
        for (i = year1+1; i < year2; ++i)
        {
            if (isLeepYear(i))
            {
                sum += 366;
            }
            else
            {
                sum += 365;
            }
        }
        sum += monthday1[month1] - day1;
        for (i = month1+1; i < 13; ++i)
        {
            sum += monthday1[i];
        }
        for (i = 1; i < month2; ++i)
        {
            sum += monthday2[i];
        }
        sum += day2;
    }
    else if (year1 > year2)
    {
        for (i = year2+1; i < year1; ++i)
        {
            if (isLeepYear(i))
            {
                sum += 366;
            }
            else
            {
                sum += 365;
            }
        }
        sum += monthday2[month2] - day2;
        for (i = month2+1; i < 13; ++i)
        {
            sum += monthday2[i];
        }
        for (i = 1; i < month1; ++i)
        {
            sum += monthday1[i];
        }
        sum += day1;
    }
    else
    {
        if (month1 < month2)
        {
            sum += monthday1[month1] - day1;
            for (i = month1+1; i < month2; ++i)
            {
                sum += monthday1[i];
            }
            sum += day2;
        }
        else if (month1 > month2)
        {
            sum += monthday2[month2] - day2;
            for (i = month2+1; i < month1; ++i)
            {
                sum += monthday2[i];
            }
            sum += day1;
        }
        else
        {
            sum = abs(day2 - day1);
        }
        
    }

    return sum;
    
}