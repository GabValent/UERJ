#include <stdio.h>

int main()
{
	int num, mil, cent, dez, uni;
	
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	mil = num/1000;
	num = num - 1000*mil;
	switch(mil)
	{
		case 1: printf("Mil ");
		break;
		case 2: printf("Dois mil ");
		break;
		case 3: printf("Tresmil ");
		break;
		case 4: printf("Quatro mil ");
		break;
		case 5: printf("Cinco mil ");
		break;
		case 6: printf("Seis mil ");
		break;
		case 7: printf("Sete mil ");
		break;
		case 8: printf("Oito mil ");
		break;
		case 9: printf("Nove mil ");
		break;
	}
	
	cent = num/100;
	num = num-100*cent;
	
	switch(cent)
	{
		case 1: printf("cento e");
		break;
		case 2: printf("duzentos e");
		break;
		case 3: printf("trezentos e");
		break;
		case 4: printf("quatrocentos e");
		break;
		case 5: printf("quinhentos e");
		break;
		case 6: printf("seiscentos e");
		break;
		case 7: printf("setecentos e");
		break;
		case 8: printf("oitocentos e");
		break;
		case 9: printf("novecentos e");
		break;
	}
	
	dez = num/10;
	if(dez>=2)
	{
	num = num - dez*10;
	}
	
	switch(dez)
	{
		case 2: printf("e vinte ");
		break;
		case 3: printf("e trinta ");
		break;
		case 4: printf(" quarenta ");
		break;
		case 5: printf(" cinquenta ");
		break;
		case 6: printf(" sessenta ");
		break;
		case 7: printf(" setenta ");
		break;
		case 8: printf(" oitenta ");
		break;
		case 9: printf(" noventa ");
		break;
	}
	
	uni = num/1;
	
		switch(uni)
	{
		case 1: printf(" e um");
		break;
		case 2: printf(" e dois");
		break;
		case 3: printf(" e tres");
		break;
		case 4: printf(" e quatro");
		break;
		case 5: printf(" e cinco");
		break;
		case 6: printf(" e seis");
		break;
		case 7: printf(" e sete");
		break;
		case 8: printf(" e oito");
		break;
		case 9: printf(" e nove");
		break;
		case 10: printf(" e dez");
		break;
		case 11: printf(" e onze");
		break;
		case 12: printf(" e doze");
		break;
		case 13: printf(" e treze");
		break;
		case 14: printf(" e quatorze");
		break;
		case 15: printf(" e quinze");
		break;
		case 16: printf(" e dezesseis");
		break;
		case 17: printf(" e dezessete");
		break;
		case 18: printf(" e dezoito");
		break;
		case 19: printf(" e dezenove");
		break;
	}
	
	


return 0;
}
