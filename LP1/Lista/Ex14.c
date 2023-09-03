#include <stdio.h>

int main()
{
	int h=0,m=0,s=0;
	
	while(h<24)
	{
		printf("%d : %d : %d\n", h, m, s);
		s++;
		if(s>=60)
		{
			m++;
			s=0;
			if(m>=60)
			{
				h++;
				m=0;
				s=0;
				if(h>=24)
				{
					h=0;
					m=0;
					s=0;
					printf("%d : %d : %d\n", h, m, s);
					break;
					
				}
			}
		}
	}
	
	return 0;
	
}
