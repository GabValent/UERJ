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

int main()
{
	int i, j, cont=1,conta=0, cont2=0;
	char vet[80], aux[80];
	
	limpa(vet);
	limpa(aux);
	
	printf("Digite uma frase:");
	gets(vet);
	
	for(i=0; vet[i] != '\0'; i++)
	{
		if(vet[i] == ' ' && vet[i+1] != ' ' && vet[i+1] != '\0')
		{
			cont++;
			
		}
	}
	printf("%d\n",cont);
	
	char sep[cont][80];
	
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
			strcpy(sep[cont2], aux);
			cont2++;
			limpa(aux);
		}
		if (vet[i+1] == '\0')
		{
			strcpy(sep[cont2], aux);
		}
	}
	
	
	char marca[1] = "0";

	for(i=0; i<cont; i++)
	{
		int contp;
		contp = 1;
		for(j=i+1; j<cont; j++ )
		{
			if(strcmp(sep[i], sep[j])==0)
			{
				contp ++;
				strcpy(sep[j], marca);
					
			}

		}
		if(strcmp(sep[i],marca)!=0)
		{
		printf("%s teve %d ocorrencia\n", sep[i], contp);
		}
	}
	
	
	return 0;
}
