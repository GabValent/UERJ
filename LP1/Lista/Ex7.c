#include <stdio.h>
#include <string.h>
typedef
	struct aluno
	{
		char nome[10];
		float med;
	}taluno;


int i=1, j=0;
float somat=0, medt=0;
struct aluno x[50];
struct aluno aux;

int main()
{
	for(j; j<50; j++)
{		
	printf("Entre com o nome: ");
	scanf("%s", x[j].nome);
	printf("Entre com a media: ");
	scanf("%f", &x[j].med);
	somat = somat + x[j].med; 
}

medt = somat/50;

	for(i; i<50; i++)
	{
		for(j; j<49; j++ )
		{
			if(x[j].med> x[j+1].med)
			{
				aux = x[j];
				x[j] = x[j+1];
				x[j+1] = aux;
			}
		}
	}
printf("Media da turma %2.2f", medt);

for (i=45; i<50; i++)
{
	if (x[i].med > medt)
	{
		printf("\nAluno acima da media: %s", x[i].nome);
	}
}
	
return 0;	
}


	
	


