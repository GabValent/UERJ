#include <stdio.h>

int fat (int num);

int main()
{
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num );
	
	printf("Fatorial e: %d", fat(num) );
	
	return 0;
	
}

int fat( int num)
{
	int resul;
	
	if (num == 0)
	{
		resul = 1;
		return(resul);
	}
	else
	{
		resul = num*fat(num-1);
		return(resul); 
	}
		
}
