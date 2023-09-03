#include <stdio.h>

int main()
{
	int perf=0, i=1, soma=0;
	
	printf("Digite um numero:");
	
	scanf("%d", &perf);
	
	for(i; i<perf; i++)
	{
		
		if ((perf%i) == 0) 
		{
			soma = soma + i;
		}
		
	}
	
	printf("Soma: %d", soma);
	printf("Perf: %d", perf);
	
	if (soma == perf)
	{
		printf("E perfeito");
	}
	else
	{
		printf("Nao e perfeito");
	}
	
	return 0;
}
