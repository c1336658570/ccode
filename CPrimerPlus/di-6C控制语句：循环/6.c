# include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, t;
    char ch;

    printf("Please enter big char:");
    scanf("%c", &ch);
    char arr[ch-'A'+1][ (ch-'A'+1)*2 - 1 ];

    for (i = 0; i <= ch-'A'; ++i)
    {
        t = 2;
        arr[i][0] = arr[i][i*2+1] = 'A';
        for (j = 1; j <= i*2; ++j)
        {
            if(j <= i)
                arr[i][j] = 'A'+j;
            else
            {
                arr[i][j] = 'A'+j-t;
                t += 2;
            }
        }
        
    }
    for(i = 0; i <= ch-'A'; ++i)
    {
        for (j = 0; j < ch-'A'-i; ++j)
        {
            printf(" ");
        }

        for (j = 0; j < i*2+1; ++j)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}