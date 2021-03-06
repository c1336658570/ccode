/*
    strncmp
    输出：
        Found: astronomy
        Found: astrophysics
        Found: astrophobia
        The list contained 3 words beginning whth astro.
*/
# include <stdio.h>
# include <string.h>
# define LISTSIZE 6

int main(void)
{
    const char * list[LISTSIZE] = 
    {
        "astronomy", "astounding",
        "astrophysics", "ostracize",
        "asterism", "astrophobia"
    };
    int count = 0;
    int i;

    for (i = 0; i < LISTSIZE; ++i)
    {
        if (strncmp(list[i], "astro", 5) == 0)
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    }
    printf("The list contained %d words beginning"
            " whth astro.\n", count);

    return 0 ;
}