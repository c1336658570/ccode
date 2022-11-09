#include <stdio.h>
#include <string.h>

/*
出题人：楚梦凡
考点：大小端，二维数组的存储方式，按行还是按列，strcpy和strcat两个函数使用
*/

//解释程序输出
int main(int argc, char **argv)
{
    int data[2][3] = {{0X636c6557, 0X20656d6f, 0X78206f74},
                      {0X756f7969, 0X6e694c20, 0x00000000}};
    int data2[] = {0X67207875, 0X70756f72, 0X32303220, 0X00000a32};

    char *a = (char *)data;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);

    printf("%s\n", buf);

    return 0;
}