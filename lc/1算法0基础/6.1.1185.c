/*
1185. 一周中的第几天
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
输入为三个整数：day、month 和 year，分别表示日、月、年。
您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", 
                        "Thursday", "Friday", "Saturday"}。

示例 1：
输入：day = 31, month = 8, year = 2019
输出："Saturday"

示例 2：
输入：day = 18, month = 7, year = 1999
输出："Sunday"

示例 3：
输入：day = 15, month = 8, year = 1993
输出："Sunday"

给出的日期一定是在 1971 到 2100 年之间的有效日期。
*/
# include <stdbool.h>

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100) || (year % 400 == 0);
}

char * dayOfTheWeek(int day, int month, int year)
{
    int i, j, sum = 4;
    int monthday[] = {0,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    //1971.1.1周五
    char *d[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                "Friday", "Saturday"};
    for (i = 1971; i < year; ++i)
    {
        if ( isLeapYear(i) )
            sum += 366;
        else
            sum += 365;
        // monthday[2] = isLeapYear(i) ? 29 : 28;
        // for (j = 1; j <= 12; ++j)
        // {
        //     sum += monthday[j];
        // }
    }

    monthday[2] = isLeapYear(year) ? 29 : 28;
    for (j = 1; j < month; ++j)
    {
        sum += monthday[j];
    }
    sum += day;
    sum %= 7;
    return d[sum];
}

//基姆拉尔森公式
//0年1月1日是星期天
char * dayOfTheWeek(int day, int month, int year)
{
    int w;
    char *d[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                "Friday", "Saturday"};
    int e[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

    // w = (day - 1 + year + (year-1)/4 -(year-1)/100 + (year-1)/400 );
    // if ( isLeapYear(year) && month > 2)
    // {
    //     w += 1+e[month-1];
    // }
    // else 
    // {
    //     w += e[month-1];
    // }
    w = (d-1 + year + e[month-1] + year/4 - year/100 + year/400);
    if(month < 3 && (year%4==0 && year%100 || year%400==0) && year!=0) 
        --w; 
    w %= 7;

    return d[w];
}

//改进
//0年3月1日是星期3
//将一月和二月当作13和14月
char * dayOfTheWeek(int day, int month, int year)
{
    int w;
    char *d[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                "Friday", "Saturday"};
    int e[] = {0, 3, 5, 1, 3, 6, 2, 4, 0, 2, 5, 1}; //3 - 14月，即3-12+1-2
    // f(m) = -1 + 2*m + 3*(m+1)/5的结果：2   4   
    //0   3   5   1   3   6   2   4   0   2   5   1 后12项和e[]一样

    if (month == 1 || month == 2)
    {
        month += 12;
        year--;
    }
    w = (day + 2 + year + year/4 -year/100 + year/400 + e[month-3] ) % 7;
    w = (day + 1 + 2*month + 3*(month+1)/5 + year + (year/4) - year/100 + year/400) % 7;
    return d[w];
}