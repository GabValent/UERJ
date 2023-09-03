#include <stdio.h>

int main()
{
	int aux=0, i, j=0;
	int vet[10];
	
	for(i=0; i<10; i++)
	{
		printf("Digite um numero: ");
		scanf("%d", &vet[i]);	
	}
	
	for(i=1; i<10; i++)
	{
		for(j; j<9; j++)
		{
			if (vet[j]> vet[j+1])
			{
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
	printf("O maior elemento do vetor: %d\n O segundo maior elemento: %d",vet[9],vet[8]);
	
	return 0;
}
