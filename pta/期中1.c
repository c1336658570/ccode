/*
	打印 
       *
      ***
     *****
    *******
     *****
      ***
       *
*/
# include <stdio.h>

int main(void)
{
	int i, j;
	
	for (i=1; i<5; ++i)
	{
		for (j=0; j<6-i; ++j)
		{
			printf(" ");
		}
		
		for (j=0; j<2*i-1; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for (i=1; i<4; ++i)
	{
		for (j=5; j>3-i; --j)
		{
			printf(" ");
		}
		
		for (j=5;j>+2*i-2; --j)
		{
			printf("*");
		}
		if (i == 3)
			break;
		printf("\n");
	}
	
	return 0;
 } 
