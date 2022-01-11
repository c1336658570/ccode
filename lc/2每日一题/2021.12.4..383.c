/*
为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。

给你一个赎金信 (ransomNote) 字符串和一个杂志(magazine)字符串，
判断 ransomNote 能不能由 magazines 里面的字符构成。
如果可以构成，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
*/
# include <stdlib.h>
# include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){

    int i, j;
    int *book = (int *)malloc(4 * strlen(magazine));

    for (i = 0; i < strlen(magazine); ++i)
    {
        book[i] = 0;
    }

    for (i = 0; i < strlen(ransomNote); ++i)
    {
        for (j = 0; j < strlen(magazine); ++j)
        {
            if (book[j] == 0 && ransomNote[i] == magazine[j])
            {
                book[j] = 1;
                break;
            }
        }
        if (j == strlen(magazine))
            return false;
    }
    return true;

}