/*
一头母牛，每年生一只，每头小牛第四年开始生牛，每年也生一只，求第n年有多少头牛(n < 55)
*/

/*
1:A
2:A B
3:A B C
4:A B C D
5:A B C D E(from A) F(frmo B)
6:A B C D E F G(from A) H(from B) I(from C)
f[n] = f[n-1]+f[n-3]
*/

# include <stdio.h>

int fib(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
}

int fib(int n)
{
    if (n <= 4)
        return n;
    return fib(n-3) + fib(n-1);
}