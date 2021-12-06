/*5.执行下面的代码段，会输出什么？请试着解释其原因，并叙述相关知识。
int main(int argc, char *argv[]) {
 char ch = 255;
 int d = a + 1;
 printf("%d %d", ch, d);
}
*/
# include<stdio.h>

int main(int argc, char *argv[]) {
 char ch = 255;
 int d = 'a' + 1;
 printf("%d %d", ch, d);
}