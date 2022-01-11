/*
句子 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。
每个单词仅由大小写英文字母组成（不含标点符号）。
例如，"Hello World"、"HELLO" 和 "hello world hello world" 都是句子。
给你一个句子 s​​​​​​ 和一个整数 k​​​​​​ ，请你将 s​​ 截断 ​，​​​使截断后的句子仅含 前 k​​​​​​ 个单词。
返回 截断 s​​​​​​ 后得到的句子。
示例 1：
输入：s = "Hello how are you Contestant", k = 4
输出："Hello how are you"
解释：
s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
前 4 个单词为 ["Hello", "how", "are", "you"]
因此，应当返回 "Hello how are you"
*/

char * truncateSentence(char * s, int k){
    int i;

    for (i = 0; i < strlen(s); ++i)
    {
        if (isblank(s[i]))
            k--;
        if (k == 0)
            s[i] = '\0';
    }
    return s;
}