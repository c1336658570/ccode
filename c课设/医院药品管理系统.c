/*
    药品管理系统
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEDICINE_FILE "medicine.txt"
#define USER_FILE "user.txt"

typedef struct medicine
{
    char drug_name[100]; //药品名
    int drug_number;     //药品编号
    char drug_type[50];  //药品类型（中药，西药）
    int cost;            //成本
    int price;           //售价
    int num;             //药品剩余数量
} medicine;

struct med
{
    medicine medicine_array[500]; //存放药品的数组
    int size;                     //数组已使用的大小
} med;

typedef struct user_f
{
    char name[50];   //账号
    char passwd[50]; //密码
} user_f;

typedef struct user
{
    user_f userarray[50];
    int size; //管理员个数
} user;

//与登录相关函数
void login_menu(user *userarr);     //登录菜单
void reg(user *userearr);           //注册账号
bool login(user *userarr);          //登录账号
void revise_passwd(user *userarr);  //修改密码
void get_passwd(user *userarr);     //找回密码
void save_user(user *userarr);      //保存账号到文件
void read_user_file(user *userarr); //从文件中读取管理员信息

//与药品操作相关函数
void showMenu();                //打印菜单
void read_medicine_file();      //从文件中读入药品信息
void add_medicine();            //添加药品信息
void show_medicine();           //查看所有药品信息
void drug_number_del();         //按编号删除药品信息
void drug_name_del();           //按姓名删除药品信息
void drug_number_revise();      //按编号修改药品信息
void drug_name_revise();        //按姓名修改药品信息
int drug_number_find(int num);  //按编号查找药品信息，返回下标
void show_drug_number_find();   //输出查找到的药品信息
int drug_name_find(char *name); //按姓名查找药品信息，返回下标
void show_drug_name_find();     //按姓名查找药品信息，并将药品信息输出
void drug_number_sort();        //按编号排序药品信息
void drug_name_sort();          //按姓名排序药品信息
void save_medicine();           //保存药品信息到文件

int main(int argc, char *argv[])
{
    int select = 15;
    user userarr;

    read_user_file(&userarr); //从文件读管理员信息

    login_menu(&userarr); //登录账号菜单

    read_medicine_file(); //读取文件中药品的信息

    while (1)
    {
        showMenu(); //打印菜单
        while (scanf("%d", &select) != 1 || select < 0 || select > 10)
        {
            printf("输入有误，请重新输入\n");
            rewind(stdin); //将输入指针置于输入流首部
        }

        switch (select)
        {
        case 0:
            //退出程序
            exit(0);
            break;
        case 1:
            //添加药品信息
            add_medicine();
            break;
        case 2:
            //查看所有药品信息
            show_medicine();
            break;
        case 3:
            //按编号删除药品信息
            drug_number_del();
            break;
        case 4:
            //按姓名删除药品信息
            drug_name_del();
            break;
        case 5:
            //按编号修改药品信息
            drug_number_revise();
            break;
        case 6:
            //按姓名修改药品信息
            drug_name_revise();
            break;
        case 7:
            //按编号查找药品信息，并将药品信息输出
            show_drug_number_find();
            break;
        case 8:
            //按姓名查找药品信息，并将药品信息输出
            show_drug_name_find();
            break;
        case 9:
            //按编号排序药品信息
            drug_number_sort();
            break;
        case 10:
            //按姓名排序药品信息
            drug_name_sort();
            break;
        }
    }

    return 0;
}

//登录菜单
void login_menu(user *userarr)
{
    while (1)
    {
        printf("\033[35m欢迎使用药品管理系统！\033[0m\n");
        printf("\033[35m1、注册账号\033[0m\n");
        printf("\033[35m2、登录账号\033[0m\n");
        printf("\033[35m3、修改密码\033[0m\n");
        printf("\033[35m4、找回密码\033[0m\n");
        printf("\033[35m0、退出\033[0m\n");

        int select = 3, flag = 0;

        while (scanf("%d", &select) != 1 || select < 0 || select > 4)
        {
            printf("输入有误，请重新输入!\n");
            rewind(stdin);
        }
        switch (select)
        {
        case 0:
            //退出程序
            exit(0);
            break;
        case 1:
            //注册账号
            reg(userarr);
            break;
        case 2:
            //登录账号
            if (login(userarr))
            {
                printf("登录成功\n");
                flag = 1;
            }
            else
            {
                printf("登录失败，程序退出\n");
                exit(-1);
            }
            break;
        case 3:
            revise_passwd(userarr);
            break;
        case 4:
            get_passwd(userarr);
            break;
        }
        if (flag == 1)
        {
            break;
        }
    }
}

//注册账号
void reg(user *userarr)
{
    printf("请输入账号\n");
    scanf("%s", userarr->userarray[userarr->size].name);
    printf("请输入密码\n");
    scanf("%s", userarr->userarray[userarr->size].passwd);
    userarr->size++;
    printf("注册成功\n");

    save_user(userarr);
}

//登录账号
bool login(user *userarr)
{
    char name[50], passwd[50];
    int i, j;

    for (j = 0; j < 5; ++j)
    {
        printf("\033[35m第%d次登录\033[0m\n", j + 1);
        printf("\033[35m请输入你的账号\033[0m\n");
        scanf("%s", name);
        printf("\033[35m请输入你的密码\033[0m\n");
        scanf("%s", passwd);
        for (i = 0; i < userarr->size; ++i)
        {
            if (strcmp(userarr->userarray[i].name, name) == 0)
            {
                if (strcmp(userarr->userarray[i].passwd, passwd) == 0)
                {
                    return true;
                }
            }
        }
        printf("\033[35第%d次登录失败\033[0m\n", j + 1);
    }

    return false;
}

//修改密码
void revise_passwd(user *userarr)
{
    char name[50];
    int i;

    printf("请输入你要修改的姓名\n");

    scanf("%s", name);

    for (i = 0; i < userarr->size; ++i)
    {
        if (strcmp(name, userarr->userarray[i].name) == 0)
        {
            printf("请输入新密码\n");
            scanf("%s", userarr->userarray[i].passwd);
            printf("修改成功\n");
            save_user(userarr);
            return;
        }
    }
    printf("未找到该用户\n");
}

//找回密码
void get_passwd(user *userarr)
{
    char name[50];
    int i;

    printf("请输入你要找回的姓名\n");

    scanf("%s", name);

    for (i = 0; i < userarr->size; ++i)
    {
        if (strcmp(name, userarr->userarray[i].name) == 0)
        {
            printf("该用户的密码为：%s\n", userarr->userarray[i].passwd);
            return;
        }
    }
    printf("未找到该用户\n");
}

//保存账号到文件
void save_user(user *userarr)
{
    int i;
    FILE *fp = fopen(USER_FILE, "w");

    if (fp == NULL)
    {
        return;
    }

    for (i = 0; i < userarr->size; ++i)
    {
        fprintf(fp, "%s %s\n", userarr->userarray[i].name, userarr->userarray[i].passwd);
    }

    fclose(fp);
}

//从文件中读取管理员信息
void read_user_file(user *userarr)
{
    do
    {
        userarr->size = 0;
        memset(&userarr->userarray, 0, sizeof(userarr->userarray));
        FILE *fp = fopen(USER_FILE, "r");
        if (fp == NULL)
        {
            break;
        }

        while (fscanf(fp, "%s %s", &userarr->userarray[userarr->size].name,
                      &userarr->userarray[userarr->size].passwd) != EOF)
        {
            userarr->size++;
        }
    } while (0);
}

//打印菜单
void showMenu()
{
    printf("\033[34m-------------------------------------------\033[0m\n");
    printf("\033[35m请输入你要选择的编号：\033[0m\n");
    printf("\033[35m1、添加药品信息\033[0m\n");
    printf("\033[35m2、查看所有药品信息\033[0m\n");
    printf("\033[35m3、按编号删除药品信息\033[0m\n");
    printf("\033[35m4、按姓名删除药品信息\033[0m\n");
    printf("\033[35m5、按编号修改药品信息\033[0m\n");
    printf("\033[35m6、按姓名修改药品信息\033[0m\n");
    printf("\033[35m7、按编号查找药品信息\033[0m\n");
    printf("\033[35m8、按姓名查找药品信息\033[0m\n");
    printf("\033[35m9、按编号排序药品信息\033[0m\n");
    printf("\033[35m10、按姓名排序药品信息\033[0m\n");
    printf("\033[35m0、退出本系统\033[0m\n");
    printf("\033[34m-------------------------------------------\033[0m\n");
}

//从文件中读入药品信息
void read_medicine_file()
{
    FILE *fp = fopen(MEDICINE_FILE, "r");
    if (fp == NULL)
    {
        med.size = 0;
        memset(&med.medicine_array, 0, sizeof(med.medicine_array));
    }
    else
    {
        while (fscanf(fp, "%s%d%s%d%d%d", &med.medicine_array[med.size].drug_name,
                      &med.medicine_array[med.size].drug_number,
                      &med.medicine_array[med.size].drug_type,
                      &med.medicine_array[med.size].cost,
                      &med.medicine_array[med.size].price,
                      &med.medicine_array[med.size].num) != EOF)
        {
            med.size++;
        }
    }
}

//添加药品信息
void add_medicine()
{
    int flag = 0;
    int num; //保存编号用于去重
    printf("请输入你要添加的药品的数量\n");
    int n, i;
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    //姓名   |   编号   |   类型   |   成本   |   售价   |   数量
    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的信息\n", i + 1);
        printf("--------------------\n");
        printf("请输入药品姓名\n");
        scanf("%s", &med.medicine_array[med.size].drug_name);
        printf("请输入药品编号\n");
        med.medicine_array[med.size].drug_number = 0;
        do
        {
            scanf("%d", &num);
            int ret = drug_number_find(num);
            if (ret != -1)
            {
                printf("该编号已经存在，请重新输入\n");
            }
            else
            {
                med.medicine_array[med.size].drug_number = num;
                break;
            }
        } while (1);
        printf("请输入药品类型\n");
        scanf("%s", &med.medicine_array[med.size].drug_type);
        printf("请输入药品成本\n");
        scanf("%d", &med.medicine_array[med.size].cost);
        printf("请输入药品售价\n");
        scanf("%d", &med.medicine_array[med.size].price);
        printf("请输入药品数量\n");
        scanf("%d", &med.medicine_array[med.size].num);
        flag = 1;

        med.size++;
    }
    if (flag == 1)
        save_medicine(); //保存到文件
}

//查看所有药品信息
void show_medicine()
{
    printf("   姓名   |   编号   |   类型   |   成本   |   售价   |   数量\n");

    int i;
    for (i = 0; i < med.size; ++i)
    {
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[i].drug_name,
               med.medicine_array[i].drug_number,
               med.medicine_array[i].drug_type,
               med.medicine_array[i].cost,
               med.medicine_array[i].price,
               med.medicine_array[i].num);
    }
}

//按编号删除药品信息
void drug_number_del()
{
    int flag = 0;
    int i, j, n, number;

    printf("请输入你要删除的药品数量\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的编号\n", i + 1);
        printf("--------------------\n");
        printf("请输入要删除的药品编号\n");
        while (scanf("%d", &number) != 1)
        {
            printf("输入有误，请重新输入\n");
            rewind(stdin);
        }

        int ret = drug_number_find(number);
        if (ret != -1)
        {
            flag = 1;
            printf("删除成功，删除的信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            for (j = ret; j < med.size - 1; j++)
            {
                med.medicine_array[j] = med.medicine_array[j + 1];
            }
            med.size--;
        }
        else
        {
            printf("删除失败\n");
        }
    }

    if (flag == 1)
        save_medicine();
}

//按姓名删除药品信息
void drug_name_del()
{
    int flag = 0;
    int i, j, n;
    char name[100];

    printf("请输入你要删除的药品数量\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的姓名\n", i + 1);
        printf("--------------------\n");
        printf("请输入要删除的药品姓名\n");
        scanf("%s", name);

        int ret = drug_name_find(name);
        if (ret != -1)
        {
            flag = 1;
            printf("删除成功，删除的信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            for (j = ret; j < med.size - 1; j++)
            {
                med.medicine_array[j] = med.medicine_array[j + 1];
            }
            med.size--;
        }
        else
        {
            printf("删除失败\n");
        }
    }

    if (flag == 1)
        save_medicine();
}

//按编号修改药品信息
void drug_number_revise()
{
    int flag = 0;
    int i, j, n, number; //保存要修改的编号
    int num;             //保存新编号，用于去重

    printf("请输入你要修改的药品数量\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的编号\n", i + 1);
        printf("--------------------\n");
        printf("请输入要修改的药品编号\n");
        while (scanf("%d", &number) != 1)
        {
            printf("输入有误，请重新输入\n");
            rewind(stdin);
        }

        int ret = drug_number_find(number);
        if (ret != -1)
        {
            flag = 1;
            printf("找到该编号的药品，该药品信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            printf("请输入新信息\n");
            printf("请输入药品新姓名\n");
            scanf("%s", &med.medicine_array[ret].drug_name);
            printf("请输入药品编号\n");
            med.medicine_array[ret].drug_number = 0;
            do
            {
                scanf("%d", &num);
                int ret = drug_number_find(num);
                if (ret != -1)
                {
                    printf("该编号已经存在，请重新输入\n");
                }
                else
                {
                    med.medicine_array[ret].drug_number = num;
                    break;
                }
            } while (1);
            printf("请输入药品类型\n");
            scanf("%s", &med.medicine_array[ret].drug_type);
            printf("请输入药品成本\n");
            scanf("%d", &med.medicine_array[ret].cost);
            printf("请输入药品售价\n");
            scanf("%d", &med.medicine_array[ret].price);
            printf("请输入药品数量\n");
            scanf("%d", &med.medicine_array[ret].num);
            printf("修改成功！\n");
        }
        else
        {
            printf("未找到该编号的药品\n");
        }
    }

    if (flag == 1)
        save_medicine();
}

//按姓名修改药品信息
void drug_name_revise()
{
    int flag = 0;
    int i, j, n;
    char name[100];
    int num; //保存编号，用于去重

    printf("请输入你要修改的药品数量\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的姓名\n", i + 1);
        printf("--------------------\n");
        printf("请输入要修改的药品姓名\n");
        scanf("%s", &name);

        int ret = drug_name_find(name);
        if (ret != -1)
        {
            flag = 1;
            printf("找到该姓名的药品，该药品信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            printf("请输入新信息\n");
            printf("请输入药品新姓名\n");
            scanf("%s", &med.medicine_array[ret].drug_name);
            printf("请输入药品编号\n");
            med.medicine_array[ret].drug_number = 0;
            do
            {
                scanf("%d", &num);
                int ret = drug_number_find(num);
                if (ret != -1)
                {
                    printf("该编号已经存在，请重新输入\n");
                }
                else
                {
                    med.medicine_array[ret].drug_number = num;
                    break;
                }
            } while (1);
            printf("请输入药品类型\n");
            scanf("%s", &med.medicine_array[ret].drug_type);
            printf("请输入药品成本\n");
            scanf("%d", &med.medicine_array[ret].cost);
            printf("请输入药品售价\n");
            scanf("%d", &med.medicine_array[ret].price);
            printf("请输入药品数量\n");
            scanf("%d", &med.medicine_array[ret].num);
            printf("修改成功！\n");
        }
        else
        {
            printf("未找到该姓名的药品\n");
        }
    }

    if (flag == 1)
        save_medicine();
}

//按编号查找药品信息，返回下标
int drug_number_find(int number)
{
    int i;

    for (i = 0; i < med.size; ++i)
    {
        if (number == med.medicine_array[i].drug_number)
        {
            return i;
        }
    }

    return -1;
}

//输出查找到的药品信息
void show_drug_number_find()
{
    int number;

    printf("请输入要查找的编号编号\n");
    while (scanf("%d", &number) != 1)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    int ret = drug_number_find(number);

    if (ret == -1)
    {
        printf("未找到\n");
    }
    else
    {
        printf("找到了，信息为\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
               med.medicine_array[ret].drug_number,
               med.medicine_array[ret].drug_type,
               med.medicine_array[ret].cost,
               med.medicine_array[ret].price,
               med.medicine_array[ret].num);
    }
}

//按姓名查找药品信息
int drug_name_find(char *name)
{
    int i;

    for (i = 0; i < med.size; ++i)
    {
        if (strcmp(name, med.medicine_array[i].drug_name) == 0)
            return i;
    }

    return -1;
}

//按姓名查找药品信息，并将药品信息输出
void show_drug_name_find()
{
    char name[100];

    printf("请输入你要查找的药品姓名\n");
    scanf("%s", name);

    int ret = drug_name_find(name);
    if (ret == -1)
    {
        printf("未找到\n");
    }
    else
    {
        printf("找到了，药品信息为\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
               med.medicine_array[ret].drug_number,
               med.medicine_array[ret].drug_type,
               med.medicine_array[ret].cost,
               med.medicine_array[ret].price,
               med.medicine_array[ret].num);
    }
}

int cmp1(const void *a, const void *b) //升序
{
    return ((medicine *)a)->drug_number - ((medicine *)b)->drug_number;
}

int cmp2(const void *a, const void *b) //降序
{
    return ((medicine *)b)->drug_number - ((medicine *)a)->drug_number;
}

//按编号排序药品信息
void drug_number_sort()
{
    int select = 0;

    printf("1、升序         2、降序         0、退出\n");

    while (scanf("%d", &select) != 1 || select < 0 || select > 2)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    switch (select)
    {
    case 0:
        break;
    case 1:
        qsort(&med.medicine_array, med.size, sizeof(med.medicine_array[0]), cmp1);
        break;
    case 2:
        qsort(&med.medicine_array, med.size, sizeof(med.medicine_array[0]), cmp2);
        break;
    }

    save_medicine();
}

int cmp3(const void *a, const void *b)
{
    return (strcmp(((medicine *)a)->drug_name, ((medicine *)b)->drug_name) > 0);
}

int cmp4(const void *a, const void *b)
{
    return (strcmp(((medicine *)a)->drug_name, ((medicine *)b)->drug_name) <= 0);
}

//按姓名排序药品信息
void drug_name_sort()
{
    int select = 0;

    printf("1、升序         2、降序         0、退出\n");

    while (scanf("%d", &select) != 1 || select < 0 || select > 2)
    {
        printf("输入有误，请重新输入\n");
        rewind(stdin);
    }

    switch (select)
    {
    case 0:
        break;
    case 1:
        qsort(&med.medicine_array, med.size, sizeof(med.medicine_array[0]), cmp3);
        break;
    case 2:
        qsort(&med.medicine_array, med.size, sizeof(med.medicine_array[0]), cmp4);
        break;
    }

    save_medicine();
}

//保存药品信息到文件
void save_medicine()
{
    int i;
    FILE *fp = fopen(MEDICINE_FILE, "w");
    if (fp == NULL)
    {
        return;
    }

    for (i = 0; i < med.size; ++i)
    {
        fprintf(fp, "%s %d %s %d %d %d\n", med.medicine_array[i].drug_name,
                med.medicine_array[i].drug_number,
                med.medicine_array[i].drug_type,
                med.medicine_array[i].cost,
                med.medicine_array[i].price,
                med.medicine_array[i].num);
    }

    fclose(fp);
}