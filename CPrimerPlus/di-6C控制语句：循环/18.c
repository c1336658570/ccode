# include <stdio.h> 
int main(int argc, char *argv[])
{
    int sum = 5, i;

    for (i = 1; ; ++i) 
    {
        sum -= i;
        sum *= 2;
        if (sum > 150)
            break;
        printf("%d week friends:%d\n", i, sum);
    }

    return 0;
}