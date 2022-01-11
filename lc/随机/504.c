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

void reverse(char *s)//字符串反转函数
{
    int i,len=strlen(s);
    char t;
    for(i=0;i<len/2;i++)
    {
        t=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=t;
    }
}
char * convertToBase7(int num)
{
    char *ans=(char*)malloc(sizeof(char)*1000);
    if(num==0)
    {
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }
    int flag=1,k=0;
    if(num<0)
    {
        flag=0;
        num=-num;
    }
    while(num)
    {
        ans[k++]=num%7+'0';
        num/=7;
    }
    ans[k]='\0';
    if(flag==0)
        strcat(ans,"-");
    reverse(ans);
    return ans;
}