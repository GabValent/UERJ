#include <stdio.h>

void bolha (int vet[])
{
	int k, l, aux; 
for(k=1; k<10; k++)
	{
		for(l=0; l<9; l++)
		{
			if (vet[l]> vet[l+1])
			{
				aux = vet[l];
				vet[l] = vet[l+1];
				vet[l+1] = aux;
			}
		}
	}
}

void printa(int vet[])
{
	int a;
	for(a=0; a<10; a++)
	{
	printf("%d ", vet[a]);
	}
	
	printf("\n");

}

int main()
{
	int i,j, v1[10], v2[10], v3[10];
	for(i=0;i<10; i++)
	{
		v1[i] = '\0';
		v2[i] = '\0';
		v3[i] = '\0';
	}
	
		for(i=0; i<10; i++)
		{
		printf("Digite para o primeiro vetor");
		scanf("%d", &v1[i]);
		}
		
		for(i=0; i<10; i++)
		{
		printf("Digite para o segundo vetor");
		scanf("%d", &v2[i]);
		}
		
		for(i=0; i<10; i++)
		{
		printf("Digite para o terceiro vetor");
		scanf("%d", &v3[i]);
		}

	
	bolha(v1);
	bolha(v2);	
	bolha(v3);	
	printa(v1);
	printa(v2);
	printa(v3);
	
	
	
return 0;
}
