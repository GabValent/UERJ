#include <stdio.h>
#include <string.h>


void limpa(char v[])
{
	int k;
	for( k=0; k<80; k++)
	{
		v[k] = '\0';
	}
}

int cvogal(char v[])
{
	int k,cont=0, tam;
	tam = strlen(v)
	for(k=0; k<tam; k++)
	{
		if(v[k] == 'a' || v[k] == 'e' || v[k] == 'i' || v[k] == 'o' || v[k] == 'u')
		{
			cont++
		}
	}
	return cont; 
}

int main()
{
	int i, j, cont=1, conta=0, cont2=0;
	char vet[50], aux[50];
	limpa(vet);
	limpa(aux);
	
	printf("Digite uma palavra");
	gets(vet);
	
	for(i=0; vet[i] != '\0'; i++)
	{
		if(vet[i] == ' ' && vet[i+1] != ' ' && vet[i+1] != '\0')
		{
			cont++;
			
		}
	}
	
	char vogal[cont][80];
	
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
		int contv = cvogal(vogal[i]);
		
		if(contv>=3)
		{
			printf("%s",vogal[i]);
		}
	}
	
	
	
	
	return 0;
}
