#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void showMenu();                                   //输出菜单
void adjacent_pairs();                             //相邻数对
void Equation_Solving();                           //方程求解
void Confirm_license_plate();                      //确认车牌
void Permutations();                               //排列组合
int dfs(int step, int n, int m, int *a, int *vis); //全排列
void hourglass();                                  //沙漏
void read_write();                                 //文件读写

int main(void)
{
    while (1)
    {
        showMenu(); //打印菜单
        ;
        int choice = 10;                //定义变量（存储选项），开始就初始化，防止开始就输入一串字符串如asdasd，导致程序出错
        int ret = scanf("%d", &choice); //读取选项
        if (ret == 1)
        {
            //根据选项进入不同的分支
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
            rewind(stdin); //错误处理，如果输入非数字，scanf会读取失败，使用rewind清除输入缓冲
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
    srand((unsigned)time(NULL)); //初始化随机数种子
    int n, i, sum, flag = 0;
    int arr[10000]; //定义一个数组，存储1-9999的随机数

    memset(arr, 0, sizeof(arr));
    printf("请输入数据规模N:\n");
    while (scanf("%d", &n) != 1)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin); //清空缓冲区
    }

    //产生n个随机数，并存入到数组arr中
    for (i = 0; i < n; ++i)
    {
        arr[rand() % 9999 + 1] = 1;
    }
    sum = 0; //用于保存相邻元素总对数

    for (i = 0; i < 10000; ++i)
    {
        //比较数组arr中的相邻元素，若两个相邻元素存在，就输出，并且计数器加1
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
    rewind(stdin);

    return;
}

//方程求解
void Equation_Solving()
{
    // a,b,c存系数,delta存b*b-4*a*c,x1,x2存解
    double a, b, c, delta, x1, x2;

    printf("请输入三个系数\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("输入有误，请重新输入三个系数\n");
        rewind(stdin); //刷新输入缓冲区
    }

    //求delta，根据delta的不同进入不同的分支
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

    //如果先输入3个数字，后面再跟一串字符串也会输入成功，在此刷新输入缓冲，将后面的字符串丢弃
    rewind(stdin);

    return;
}

//确认车牌
void Confirm_license_plate()
{
    //定义循环变量
    int i, j, k;
    // i为第3位和第4位车牌的
    for (i = 0; i <= 9; ++i)
    {
        // j为第5位和第6位车牌的值
        for (j = 0; j <= 9; ++j)
        {
            //车牌为4位数0-9999;所以循环判断0-99中是否有哪个数的平方等于车牌
            for (k = 0; k < 100; ++k)
            {
                //如果某个数平方等于车牌等于就输出
                if (k * k == i * 1000 + i * 100 + j * 10 + j)
                {
                    printf("车牌的后四位为：%d%d%d%d\n", i, i, j, j);
                }
            }
        }
    }

    rewind(stdin);
}

//排列组合
void Permutations()
{
    int n, m;
    int a[200], vis[200];    //定义两个数组，一个标记这个数是否走过，一个保存当前值
    memset(a, 0, sizeof(a)); //数组初始化
    memset(vis, 0, sizeof(vis));

    printf("请输入两个整数N, M，M必须小于N:\n");
    while (scanf("%d %d", &n, &m) != 2 || n < m)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }
    dfs(1, n, m, a, vis);

    //如果先输入2个数字，后面再跟一串字符串也会输入成功，在此刷新输入缓冲，将后面的输入丢弃
    rewind(stdin);
}

//全排列
int dfs(int step, int n, int m, int *a, int *vis)
{
    static int i = 0;
    if (step == m + 1) //如果到达最后一层
    {
        int j;
        for (j = 1; j <= m; j++)
        {
            printf("%d ", a[j]);
        }
        i++;
        if (i % 30 == 0)
        {
            putchar('\n');
            system("pause");
        }
        putchar('\n');
    }
    else
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && a[step - 1] < i) //向前一步走的通，且当前元素没被用过
            {
                a[step] = i; //保存当前结果
                vis[i] = 1;  //将当前数字标记为走过
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
        rewind(stdin);
    }

    //上三角
    int i;
    for (i = 0; i <= n / 2; ++i)
    {
        int j;
        //输出空格
        for (j = 0; j < i; ++j)
        {
            putchar(' ');
        }
        int k;
        //输出*
        for (k = 0; k < n - i * 2; ++k)
        {
            printf("*");
        }
        putchar('\n');
    }
    //下三角
    for (i = 0; i < n / 2; ++i)
    {
        int j;
        //输出空格
        for (j = 0; j < n / 2 - i - 1; ++j)
        {
            putchar(' ');
        }
        int k;
        //输出*
        for (k = 0; k < 2 * i + 3; ++k)
        {
            putchar('*');
        }
        putchar('\n');
    }

    rewind(stdin);
}

