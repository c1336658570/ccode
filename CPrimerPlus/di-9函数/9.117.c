# include <stdio.h>
# include <ctype.h>

void Input();
int zimu(char ch);

int main(void)
{
    sInput();

    return 0;
}

void Input()
{
    char ch;
    int i;

    while ((ch = getchar()) != EOF)
    {
        i = zimu(ch);
        if (i == -1)
            printf("不是字母！\n");
        else
            printf("是字母！%d\n", i);
    }
}
int zimu(char ch)
{
    int i = -1;
    if ( isalpha(ch) )
    {
        if(ch < 97)
        {
            i = ch-'A'+1;
        }
        else
        {
            i = ch-'a'+1;
        }
    }

    return i;
}