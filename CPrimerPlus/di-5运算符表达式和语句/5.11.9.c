# include <stdio.h>

void print(double wendu);

int main(int argc, char *argv[]){
    double wendu;
    while(scanf("%lf",&wendu) == 1)
    {   
        print(wendu);
        printf("Input q or not number close:");
    }

    return 0;
}

void print(double wendu)
{
    printf("huashiwendu：%lf\n", wendu);
    printf("sheshiwendu:%lf\n", ( (5.0/9.0)*(wendu - 32) ));
    printf("kaishiwendu:%lf\n", ( (5.0/9.0)*(wendu - 32) ) + 273.46);
}