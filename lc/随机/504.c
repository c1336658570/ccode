/*
    七进制数
    返回字符串
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char * convertToBase7(int num);

int main(void) 
{
    char *p = convertToBase7(-10);
    printf("%s\n", p);
}

char * convertToBase7(int num){
    if (num == 0)
        return "0";
    char *arr = (char *)malloc(sizeof(char) *20);
    memset(arr, 0, sizeof(char) *20);
    char str[20];
    if (num < 0)
    {
        strcat(arr, "-");
        num = -num;
    }
    int i = 0;
    while (num)
    {
        str[i++] = num % 7 + '0';
        num /= 7;
    }
    for (i -= 1; i >= 0; i--)
    {
        strncat(arr, str+i, 1);
    }
    
    return arr;
}

char * convertToBase7(int num){
    if(num == 0) {
        return "0";
    }
    char* arr = (char*)calloc(12, sizeof(char));
    if(num < 0)
    {
        strcat(arr, "-");
    }
    num = abs(num);
    char str[12] = {0};
    int i = 0;
    while(num > 0) 
    {
        str[i++] = num % 7 + '0';
        num /= 7;
    }
    for(i -= 1; i >= 0; i--){
        strncat(arr, str+i, 1);
    }
    return arr;
}