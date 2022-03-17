/*
习了字符串相关知识的王大队长在思考一些问题：现在王大队长有一个字符串s ，
他想找到两个非空字符串 a and b ，来满足下面的条件：字符串 a 和 b 都是 s 的子序列；
对于每个索引 i, 字符串 s 的字符 si,必须恰好属于字符串 a 或 b 其中一个；
字符串 a 必须是字典序 最小的，字符串 b 则可以是任何可能的字符串；
现在给定字符串 s, 请打印出任意一组有效的 a 和 b.

Input
每个测试包含多个测试用例。第一行包含测试用例的数量 t (1≤t≤1000). 测试用例的描述如下：
每个测试用例的第一行也是唯一一行包含一个字符串 s(2≤∣s∣≤100 其中 |s| 表示 s 的长度). 
字符串 s 由小写拉丁字母组成。

Output
对于每个测试用例，打印满足给定条件的字符串 a 和 b ，如果有多个答案，请输出任意一个。

Example
Input
3
fc
aaaa
thebrightboiler
Output
c f
a aaa
b therightboiler
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
    char s[101], a[2], b[101];
    int i, j, k, n;;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", s);
        for (j = 0, k = 0; j < strlen(s); ++j)
        {
            if (s[k] > s[j])
                k = j;
        }
        a[0] = s[k];
        a[1] = '\0';
        memcpy(b, s, k);
        memcpy(b+k, s+k+1, strlen(s)-k);
        printf("%s %s\n", a, b);
    }

}