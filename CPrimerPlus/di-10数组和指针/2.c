# include <stdio.h>

void copy_ptrs(double *target2, double *source, double *soures_last);
void copy_arr(double *target1, double *source, int len);
void copy_ptr(double *target2, double *source, int len);
void Input(double *arr, int len);

double main(double argc, char *argv[])
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target1, source, source + 5);
    Input(target1, 5);
    Input(target2, 5);
    Input(target2, 5);

    return 0;
}

void copy_arr(double *target1, double *source, int len)
{
    for (len-=1; len >= 0; --len) 
    {
        target1[len] = source[len];
    }
}

void copy_ptr(double *target2, double *source, int len)
{
    for (len-=1; len >= 0; --len) 
    {
        *(target2+len) = *(source+len);
    }
}

void copy_ptrs(double *target2, double *source, double *soures_last)
{
    for (; source < soures_last; source++)
    {
        *(target2++) = *source;
    }
}

void Input(double *arr, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        printf("%f\t", arr[i]);
    }
    putchar('\n');
}