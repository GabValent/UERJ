#include <stdio.h>

int main()
{
	int i;
	i = 1;
	
	int achou;
	achou = 0;
	
	while(achou == 0)
	{
		if ((i%3 == 2) && (i%5 == 3) && (i%7 == 4))
		{
			achou = 1;
		}
		else
		{
			i = i + 1;
	    }
	}
	printf("%d", i);
	
	return 0;
}
