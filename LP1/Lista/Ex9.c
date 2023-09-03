#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, total=0;
	char vet [80];
	char vet2 [80];
	
	for(i;i<80; i++)
	{
		vet[i] = '\0';
	}
	
	printf("Digite ate 80 caracteres:");
	gets(vet);
	
	for(i=0; vet[i] != '\0'; i++)
	{
		if(vet[i] != ' ')
		{
			char aux = vet[i];
			for(j=i+1; vet[j] != '\0'; j++ )
			{
				if(aux == vet[j])
				{
					vet[j] = '0';
				}
			}
			
		}
	}
	for(i=0; vet[i] != '\0'; i++)
	{
		if (vet[i] != '0' && vet[i] != ' ')
		{
			total++;
		}
		
	}

	printf("Total de letras distintas: %d", total);
	
	
	
return 0;
}
