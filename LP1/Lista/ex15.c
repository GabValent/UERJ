#include <stdio.h>

typedef
struct tran
{
	int ano;
	char sexo;
	int pre;
}vtran;

void limpa(struct tran *x)
{
	(*x).ano = 0;
	(*x).sexo = 'N';
	(*x).pre = -1;
}

int main()
{	
	struct tran v;
	float totalm=0,total21=0;
	int idade = 0, cm=0, inter=0, m60=0;
	
	limpa(&v);

	while((v.ano)>=0)
	{
		printf("Digite o ano de nascimento: ");
		scanf("%d", &v.ano);
		if((v.ano)<0)
		{
			break;
		}
		
		totalm++;
		idade = 2021-(v.ano);
		
		if(idade<21)
		{
			total21++;
		}

		printf("Digite o sexo(m/f): ");
		scanf("%s", &v.sexo);
		
		
		if((v.sexo) == 'f' && idade>60);
		{
			m60 = 1;
		}
		
		printf("Digite a precedencia(0-Capital, 1-Interior, 2-Outro estado); ");
		scanf("%d", &v.pre);
		
		if((v.sexo) == 'f' && (v.pre) == 0 )
		{
			cm++;
		}
		
		if((v.pre) == 1 && idade>60)
		{
			inter++;
		}
		
		
		limpa(&v);
	}
	
	float por21 = (total21/totalm)*100;
	
	printf("Porcentagem de motoristas com menos de 21 %2.2f porcento\n ",por21);
	printf("Quantas mulheres tem na capital: %d mulhere(s)\n", cm);
	printf("Motoristas do interior com idade maior que 60 anos: %d\n",inter);
	
	if(m60 == 1)
	{
		printf("Existe alguma mulher com 60 anos ou mais");
	}
	else
	{
		printf("Nao existe mulherem com 60 anos ou mais");
	}
	
	return 0;
}
