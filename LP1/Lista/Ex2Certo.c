#include <stdio.h>

int main()
{
	int cont = 0, i = 2, num;
	
	printf("Digite um Numero: ");
	scanf("%d", &num);
	
	while (i<num)
	{
		if(num%i == 0)
		{
			cont = cont + 1;
		}
		i++;
		
	}
	if(cont == 0)
	{
		printf("E Primo");	
	}
	else
	{
		printf("Nao e primo");
	}
	return 0;
}
