#include <stdio.h>

int main()
{
	int troco=0,resto = 0;
	
	
	printf("Digite o valor em centavos: ");
	scanf("%d", &troco);
	
	while (troco > 0)
	{
			if (troco >= 100)
			{
				resto = troco/100;
				printf("Moedas de 1 real: %d",resto);
				troco = troco - (resto*100);
			}
			else if (troco >= 50)
			{
				resto = troco/50;
				printf("\nMoedas de 50 centavos: %d",resto);
				troco = troco - (resto*50);
	    	}
	    	else if(troco >= 25)
	    	{
	    		resto = troco/25;
				printf("\nMoedas de 25 centavos: %d",resto);
				troco = troco - (resto*25);
			}
			else if(troco >= 10)
	    	{
	    		resto = troco/10;
				printf("\nMoedas de 10 centavos: %d",resto);
				troco = troco - (resto*10);
			}
			else if(troco >= 5)
	    	{
	    		resto = troco/5;
				printf("\nMoedas de 5 centavos: %d",resto);
				troco = troco - (resto*5);
			}
			else if(troco >= 1)
	    	{
	    		resto = troco/1;
				printf("\nMoedas de 1 centavo: %d",resto);
				troco = troco - resto;
				
			}
				
	}	
	
	return 0;
}
