//统计元音
/*
统计每个元音字母在字符串中出现的次数

输入：
输入数据包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串

输出：
对于每个测试实例输出5行
a:num1
e:num2
i:num3
o:num4
u:num5
多个测试案例空格隔开
最后一块输出无空格
*/

# include <stdio.h>
# include <string.h>

int cnt[5];

int main(void)
{
    int n, i;
    char str[101];
    scanf("%d", &n);
    getchar();

    get(str);
    for (i = 0; i < strlen(str); ++i)
    {
        if(str[i] == 'a') ++cnt[0];
        else if(str[i] == 'e') ++cnt[1];
        else if(str[i] == 'i') ++cnt[2];
        else if(str[i] == 'o') ++cnt[3];
        else if(str[i] == 'u') ++cnt[4];
    }
    printf("%d %d %d %d %d", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);

    return 0;
}