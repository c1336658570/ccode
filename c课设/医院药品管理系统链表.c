/*
    药品管理系统
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEDICINE_FILE "medicine.txt" //药品文件名
#define USER_FILE "user.txt"         //管理员文件

typedef struct medicine
{
    char drug_name[100]; //药品名
    int drug_number;     //药品编号
    char drug_type[50];  //药品类型（中药，西药）
    int cost;            //成本
    int price;           //售价
    int num;             //药品剩余数量
    struct medicine *next;
} medicine;

medicine *head; //定义头指针

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
void showMenu();                      //打印菜单
void read_medicine_file();            //从文件中读入药品信息
void add_medicine();                  //添加药品信息
void show_medicine();                 //查看所有药品信息
void drug_number_del();               //按编号删除药品信息
void drug_name_del();                 //按姓名删除药品信息
void drug_number_revise();            //按编号修改药品信息
void drug_name_revise();              //按姓名修改药品信息
medicine *drug_number_find(int num);  //按编号查找药品信息，返回下标
void show_drug_number_find();         //输出查找到的药品信息
medicine *drug_name_find(char *name); //按姓名查找药品信息，返回下标
void show_drug_name_find();           //按姓名查找药品信息，并将药品信息输出
void drug_number_sort();              //按编号排序药品信息
void drug_name_sort();                //按姓名排序药品信息
void save_medicine();                 //保存药品信息到文件

int main(int argc, char *argv[])
{
    int select = 15;
    user userarr;
    head = (medicine *)malloc(sizeof(medicine));
    head->next = NULL;

    read_user_file(&userarr); //从文件读管理员信息

    login_menu(&userarr); //登录账号菜单

    read_medicine_file(); //读取文件中药品的信息

    while (1)
    {
        showMenu(); //打印菜单
        while (scanf("%d", &select) != 1 || select < 0 || select > 10)
        {
            printf("输入有误，请重新输入\n");
            scanf("%*[^\n]%*c"); //将输入指针置于输入流首部
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
            scanf("%*[^\n]%*c");
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
            revise_passwd(userarr); //修改密码
            break;
        case 4:
            get_passwd(userarr); //找回密码
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

    printf("\033[35m你有5次登录机会！\033[0m\n");
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
        printf("\033[35m第%d次登录失败\033[0m\n", j + 1);
    }

    return false;
}

//修改密码
void revise_passwd(user *userarr)
{
    char name[50], passwd[50];
    int i;

    printf("请输入你要修改的姓名\n");

    scanf("%s", name);

    printf("请输入原密码\n");
    scanf("%s", passwd);

    for (i = 0; i < userarr->size; ++i)
    {
        if (strcmp(name, userarr->userarray[i].name) == 0 && strcmp(passwd, userarr->userarray[i].passwd) == 0)
        {
            printf("请输入新密码\n");
            scanf("%s", userarr->userarray[i].passwd);
            printf("修改成功\n");
            save_user(userarr);
            return;
        }
    }
    printf("账号或密码错误\n");
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

        while (fscanf(fp, "%s %s", userarr->userarray[userarr->size].name,
                      userarr->userarray[userarr->size].passwd) != EOF)
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
        return;
    }
    else
    {
        medicine *p = head;
        while (1)
        {
            medicine *pNew = (medicine *)malloc(sizeof(medicine));
            pNew->next = NULL;
            if (fscanf(fp, "%s%d%s%d%d%d", pNew->drug_name,
                       &pNew->drug_number,
                       pNew->drug_type,
                       &pNew->cost,
                       &pNew->price,
                       &pNew->num) != EOF)
            {
                p->next = pNew;
                p = pNew;
            }
            else
            {
                free(pNew);
                break;
            }
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
        scanf("%*[^\n]%*c");
    }

    //姓名   |   编号   |   类型   |   成本   |   售价   |   数量
    medicine *p, *q;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    for (i = 0; i < n; ++i)
    {
        q = (medicine *)malloc(sizeof(medicine));
        printf("第%d个药品的信息\n", i + 1);
        printf("--------------------\n");
        printf("请输入药品姓名\n");
        scanf("%s", q->drug_name);
        printf("请输入药品编号\n");
        q->drug_number = 0;
        do
        {
            while (scanf("%d", &num) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
            medicine *ret = drug_number_find(num);
            if (ret != NULL)
            {
                printf("该编号已经存在，请重新输入\n");
            }
            else
            {
                q->drug_number = num;
                break;
            }
        } while (1);
        printf("请输入药品类型\n");
        scanf("%s", q->drug_type);
        printf("请输入药品成本\n");
        while (scanf("%d", &q->cost) != 1)
        {
            printf("输入有误，请重新输入!\n");
            scanf("%*[^\n]%*c");
        }
        printf("请输入药品售价\n");
        while (scanf("%d", &q->price) != 1)
        {
            printf("输入有误，请重新输入!\n");
            scanf("%*[^\n]%*c");
        }
        printf("请输入药品数量\n");
        while (scanf("%d", &q->num) != 1)
        {
            printf("输入有误，请重新输入!\n");
            scanf("%*[^\n]%*c");
        }
        flag = 1;

        p->next = q;
        p = q;
        q->next = NULL;
    }
    if (flag == 1)
        save_medicine(); //保存到文件
}

//查看所有药品信息
void show_medicine()
{
    printf("   姓名   |   编号   |   类型   |   成本   |   售价   |   数量\n");

    medicine *p = head->next;
    while (p != NULL)
    {
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", p->drug_name,
               p->drug_number,
               p->drug_type,
               p->cost,
               p->price,
               p->num);
        p = p->next;
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
        scanf("%*[^\n]%*c");
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的编号\n", i + 1);
        printf("--------------------\n");
        printf("请输入要删除的药品编号\n");
        while (scanf("%d", &number) != 1)
        {
            printf("输入有误，请重新输入\n");
            scanf("%*[^\n]%*c");
        }

        medicine *ret = drug_number_find(number);
        if (ret != NULL)
        {
            medicine *p = head;
            while (p->next->drug_number != number)
            {
                p = p->next;
            }

            flag = 1;
            printf("删除成功，删除的信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
                   ret->drug_number,
                   ret->drug_type,
                   ret->cost,
                   ret->price,
                   ret->num);

            p->next = p->next->next;
            free(ret);
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
        scanf("%*[^\n]%*c");
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的姓名\n", i + 1);
        printf("--------------------\n");
        printf("请输入要删除的药品姓名\n");
        scanf("%s", name);

        medicine *ret = drug_name_find(name);
        if (ret != NULL)
        {
            medicine *p = head;
            while (strcmp(p->next->drug_name, name) != 0)
            {
                p = p->next;
            }
            flag = 1;
            printf("删除成功，删除的信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
                   ret->drug_number,
                   ret->drug_type,
                   ret->cost,
                   ret->price,
                   ret->num);

            p->next = ret->next;
            free(ret);
        }
        else
        {
            printf("未找到该药品，删除失败\n");
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
        scanf("%*[^\n]%*c");
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的编号\n", i + 1);
        printf("--------------------\n");
        printf("请输入要修改的药品编号\n");
        while (scanf("%d", &number) != 1)
        {
            printf("输入有误，请重新输入\n");
            scanf("%*[^\n]%*c");
        }

        medicine *ret = drug_number_find(number);
        if (ret != NULL)
        {
            flag = 1;
            printf("找到该编号的药品，该药品信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
                   ret->drug_number,
                   ret->drug_type,
                   ret->cost,
                   ret->price,
                   ret->num);
            printf("请输入新信息\n");
            printf("请输入药品新姓名\n");
            scanf("%s", ret->drug_name);
            printf("请输入药品编号\n");
            ret->drug_number = -1; //将该药品编号改为-1防止新输入的编号和当前编号相同，导致无法成功输入该编号
            do
            {
                while (scanf("%d", &num) != 1)
                {
                    printf("输入有误，请重新输入!\n");
                    scanf("%*[^\n]%*c");
                }
                medicine *res = drug_number_find(num);
                if (res != NULL)
                {
                    printf("该编号已经存在，请重新输入\n");
                }
                else
                {
                    ret->drug_number = num;
                    break;
                }
            } while (1);
            printf("请输入药品类型\n");
            scanf("%s", ret->drug_type);
            printf("请输入药品成本\n");
            while (scanf("%d", &ret->cost) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
            printf("请输入药品售价\n");
            while (scanf("%d", &ret->price) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
            printf("请输入药品数量\n");
            while (scanf("%d", &ret->num) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
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
        scanf("%*[^\n]%*c");
    }

    for (i = 0; i < n; ++i)
    {
        printf("第%d个药品的姓名\n", i + 1);
        printf("--------------------\n");
        printf("请输入要修改的药品姓名\n");
        scanf("%s", name);

        medicine *ret = drug_name_find(name);
        if (ret != NULL)
        {
            flag = 1;
            printf("找到该姓名的药品，该药品信息为\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
                   ret->drug_number,
                   ret->drug_type,
                   ret->cost,
                   ret->price,
                   ret->num);
            printf("请输入新信息\n");
            printf("请输入药品新姓名\n");
            scanf("%s", ret->drug_name);
            printf("请输入药品编号\n");
            ret->drug_number = 0;
            do
            {
                while (scanf("%d", &num) != 1)
                {
                    printf("输入有误，请重新输入!\n");
                    scanf("%*[^\n]%*c");
                }
                medicine *res = drug_number_find(num);
                if (res != NULL)
                {
                    printf("该编号已经存在，请重新输入\n");
                }
                else
                {
                    ret->drug_number = num;
                    break;
                }
            } while (1);
            printf("请输入药品类型\n");
            scanf("%s", ret->drug_type);

            printf("请输入药品成本\n");
            while (scanf("%d", &ret->cost) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
            printf("请输入药品售价\n");
            while (scanf("%d", &ret->price) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
            printf("请输入药品数量\n");
            while (scanf("%d", &ret->num) != 1)
            {
                printf("输入有误，请重新输入!\n");
                scanf("%*[^\n]%*c");
            }
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
medicine *drug_number_find(int number)
{
    medicine *p;
    p = head->next;

    while (p != NULL)
    {
        if (p->drug_number == number)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

//输出查找到的药品信息
void show_drug_number_find()
{
    int number;

    printf("请输入要查找的编号编号\n");
    while (scanf("%d", &number) != 1)
    {
        printf("输入有误，请重新输入\n");
        scanf("%*[^\n]%*c");
    }

    medicine *ret = drug_number_find(number);

    if (ret == NULL)
    {
        printf("未找到\n");
    }
    else
    {
        printf("找到了，信息为\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
               ret->drug_number,
               ret->drug_type,
               ret->cost,
               ret->price,
               ret->num);
    }
}

//按姓名查找药品信息
medicine *drug_name_find(char *name)
{
    medicine *p, *q;
    p = head->next;

    while (p != NULL)
    {
        if (strcmp(name, p->drug_name) == 0)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

//按姓名查找药品信息，并将药品信息输出
void show_drug_name_find()
{
    char name[100];

    printf("请输入你要查找的药品姓名\n");
    scanf("%s", name);

    medicine *ret = drug_name_find(name);
    if (ret == NULL)
    {
        printf("未找到\n");
    }
    else
    {
        printf("找到了，药品信息为\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", ret->drug_name,
               ret->drug_number,
               ret->drug_type,
               ret->cost,
               ret->price,
               ret->num);
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
        scanf("%*[^\n]%*c");
    }

    int i, count = 0, num;
    medicine *p, *q, *tail;
    p = head;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    for (i = 0; i < count - 1; i++)
    {
        num = count - i - 1;
        q = head->next;
        p = q->next;
        tail = head;
        while (num--)
        {
            if (select == 1)
            {
                if (q->drug_number > p->drug_number)
                {
                    q->next = p->next;
                    p->next = q;
                    tail->next = p;
                }
            }
            else if (select == 2)
            {
                if (q->drug_number < p->drug_number)
                {
                    q->next = p->next;
                    p->next = q;
                    tail->next = p;
                }
            }
            tail = tail->next;
            q = tail->next;
            p = q->next;
        }
    }

    save_medicine();
}

//按姓名排序药品信息
void drug_name_sort()
{
    int select = 0;

    printf("1、升序         2、降序         0、退出\n");

    while (scanf("%d", &select) != 1 || select < 0 || select > 2)
    {
        printf("输入有误，请重新输入\n");
        scanf("%*[^\n]%*c");
    }

    int i, count = 0, num;
    medicine *p, *q, *tail;
    p = head;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    for (i = 0; i < count - 1; i++)
    {
        num = count - i - 1;
        q = head->next;
        p = q->next;
        tail = head;
        while (num--)
        {
            if (select == 1)
            {
                if (strcmp(q->drug_name, p->drug_name) > 0)
                {
                    q->next = p->next;
                    p->next = q;
                    tail->next = p;
                }
            }
            else if (select == 2)
            {
                if (strcmp(q->drug_name, p->drug_name) < 0)
                {
                    q->next = p->next;
                    p->next = q;
                    tail->next = p;
                }
            }
            tail = tail->next;
            q = tail->next;
            p = q->next;
        }
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

    medicine *p = head->next;

    while (p != NULL)
    {
        fprintf(fp, "%s %d %s %d %d %d\n", p->drug_name,
                p->drug_number,
                p->drug_type,
                p->cost,
                p->price,
                p->num);

        p = p->next;
    }

    fclose(fp);
}