//数据读写
/*
    1：将从文件中读取的字符串数字，转换为整型
    2：求运算结果，再将运算结果转换为字符串数字
    3：将运算表达式和字符串数字写入到result.txt中
*/
void read_write()
{
    // a和b为进行计算的两个操作数，alen和blen分别是他们用字符串表示时的长度，
    // aflag用来标记a长度是否已经算完，len是字符串总长度
    int a, b, alen, aflag, blen, len;
    int temp = 0; //临时变量，用来将两个操作数（字符串型）转换成整形
    char ch = 0;
    FILE *fp = fopen("express.txt", "r"); //打开要读取的文件
    FILE *fp2 = fopen("result.txt", "w"); //打开目标文件
    //打开文件失败，返回到主程序
    if (fp == NULL)
    {
        perror("fopen() error!");
        return;
    }

    // 1
    char buf[BUFSIZ]; //定义一个字符数组，保存从文件中读取的内容
    while (fgets(buf, BUFSIZ, fp) != NULL)
    {
        a = b = aflag = alen = blen = len = 0;
        temp = 0;
        len = strlen(buf);
        //中间行最后一个字符为'\n'，在此用来判断是中间行还是最后一行
        printf("strlen(buf) = %d, %s", strlen(buf), buf);
        if (buf[len - 1] == '\n')
        {
            int i;
            for (i = 0; i < len - 1; ++i) //从文件中读取的字符包括'\n'，所以要减1
            {
                if (buf[i] != '+' && buf[i] != '-' && buf[i] != '*' && buf[i] != '/' && aflag == 0)
                {
                    alen++;
                }
                else
                {
                    aflag = 1; //将标记置为1意味着a的长度已经求完，可以开始求b的长度
                }
                if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/')
                {
                    ch = buf[i];
                }
                //遇到第一个符号位时，将aflag改为1，即a的长度已求出，需要再求出b的长度，但是直接blen++会把符号位算上,所以在循环外会减减
                if (aflag == 1)
                {
                    blen++;
                }
            }
            printf("blen = %d\n", blen);
            //此处blen--，为了减去符号位
            blen--;
            //求a，即将字符串型数字转变为整形
            for (i = 0; i < alen; ++i)
            {
                temp = buf[i] - '0';
                int j;
                for (j = 0; j < alen - i - 1; ++j)
                {
                    temp *= 10;
                }
                a += temp;
            }
            //求b，即将字符串型数字转变为整形
            printf("blen = %d\n", blen);
            for (i = len - blen - 1; i < len - 1; ++i)
            {
                temp = buf[i] - '0';
                int j;
                for (j = 0; j < len - i - 2; ++j)
                {
                    temp *= 10;
                }
                b += temp;
            }

            // 2判断符号是什么符号，进行运算
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

            // 3将运算结果转为字符串，然后写入目标文件中
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
            int i;
            for (i = 0; i < len; ++i)
            {
                if (buf[i] != '+' && buf[i] != '-' && buf[i] != '*' && buf[i] != '/' && aflag == 0)
                {
                    alen++;
                }
                else
                {
                    aflag = 1; //将标记置为1意味着a的长度已经求完，可以开始求b的长度
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
            //求a，将字符串转为整形
            for (i = 0; i < alen; ++i)
            {
                temp = buf[i] - '0';
                int j;
                for (j = 0; j < alen - i - 1; ++j)
                {
                    temp *= 10;
                }
                a += temp;
            }
            //求b，将字符串转为整形
            for (i = len - blen; i < len; ++i)
            {
                temp = buf[i] - '0';
                int j;
                for (j = 0; j < len - i - 1; ++j)
                {
                    temp *= 10;
                }
                b += temp;
            }
            // 2根据运算符进行运算
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

            // 3将运算结果转为字符串并写入目标文件中
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

    fclose(fp);
    fclose(fp2);
}
