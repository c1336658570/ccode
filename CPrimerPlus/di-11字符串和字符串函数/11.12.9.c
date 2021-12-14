/*
char *gets_s(char *st, int n)改写
*/

# include <stdio.h>

char *gets_s(char *st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (*st != '\0' && *st != '\n')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}