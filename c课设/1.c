/*
    药品管理系统
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEDICINE_FILE_NAME "medicine.txt"

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

void showMenu();                //打印菜单
void read_file();               //从文件中读入药品信息
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
void save();                    //保存药品信息到文件

int main(int argc, char *argv[])
{
    int select = 15;

    read_file(); //读取文件中的信息

    while (1)
    {
        showMenu(); //打印菜单
        while (scanf("%d", &select) != 1)
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

//打印菜单
void showMenu()
{
    printf("-------------------------------------------\n");
    printf("欢迎使用药品管理系统！\n");
    printf("请输入你要选择的编号：\n");
    printf("1、添加药品信息\n");
    printf("2、查看所有药品信息\n");
    printf("3、按编号删除药品信息\n");
    printf("4、按姓名删除药品信息\n");
    printf("5、按编号修改药品信息\n");
    printf("6、按姓名修改药品信息\n");
    printf("7、按编号查找药品信息\n");
    printf("8、按姓名查找药品信息\n");
    printf("9、按编号排序药品信息\n");
    printf("10、按姓名排序药品信息\n");
    printf("0、退出本系统\n");
    printf("-------------------------------------------\n");
}

//从文件中读入药品信息
void read_file()
{
    FILE *fp = fopen(MEDICINE_FILE_NAME, "r");
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
        save(); //保存到文件
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
        save();
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
        save();
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
        save();
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
        save();
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

//按编号排序药品信息
void drug_number_sort()
{
}

//按姓名排序药品信息
void drug_name_sort()
{
}

//保存药品信息到文件
void save()
{
    int i;
    FILE *fp = fopen(MEDICINE_FILE_NAME, "w");
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
}