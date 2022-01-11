/*
    舍弃超过数组长度的字符
*/
# include <string.h>
# include <stdio.h>

char * s_gets(char * st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) // 即，ret_val != NULL
    {
        while(ret_val[i] != '\n' && ret_val != '\0')
        {
            i++;
        }
        if (ret_val[i] == '\n')
        {
            ret_val[i] = '\0';
        }
        else
        {
            while(getchar != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}