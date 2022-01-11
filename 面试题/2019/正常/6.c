/*
执行以下代码段，将产生什么样的输出？请对输出加以解释，并手动计算代码中 t 的值。
int main(int argc, char *argv[]) {
    char x = -2, y = 3;
    char t = (++x) | (y++);
    printf("x = %d, y = %d, t = %d\n", x, y, t);
    t = (++x) || (y++);
    printf("x = %d, y = %d, t = %d\n", x, y, t);
}

*/

# include <stdio.h>

int main(int argc, char *argv[]) {
    char x = -2, y = 3;
    char t = (++x) | (y++); // -1 | 3 == 0xff   x = -1, y = 4;
    printf("x = %d, y = %d, t = %d\n", x, y, t);  // x = -1, y = 4, t = -1 
    t = (++x) || (y++); // 0 | 4 == 1    x = 0, y = 5;
    printf("x = %d, y = %d, t = %d\n", x, y, t); // x = 0, y = 5, t = 1
}