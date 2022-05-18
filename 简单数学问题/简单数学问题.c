#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

void showMenu();
void adjacent_pairs();
void Equation_Solving();
void Confirm_license_plate();
void Permutations();
int dfs(int step, int n, int m, int *a, int *vis);
void hourglass();
void read_write();

int main(void)
{
    while (1)
    {
        showMenu();
        int choice;
        int ret = scanf("%d", &choice); //读取选项
        if (ret == 1)
        {
            switch (choice)
            {
            case 1:
                adjacent_pairs();
                break;
            case 2:
                Equation_Solving();
                break;
            case 3:
                Confirm_license_plate();
                break;
            case 4:
                Permutations();
                break;
            case 5:
                hourglass();
                break;
            case 6:
                read_write();
                break;
            case 0:
                exit(0);
                break;
            default:
                break;
            }
        }
        else
        {
            fflush(stdin); //错误处理，如果输入非数字，scanf会读取失败，然后用getcahr将所有非数字读取
        }
    }
    return 0;
}

//输出菜单
void showMenu()
{
    printf("\t\t\t1.相邻数对\n");
    printf("\t\t\t2.方程求解\n");
    printf("\t\t\t3.确认车牌\n");
    printf("\t\t\t4.排列组合\n");
    printf("\t\t\t5.沙漏\n");
    printf("\t\t\t6.数据读写\n");
    printf("\t\t\t0.退出\n");
    printf("\t\t\t请输入0-6：\n");
}

//相邻数对
void adjacent_pairs()
{
    srand((unsigned)time(NULL));
    int n, i, sum, flag = 0;
    int arr[10000];

    memset(arr, 0, sizeof(arr));
    printf("请输入数据规模N:\n");
    while (scanf("%d", &n) != 1)
    {
        printf("输入有误，请重新输入\n");
        fflush(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        arr[rand() % 9999 + 1] = 1;
    }
    sum = 0;
    for (i = 0; i < 10000; ++i)
    {
        if (arr[i] && arr[i + 1])
        {
            printf("(%d,%d) ", i, i + 1);
            flag++;
            if (flag % 5 == 0)
            {
                putchar('\n');
            }
            sum++;
        }
    }
    if (flag % 5)
    {
        putchar('\n');
    }
    printf("一共有%d个相邻数对\n", sum);
    //如果先输入一个数字，后面再跟一串字符串也会输入成功，在此刷新输入缓冲，将后面的字符串丢弃
    fflush(stdin);

    return;
}

//方程求解
void Equation_Solving()
{
    double a, b, c, delta, x1, x2;

    printf("请输入三个系数\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("输入有误，请重新输入三个系数\n");
        fflush(stdin); //刷新输入缓冲区
    }

    delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("方程有两个解x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = x2 = -b / (2 * a);
        printf("方程有一个解x = %.2lf\n", x1);
    }
    else
    {
        printf("方程有两个虚根x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\n",
               -b / (2 * a), (sqrt(-delta) / (2 * a)),
               -b / (2 * a), (sqrt(-delta) / (2 * a)));
    }

    //如果先输入一个数字，后面再跟一串字符串也会输入成功，在此刷新输入缓冲，将后面的字符串丢弃
    fflush(stdin);

    return;
}

//确认车牌
void Confirm_license_plate()
{
    int i, j, k;
    for (i = 0; i <= 9; ++i)
    {
        for (j = 0; j <= 9; ++j)
        {
            for (k = 0; k < 100; ++k)
            {
                if (k * k == i * 1000 + i * 100 + j * 10 + j)
                {
                    printf("车牌的后四位为：%d%d%d%d\n", i, i, j, j);
                }
            }
        }
    }

    fflush(stdin);
}

//排列组合
void Permutations()
{
    int n, m;
    int a[200], vis[200];
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));

    printf("请输入两个整数N, M，M必须小于N:\n");
    while (scanf("%d %d", &n, &m) != 2 || n < m)
    {
        printf("输入有误，请重新输入\n");
        fflush(stdin);
    }
    dfs(1, n, m, a, vis);

    fflush(stdin);
}

//全排列
int dfs(int step, int n, int m, int *a, int *vis)
{
    if (step == m + 1) //如果到达目的地，输出排列
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", a[j]);
        }
        putchar('\n');
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && a[step - 1] < i) //向前一步走的通：没被用过
            {
                a[step] = i; //保存当前结果
                vis[i] = 1;  //这个格子标记为用过
                dfs(step + 1, n, m, a, vis);
                vis[i] = 0; //回溯
            }
        }
    }
    return 0;
}

//沙漏
void hourglass()
{
    int n;

    printf("请输入一个奇数");
    while (scanf("%d", &n) != 1 || n % 2 == 0)
    {
        printf("输入有误，请重新输入：\n");
        fflush(stdin);
    }

    //上三角
    for (int i = 0; i <= n / 2; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            putchar(' ');
        }
        for (int k = 0; k < n - i * 2; ++k)
        {
            printf("*");
        }
        putchar('\n');
    }
    //下三角
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n / 2 - i - 1; ++j)
        {
            putchar(' ');
        }
        for (int k = 0; k < 2 * i + 3; ++k)
        {
            putchar('*');
        }
        putchar('\n');
    }

    fflush(stdin);
}

