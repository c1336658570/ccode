# include <stdio.h>
# include <ctype.h>
 
int main(void)
{
	int guess = 50 ;
	int upper = 100 ;
	int lower = 0 ;
	char ch ;
 
	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a y if my guess is right and with\n");
	printf("an n if it is wrong.\n");
	printf("Uh...is your number %d?\n" , guess);
 
	while ((ch = getchar()))
	{
		if (!isalpha(ch))
			continue ;		//不是字母,进入下一次循环
 
		while (getchar() != '\n') ;	//丢掉后面所有字符
 
		if (tolower(ch) == 'y')
			break ;			//猜对了,退出循环
		
		printf("OK , the number you chosen is bigger or smaller than i guest?(b/s): ");
		while((ch = getchar()))
		{
			if (!isalpha(ch))
				continue ;

			while(getchar() != '\n') ;
 
			switch (tolower(ch))
			{
				case 'b' :	//猜大了就缩小一半
					upper = guess ;
					guess -= ((upper - lower) / 2) ;
					break ;
				case 's' :	//猜笑了就增加一半
					lower = guess ;
					guess += ((upper - lower) / 2) ;
					break ;
				default :	//回答不正确,再次询问
					printf("Invalid choice,the number" 
							" you chosen is bigger or smaller "
							"than i guest?(b/s): ");
					continue ;
			}
			break ;			//退出询问大小
		}
						//再次猜一个数;
		printf("Well, then , is it %d?(y/n)\n" , guess);
	}
	printf("I knew I could do it!\n");
 
	return 0 ;
} 