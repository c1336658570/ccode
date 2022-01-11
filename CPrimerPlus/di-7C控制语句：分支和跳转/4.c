# include <stdio.h>

int main(int argc, char *argv[])
{
    char ch1, ch2;
    int t = 0;

    while(1)
    {
        ch1 = getchar();
        if (ch1 == '#')
            break;
        if (ch1 == '.')
        {
            ch1 = '!';
            t++;
        }
        else if (ch1 == '!')
        {
            t++;
        }
        
    }
    printf("%d\n", t);
    
    return 0;
}