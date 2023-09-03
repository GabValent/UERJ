#include <stdio.h>
/*
Um  motorista  acaba  de  retornar  de  um  feriado  prolongado.  Em  cada  parada  de  reabastecimento  ele 
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o 
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de 
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total 
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados  relativos à compra de 
gasolina e calcular : 
a)  a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento; 
b)  a quilometragem obtida por litro de gasolina em toda a viagem 
c)  custo do combustível por quilometro rodado em toda a viagem
*/

int main()
{
	int r=0, gr=0, gv=0, i=0;
	float l=0, p=0, km=0, tp=0, tv=0, kl=0, klt=0, kmt=0, kt=0, lt=0 ;
	
	printf("Quantas paradas foram realizadas: ");
	scanf("%d", &r);
	for(i; i<r; i++)
	{
		printf("Quantos litros colocou na %d  parada: ", i+1);
		scanf("%f", &l);
		
		lt = lt + l;
		
		printf("\nQual o preco do litro: ");
		scanf("%f", &p);
		
		tp = l * p;
		tv = tv + tp;
		
		printf("\nQuantos quilometros foram rodados:");
		scanf("%f", &km);
		
		kt = kt + km;
		kl = km / l;
		
		printf("A quilometragem para %d  parada foi %2f KM/l\n", i+1, kl);
					
	}
	printf("Custo total da viagem: %2f R$\n", tv);
	
	printf("Custo do combustivel por km na viagem foi R$ %2f\n", (kt/tv));
	
	klt = kt/lt; 
	printf("Quilometragem por litro de toda a viagem foi: %3f Km/l", klt);
	
	return 0;
}
