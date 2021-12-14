/*
    将后n位1变0， 0 变1
*/

# include <stdio.h>
# include <limits.h>

char *itobs(int n, char *ps);
void show_bstr(const char *str);
int invert_end(int number, int bits);

int main(int argc, char *argv[])
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str); // 将整数转换为二进制字符串
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT *sizeof(int);

    for (i = size-1; i >= 0; --i)
    {
        ps[i] = (01 & n) + '0';
        n >>= 1;
    }
    ps[size] = '\0';
    
    return ps;
}

void show_bstr(const char *str)
{
    int i = 0;

    while(str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

int invert_end(int number, int bits)
{
    int mask = 0;
    int bitval = 1;

    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return number ^ mask;
}