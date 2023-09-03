#include <stdio.h>
#include <string.h>


void limpa(char v[])
{
	int k;
	for( k=0; k<50; k++)
	{
		v[k] = '\0';
	}
}


int main()
{
	int i, j, cont=1, conta=0, cont2=0, contv=0;
	char vet[50], aux[50];
	
	
	limpa(vet);
	limpa(aux);
	
	printf("Digite uma palavra:");
	gets(vet);
	
	for(i=0; vet[i] != '\0'; i++)
	{
		if(vet[i] == ' ' && vet[i+1] != ' ' && vet[i+1] != '\0')
		{
			cont++;
			
		}
	}
	
	
	char vogal[cont][50];
	
	for(i=0; i<cont; i++)
	{
		for(j=0; j<50; j++)
		{
			vogal[i][j] = '\0';
		}
	}
	
	for(i=0; vet[i] !='\0'; i++)
	{
		if(vet[i] != ' ')
		{
			aux[conta] = vet[i];
			conta++;
		}
		else
		{
			conta = 0;
			strcpy(vogal[cont2], aux);
			cont2++;
			limpa(aux);
		}
		if (vet[i+1] == '\0')
		{
			strcpy(vogal[cont2], aux);
		}
	}
		
	for(i=0; i<cont; i++)
	{
		contv=0;
		for(j=0; j<50; j++)
		{
			if(vogal[i][j] == 'a' || vogal[i][j] == 'e' || vogal[i][j] == 'i' || vogal[i][j] == 'o' || vogal[i][j] == 'u')
			{
				contv++;
			}	
			
		}
		
		if(contv>=3)
		{
			printf("%d", contv);
			printf("%s\n", vogal[i]);
		}
	}
printf("%s",vogal[0]);
	
	//for limpa tudo
	
	return 0;
}
