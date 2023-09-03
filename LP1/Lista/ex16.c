#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int *x)
{	
	*x = (rand() % 5)+1;
	printf("%25d\n", *x);
	return *x;
}


int main()
{
	int p1d1=0, p1d2=0, p2d1=0, p2d2=0, i=0, soma1=0, soma2=0, v1=0, v2=0;
	
	srand(time(NULL));
	
for(i=0;i<11; )
{
	soma1 = 0;
	soma2 = 0;
	printf("Primeiro lancamento da partida %d:\n",(i+1));
	dado(&p1d1);
	dado(&p2d1);
	
	printf("Segundo lancamento da partida %d:\n",(i+1));
	
	dado(&p1d2);
	dado(&p2d2);
	
	
	soma1 = p1d1 + p1d2;
	soma2 = p2d1 + p2d2;
	
	
	if ((p1d1==p1d2) && (p2d1==p2d2))
	{
		if (soma1==soma2)
		{
			printf("Empate");
			i++;
			
		}
		else if(soma1>soma2)
		{
			v1++;
			printf("\nJogador 1 ganhou a %d rodada\n",(i+1));
			i++;
			
		}
		else
		{
			v2++;
			printf("\nJogador 2 ganhou a %d rodada\n", (i+1));
			i++;
			
		}
	}
	else if(p1d1==p1d2 && p2d1!=p2d2)
	{
		v1++;
		printf("\nJogador 1 ganhou a %d rodada\n",(i+1));
		i++;
		
	}
	else if((p2d1==p2d2) && (p1d1!=p1d2))
	{
		v2++;
		printf("\nJogador 2 ganhou a %d rodada\n", (i+1));
		i++;
		
	}
	else
	{
		if ((p1d1>p2d1) || (p1d2>p2d2))
			{
				v1++;
				printf("\nJogador 1 ganhou a %d rodada\n",(i+1));
			
			}
		else if((p2d1>p1d1) || (p2d2>p1d2))
		{
			v2++;
			printf("\nJogador 2 ganhou a %d rodada\n", (i+1));
		}
		i++;

	}
}
	
	if(v1==v2)
	{
		printf("Empate");
	}
	else if(v1>v2)
	{
		printf("Vitoria do jogador 1");
	}
	else
	{
		printf("Vitoria do jogador 2");
	}
			
	
	return 0;
}
