# include <stdio.h>
# include <math.h>

int main(int argc, char *argv[])
{
    printf("Enter the operation of your choive:\n");
    printf("a. add          s. subtract\n");
    printf("m. multiply     d.divide\n");
    printf("q. quit\n");

    char ch;
    float a, b;

    while( (ch = getchar()) != 'q' )
    {
        while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
            ch = getchar();
        scanf("%f %f", &a, &b);
        while (fabs(b) < 1e-8 && ch == 'd')
        {
            printf("Please re-enter a number");
            scanf("%f", &b);
        }

        switch( ch )
        {
            case 'a':
                printf("%.2f", a+b);
                break;
            case 's':
                printf("%.2f", a-b);
                break;
            case 'm':
                printf("%.2f", a*b);
                break;
            case 'd':
                printf("%.2f", a/b);
                break;
       }
    }

    return 0;
}