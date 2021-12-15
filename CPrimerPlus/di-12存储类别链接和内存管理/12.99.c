# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, i;
    scanf("%d", &n);
    char b[100];
    char **str = (char **)malloc(sizeof(char *) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", b);
        str[i] = (char *)malloc(strlen(b) + 1);
        strcpy(str[i], b);
        printf("%s\n", str[i]);
    }

    return 0;
}