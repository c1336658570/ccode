/*
给你一个字符串 s ，如果 s 是一个 好 字符串，请你返回 true ，否则请返回 false 。
如果 s 中出现过的 所有 字符的出现次数 相同 ，那么我们称字符串 s 是 好 字符串。

示例 1：

输入：s = "abacbc"
输出：true
解释：s 中出现过的字符为 'a'，'b' 和 'c' 。s 中所有字符均出现 2 次。
示例 2：

输入：s = "aaabb"
输出：false
解释：s 中出现过的字符为 'a' 和 'b' 。
'a' 出现了 3 次，'b' 出现了 2 次，两者出现次数不同。
*/
# include <stdbool.h>



bool areOccurrencesEqual(char * s){
    int i, j, arr[26];
    char ch;

    memset(arr, 0, sizeof(arr));
    for (i = 0; i < strlen(s); ++i)
    {
        arr[s[i] - 'a']++;
        // for (ch = 'a'; ch <= 'z'; ch++)
        // {
        //     if (ch == s[i])
        //     {
        //         arr[ch-'a']++;
        //         break;
        //     }
        // }
    }

    for (i = 0; i < 26; ++i)
    {
        if (arr[i] == 0)
            continue;
        for (j = 0; j < 26; ++j)
        {
            if (arr[j] == 0)
                continue;
            if (arr[i] != arr[j])
                break;
        }
        if (j != 26)
            return false;
    }
    return true;
}