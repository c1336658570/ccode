# include <stdio.h>

int main(int argc, char *argv[])
{
    const float yang = 2.05;
    const float tian = 1.15;
    const float hu = 1.09;
    char ch;
    float weight = 0, price = 0, i, j;

    while ( printf("Input a, b or c or q quit\n") )
    {
        (ch = getchar());
        if (ch == 'q')
            break;
        printf("Input weight:\n");
        switch(ch)
        {
            case 'a':
                scanf("%f", &i);
                weight += i;
                price += yang*i;
                break;
            case 'b':
                scanf("%f", &i);
                weight += i;
                price += tian*i;
                break;
            case 'c':
                scanf("%f", &i);
                weight += i;
                price += hu*i;
                break;
            default:
                printf("Input error!\n");
        }
        while(getchar() != '\n');
    }
    if (weight < 5 && weight > 0)
    {
        printf("%f", 6.5+price);
    }
    else if(weight < 20)
    {
        printf("%f", 14+price);
    }
    else if(price < 100)
    {
        printf("%f", 14+(weight-20)*0.5 + price );
    }
    else
    {
        printf("%f",( 14+(weight-20)*0.5 +price)*0.95 );
    }

    return 0;
}