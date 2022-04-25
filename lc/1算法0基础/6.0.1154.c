/*
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。
返回该日期是当年的第几天。

示例 1：
输入：date = "2019-01-09"
输出：9
解释：给定日期是2019年的第九天。

示例 2：
输入：date = "2019-02-10"
输出：41
*/
#include <stdbool.h>

bool isLeepYear(int year)
{
    return ( (year % 4 == 0 && year % 100) || year % 400 == 0 );
}

int strToInt(char *str, int len)
{
    int i, sum = 0;
    for (i = 0; i < len; ++i)
    {
        sum = sum * 10 + str[i] - '0';
    }
    return sum;
}

int dayOfYear(char * date)
{
    int sum = 0, i = 0;

    int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = strToInt(date, 4);
    int month = strToInt(date+5, 2);
    int day = strToInt(date+8, 2);
    monthday[2] = isLeepYear(year) ? 29 : 28;

    for (i = 1; i < month; ++i)
    {
        sum += monthday[i];
    }
    sum += day;
    return sum;
}

int dayOfYear(char * date){
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    int amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        ++amount[1];
    }
    int ans = 0;
    for (int i = 0; i < month - 1; ++i) {
        ans += amount[i];
    }
    return ans + day;
}
