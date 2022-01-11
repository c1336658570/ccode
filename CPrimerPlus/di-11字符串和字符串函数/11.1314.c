#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, char** argv)
{
    char *end;
    double a = strtod(argv[1], &end);
    long b = strtol(argv[2], &end, 10);
    double sum = 1.0;

    for (long i = 0; i < b; ++i) {
        sum *= a;
    }
    
    printf("%lf\n", sum);
    return 0;
}