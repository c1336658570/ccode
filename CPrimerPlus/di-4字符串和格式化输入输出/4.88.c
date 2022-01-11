# include <stdio.h>
# define xishu (3.785 / 1.609)


int main(int argc, char *argv[])
{
    float yl, oil;

    printf("yl:");
    scanf("%f", &yl);
    printf("oil:");
    scanf("%f", &oil);

    printf("%.1f\n", yl/oil);
    printf("%.1f", xishu*(oil*100)/yl);

    return 0; 
}