//数据读写
/*
    1：将从文件中读取的字符串数字，转换为整型
    2：求运算结果，再将运算结果转换为字符串数字
    3：将运算表达式和字符串数字写入一个临时文件
    4：全部处理完成后，将临时文件中的内容读入到程序然后写回express.txt中
*/
void read_write()
{
    int a, b, alen, aflag, blen, len;
    int temp = 0;
    char ch = 0;
    FILE *fp = fopen("express.txt", "r");
    FILE *fp2 = fopen("temp.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen() error!");
        return;
    }

    // 1
    unsigned char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, fp) != NULL)
    {
        a = b = aflag = alen = blen = len = 0;
        temp = 0;
        len = strlen(buf);
        if (buf[len - 1] == '\n')
        {

            for (int i = 0; i < len - 1; ++i) //从文件中读取的字符包括'\n'，所以要减1
            {
                if (buf[i] != '+' && buf[i] != '-' && buf[i] != '*' && buf[i] != '/' && aflag == 0)
                {
                    alen++;
                }
                else
                {
                    aflag = 1;
                }
                if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/')
                {
                    ch = buf[i];
                }
                //遇到第一个符号位时，将aflag改为1，即a的长度已求出，需要再求出b的长度，但是直接blen++会把符号位算上
                if (aflag == 1)
                {
                    blen++;
                }
            }

            //此处blen--，为了减去符号位
            blen--;
            //求a
            for (int i = 0; i < alen; ++i)
            {
                temp = buf[i] - '0';
                for (int j = 0; j < alen - i - 1; ++j)
                {
                    temp *= 10;
                }
                a += temp;
            }
            //求b
            for (int i = len - blen - 1; i < len - 1; ++i)
            {
                temp = buf[i] - '0';
                for (int j = 0; j < len - i - 2; ++j)
                {
                    temp *= 10;
                }
                b += temp;
            }

            // 2
            int c = 0;
            switch (ch)
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = a / b;
                break;
            }
            printf("%d%c%d=%d\n", a, ch, b, c);

            // 3
            int val = c;
            int vallen = 0;
            buf[len + 1] = buf[len];
            buf[len] = buf[len - 1];
            buf[len - 1] = '=';
            len++;
            if (val < 0)
            {
                c = -c;
                val = val * -1;
                buf[len + 1] = buf[len];
                buf[len] = buf[len - 1];
                buf[len - 1] = '-';
                len++;
            }
            while (val)
            {
                vallen++;
                val /= 10;
            }
            buf[len + vallen] = '\0';
            buf[len + vallen - 1] = '\n';
            while (c)
            {
                buf[len + vallen - 2] = c % 10 + '0';
                vallen--;
                c /= 10;
            }
            fputs(buf, fp2);
        }
        else
        {
            for (int i = 0; i < len; ++i)
            {
                if (buf[i] != '+' && buf[i] != '-' && buf[i] != '*' && buf[i] != '/' && aflag == 0)
                {
                    alen++;
                }
                else
                {
                    aflag = 1;
                }
                //将符号存入ch中，为了后边进行运算
                if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/')
                {
                    ch = buf[i];
                }
                //遇到第一个符号位时，将aflag改为1，即a的长度已求出，需要再求出b的长度.
                if (aflag == 1)
                {
                    blen++;
                }
            }

            //此处blen--，为了减去符号位
            blen--;
            //求a
            for (int i = 0; i < alen; ++i)
            {
                temp = buf[i] - '0';
                for (int j = 0; j < alen - i - 1; ++j)
                {
                    temp *= 10;
                }
                a += temp;
            }
            //求b
            for (int i = len - blen; i < len; ++i)
            {
                temp = buf[i] - '0';
                for (int j = 0; j < len - i - 1; ++j)
                {
                    temp *= 10;
                }
                b += temp;
            }
            // 2
            int c = 0;
            switch (ch)
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = a / b;
                break;
            }
            printf("%d%c%d=%d\n", a, ch, b, c);

            // 3
            int val = c;
            int vallen = 0;
            buf[len + 1] = buf[len];
            buf[len] = '=';
            len++;
            if (val < 0)
            {
                c = -c;
                val = val * -1;
                buf[len + 1] = buf[len];
                buf[len] = '-';
                len++;
            }
            while (val)
            {
                vallen++;
                val /= 10;
            }
            buf[len + vallen] = '\0';
            while (c)
            {
                buf[len + vallen - 1] = c % 10 + '0';
                vallen--;
                c /= 10;
            }
            fputs(buf, fp2);
        }
    }
    // 4将临时文件中的内容写入express.txt中
    fclose(fp);
    fp = fopen("express.txt", "w");
    fseek(fp2, 0, SEEK_SET);
    while (fgets(buf, BUFSIZ, fp2) != NULL)
    {
        fputs(buf, fp);
    }

    fclose(fp);
    fclose(fp2);
}