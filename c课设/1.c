/*
    ҩƷ����ϵͳ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEDICINE_FILE_NAME "medicine.txt"

typedef struct medicine
{
    char drug_name[100]; //ҩƷ��
    int drug_number;     //ҩƷ���
    char drug_type[50];  //ҩƷ���ͣ���ҩ����ҩ��
    int cost;            //�ɱ�
    int price;           //�ۼ�
    int num;             //ҩƷʣ������
} medicine;

struct med
{
    medicine medicine_array[500]; //���ҩƷ������
    int size;                     //������ʹ�õĴ�С
} med;

void showMenu();                //��ӡ�˵�
void read_file();               //���ļ��ж���ҩƷ��Ϣ
void add_medicine();            //���ҩƷ��Ϣ
void show_medicine();           //�鿴����ҩƷ��Ϣ
void drug_number_del();         //�����ɾ��ҩƷ��Ϣ
void drug_name_del();           //������ɾ��ҩƷ��Ϣ
void drug_number_revise();      //������޸�ҩƷ��Ϣ
void drug_name_revise();        //�������޸�ҩƷ��Ϣ
int drug_number_find(int num);  //����Ų���ҩƷ��Ϣ�������±�
void show_drug_number_find();   //������ҵ���ҩƷ��Ϣ
int drug_name_find(char *name); //����������ҩƷ��Ϣ�������±�
void show_drug_name_find();     //����������ҩƷ��Ϣ������ҩƷ��Ϣ���
void drug_number_sort();        //���������ҩƷ��Ϣ
void drug_name_sort();          //����������ҩƷ��Ϣ
void save();                    //����ҩƷ��Ϣ���ļ�

int main(int argc, char *argv[])
{
    int select = 15;

    read_file(); //��ȡ�ļ��е���Ϣ

    while (1)
    {
        showMenu(); //��ӡ�˵�
        while (scanf("%d", &select) != 1)
        {
            printf("������������������\n");
            rewind(stdin); //������ָ�������������ײ�
        }

        switch (select)
        {
        case 0:
            //�˳�����
            exit(0);
            break;
        case 1:
            //���ҩƷ��Ϣ
            add_medicine();
            break;
        case 2:
            //�鿴����ҩƷ��Ϣ
            show_medicine();
            break;
        case 3:
            //�����ɾ��ҩƷ��Ϣ
            drug_number_del();
            break;
        case 4:
            //������ɾ��ҩƷ��Ϣ
            drug_name_del();
            break;
        case 5:
            //������޸�ҩƷ��Ϣ
            drug_number_revise();
            break;
        case 6:
            //�������޸�ҩƷ��Ϣ
            drug_name_revise();
            break;
        case 7:
            //����Ų���ҩƷ��Ϣ������ҩƷ��Ϣ���
            show_drug_number_find();
            break;
        case 8:
            //����������ҩƷ��Ϣ������ҩƷ��Ϣ���
            show_drug_name_find();
            break;
        case 9:
            //���������ҩƷ��Ϣ
            drug_number_sort();
            break;
        case 10:
            //����������ҩƷ��Ϣ
            drug_name_sort();
            break;
        }
    }

    return 0;
}

//��ӡ�˵�
void showMenu()
{
    printf("-------------------------------------------\n");
    printf("��ӭʹ��ҩƷ����ϵͳ��\n");
    printf("��������Ҫѡ��ı�ţ�\n");
    printf("1�����ҩƷ��Ϣ\n");
    printf("2���鿴����ҩƷ��Ϣ\n");
    printf("3�������ɾ��ҩƷ��Ϣ\n");
    printf("4��������ɾ��ҩƷ��Ϣ\n");
    printf("5��������޸�ҩƷ��Ϣ\n");
    printf("6���������޸�ҩƷ��Ϣ\n");
    printf("7������Ų���ҩƷ��Ϣ\n");
    printf("8������������ҩƷ��Ϣ\n");
    printf("9�����������ҩƷ��Ϣ\n");
    printf("10������������ҩƷ��Ϣ\n");
    printf("0���˳���ϵͳ\n");
    printf("-------------------------------------------\n");
}

//���ļ��ж���ҩƷ��Ϣ
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

//���ҩƷ��Ϣ
void add_medicine()
{
    int flag = 0;
    int num; //����������ȥ��
    printf("��������Ҫ��ӵ�ҩƷ������\n");
    int n, i;
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    //����   |   ���   |   ����   |   �ɱ�   |   �ۼ�   |   ����
    for (i = 0; i < n; ++i)
    {
        printf("��%d��ҩƷ����Ϣ\n", i + 1);
        printf("--------------------\n");
        printf("������ҩƷ����\n");
        scanf("%s", &med.medicine_array[med.size].drug_name);
        printf("������ҩƷ���\n");
        med.medicine_array[med.size].drug_number = 0;
        do
        {
            scanf("%d", &num);
            int ret = drug_number_find(num);
            if (ret != -1)
            {
                printf("�ñ���Ѿ����ڣ�����������\n");
            }
            else
            {
                med.medicine_array[med.size].drug_number = num;
                break;
            }
        } while (1);
        printf("������ҩƷ����\n");
        scanf("%s", &med.medicine_array[med.size].drug_type);
        printf("������ҩƷ�ɱ�\n");
        scanf("%d", &med.medicine_array[med.size].cost);
        printf("������ҩƷ�ۼ�\n");
        scanf("%d", &med.medicine_array[med.size].price);
        printf("������ҩƷ����\n");
        scanf("%d", &med.medicine_array[med.size].num);
        flag = 1;

        med.size++;
    }
    if (flag == 1)
        save(); //���浽�ļ�
}

//�鿴����ҩƷ��Ϣ
void show_medicine()
{
    printf("   ����   |   ���   |   ����   |   �ɱ�   |   �ۼ�   |   ����\n");

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

//�����ɾ��ҩƷ��Ϣ
void drug_number_del()
{
    int flag = 0;
    int i, j, n, number;

    printf("��������Ҫɾ����ҩƷ����\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("��%d��ҩƷ�ı��\n", i + 1);
        printf("--------------------\n");
        printf("������Ҫɾ����ҩƷ���\n");
        while (scanf("%d", &number) != 1)
        {
            printf("������������������\n");
            rewind(stdin);
        }

        int ret = drug_number_find(number);
        if (ret != -1)
        {
            flag = 1;
            printf("ɾ���ɹ���ɾ������ϢΪ\n");
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
            printf("ɾ��ʧ��\n");
        }
    }

    if (flag == 1)
        save();
}

//������ɾ��ҩƷ��Ϣ
void drug_name_del()
{
    int flag = 0;
    int i, j, n;
    char name[100];

    printf("��������Ҫɾ����ҩƷ����\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("��%d��ҩƷ������\n", i + 1);
        printf("--------------------\n");
        printf("������Ҫɾ����ҩƷ����\n");
        scanf("%s", name);

        int ret = drug_name_find(name);
        if (ret != -1)
        {
            flag = 1;
            printf("ɾ���ɹ���ɾ������ϢΪ\n");
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
            printf("ɾ��ʧ��\n");
        }
    }

    if (flag == 1)
        save();
}

//������޸�ҩƷ��Ϣ
void drug_number_revise()
{
    int flag = 0;
    int i, j, n, number; //����Ҫ�޸ĵı��
    int num;             //�����±�ţ�����ȥ��

    printf("��������Ҫ�޸ĵ�ҩƷ����\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("��%d��ҩƷ�ı��\n", i + 1);
        printf("--------------------\n");
        printf("������Ҫ�޸ĵ�ҩƷ���\n");
        while (scanf("%d", &number) != 1)
        {
            printf("������������������\n");
            rewind(stdin);
        }

        int ret = drug_number_find(number);
        if (ret != -1)
        {
            flag = 1;
            printf("�ҵ��ñ�ŵ�ҩƷ����ҩƷ��ϢΪ\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            printf("����������Ϣ\n");
            printf("������ҩƷ������\n");
            scanf("%s", &med.medicine_array[ret].drug_name);
            printf("������ҩƷ���\n");
            med.medicine_array[ret].drug_number = 0;
            do
            {
                scanf("%d", &num);
                int ret = drug_number_find(num);
                if (ret != -1)
                {
                    printf("�ñ���Ѿ����ڣ�����������\n");
                }
                else
                {
                    med.medicine_array[ret].drug_number = num;
                    break;
                }
            } while (1);
            printf("������ҩƷ����\n");
            scanf("%s", &med.medicine_array[ret].drug_type);
            printf("������ҩƷ�ɱ�\n");
            scanf("%d", &med.medicine_array[ret].cost);
            printf("������ҩƷ�ۼ�\n");
            scanf("%d", &med.medicine_array[ret].price);
            printf("������ҩƷ����\n");
            scanf("%d", &med.medicine_array[ret].num);
            printf("�޸ĳɹ���\n");
        }
        else
        {
            printf("δ�ҵ��ñ�ŵ�ҩƷ\n");
        }
    }

    if (flag == 1)
        save();
}

//�������޸�ҩƷ��Ϣ
void drug_name_revise()
{
    int flag = 0;
    int i, j, n;
    char name[100];
    int num; //�����ţ�����ȥ��

    printf("��������Ҫ�޸ĵ�ҩƷ����\n");
    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    for (i = 0; i < n; ++i)
    {
        printf("��%d��ҩƷ������\n", i + 1);
        printf("--------------------\n");
        printf("������Ҫ�޸ĵ�ҩƷ����\n");
        scanf("%s", &name);

        int ret = drug_name_find(name);
        if (ret != -1)
        {
            flag = 1;
            printf("�ҵ���������ҩƷ����ҩƷ��ϢΪ\n");
            printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
                   med.medicine_array[ret].drug_number,
                   med.medicine_array[ret].drug_type,
                   med.medicine_array[ret].cost,
                   med.medicine_array[ret].price,
                   med.medicine_array[ret].num);
            printf("����������Ϣ\n");
            printf("������ҩƷ������\n");
            scanf("%s", &med.medicine_array[ret].drug_name);
            printf("������ҩƷ���\n");
            med.medicine_array[ret].drug_number = 0;
            do
            {
                scanf("%d", &num);
                int ret = drug_number_find(num);
                if (ret != -1)
                {
                    printf("�ñ���Ѿ����ڣ�����������\n");
                }
                else
                {
                    med.medicine_array[ret].drug_number = num;
                    break;
                }
            } while (1);
            printf("������ҩƷ����\n");
            scanf("%s", &med.medicine_array[ret].drug_type);
            printf("������ҩƷ�ɱ�\n");
            scanf("%d", &med.medicine_array[ret].cost);
            printf("������ҩƷ�ۼ�\n");
            scanf("%d", &med.medicine_array[ret].price);
            printf("������ҩƷ����\n");
            scanf("%d", &med.medicine_array[ret].num);
            printf("�޸ĳɹ���\n");
        }
        else
        {
            printf("δ�ҵ���������ҩƷ\n");
        }
    }

    if (flag == 1)
        save();
}

//����Ų���ҩƷ��Ϣ�������±�
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

//������ҵ���ҩƷ��Ϣ
void show_drug_number_find()
{
    int number;

    printf("������Ҫ���ҵı�ű��\n");
    while (scanf("%d", &number) != 1)
    {
        printf("������������������\n");
        rewind(stdin);
    }

    int ret = drug_number_find(number);

    if (ret == -1)
    {
        printf("δ�ҵ�\n");
    }
    else
    {
        printf("�ҵ��ˣ���ϢΪ\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
               med.medicine_array[ret].drug_number,
               med.medicine_array[ret].drug_type,
               med.medicine_array[ret].cost,
               med.medicine_array[ret].price,
               med.medicine_array[ret].num);
    }
}

//����������ҩƷ��Ϣ
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

//����������ҩƷ��Ϣ������ҩƷ��Ϣ���
void show_drug_name_find()
{
    char name[100];

    printf("��������Ҫ���ҵ�ҩƷ����\n");
    scanf("%s", name);

    int ret = drug_name_find(name);
    if (ret == -1)
    {
        printf("δ�ҵ�\n");
    }
    else
    {
        printf("�ҵ��ˣ�ҩƷ��ϢΪ\n");
        printf("%-11s%-11d%-11s%-11d%-11d%-11d\n", med.medicine_array[ret].drug_name,
               med.medicine_array[ret].drug_number,
               med.medicine_array[ret].drug_type,
               med.medicine_array[ret].cost,
               med.medicine_array[ret].price,
               med.medicine_array[ret].num);
    }
}

//���������ҩƷ��Ϣ
void drug_number_sort()
{
}

//����������ҩƷ��Ϣ
void drug_name_sort()
{
}

//����ҩƷ��Ϣ���ļ�
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