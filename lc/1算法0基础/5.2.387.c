/*给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
示例：
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
*/

int firstUniqChar(char * s){
    if (strlen(s) == 1)
        return 0;
    int i, j;
    int flag[strlen(s)];
    memset(flag, 0, sizeof(flag));

    for (i = 0; i < strlen(s)-1; ++i)
    {
        for (j = i+1; j < strlen(s); ++j)
        {
            if (s[i] == s[j])
            {   
                flag[i] = flag[j] = 1;
                break;
            }
        }
        if (flag[i] == 0)
            return i;
    }
    if (flag[i] == 0)
        return i;
    return -1;
}

int firstUniqChar(char * s){
    int i, j;

    for (i = 0; i < strlen(s); ++i)
    {
        for (j = 0; j < strlen(s); ++j)
        {
            if (i == j)
                continue;
            if (s[i] == s[j])
                break;
        }
        if (j == strlen(s))
            return i;
    }
    return -1;
}