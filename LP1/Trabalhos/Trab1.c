#include <stdio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
//QUANDO FOR RODAR UTILIZE LETRAS MINUSCULAS
typedef
struct at
{
	char nome[20];
	char tipo[15];
	char local[30];
	char regiao[30];
	char qual[7];
	char preco[7];
	char resum[50];
}at;
	
void limpa(struct at x[])
{
	int k;
	char zero[] = "Vazio";
	for(k=0;k<100;k++)
	{
		strcpy(x[k].nome, zero);
		strcpy(x[k].tipo, zero);
		strcpy(x[k].local, zero);
		strcpy(x[k].regiao, zero);
		strcpy(x[k].qual, zero);
		strcpy(x[k].preco, zero);
		strcpy(x[k].resum, zero);
	
	}
}


void menuprin( struct at z[],char x[], int a);
void regi(struct at z[], int a);
void consul( struct at z[], char x[], int a);
void criar(struct at z[], char x[],int a);
void saida(struct at z[],int a);
void altera(struct at z[],char x[], int a);
void ex(struct at z[],char x[], int a);
void mostra(struct at z[],char x[], int a);



int main()
{

struct at event[100];
struct at aux;
int i=0, total=0;
limpa(event);

FILE *p;

p = fopen("dados.dat", "rb");

if(p != NULL)
{
	{	
	while(fread(&aux,sizeof(struct at), 1, p) != NULL)
	{
	strcpy(event[i].nome, aux.nome);
	strcpy(event[i].tipo, aux.tipo);
	strcpy(event[i].local, aux.local);
	strcpy(event[i].regiao, aux.regiao);
	strcpy(event[i].qual, aux.qual);
	strcpy(event[i].preco, aux.preco);
	strcpy(event[i].resum, aux.resum);
	total++;
	i++;
	}
	}
}

else
{
	p = fopen("dados.dat", "wb");

}

fclose(p);

regi(event,total);

return 0;
}


void saida(struct at z[], int a)
{
	printf("%s", z[0].nome);
	struct at aux2;
	int t=0,i=1;
	FILE *arq;
	arq = fopen("dados.dat","wb");
	a++;
	
	fwrite(z, sizeof(struct at), a, arq);
	
	
	
	

	fclose(arq);
	exit(0);
	
}

void regi( struct at z[], int a)
{
	
	char reg[15];
	printf("Diga a regiao que deseja se conectar:");
	scanf("%s", reg);
	menuprin(z, reg, a);
}


void consul( struct at z[], char x[], int a)
{
	int i;
	for(i=0; i<100; i++)
	{
		if(strcmp(z[i].regiao,x)==0)
		{
		printf("\nNome:%s\n", z[i].nome);
		printf("Tipo:%s\n", z[i].tipo);
		printf("Local:%s\n", z[i].local);
		printf("Qualidade:%s e %s\n", z[i].qual, z[i].preco);
		printf("Resumo:%s\n", z[i].resum);
		}
	}
	
menuprin(z, x, a);
	
}
	
void criar(struct at z[], char x[], int a)
{
	int achou=0,i=0;
	
	while(strcmp((z[achou].nome),"Vazio") != 0)
	{
		achou++;
		
	}
	
		
	fflush(stdin);
	
	printf("\nDigite o Nome da atracao:");
	gets(z[achou].nome);
	
	fflush(stdin);
	
	printf("\nDigite o tipo de atracao:");
	gets( z[achou].tipo);
	
	fflush(stdin);
	
	printf("\nDiga o Local da atracao(Estado):");
	gets( z[achou].local);
	
	fflush(stdin);
	
	if(strcmp(z[achou].local,"acre")==0||strcmp(z[achou].local,"amapa")==0 ||strcmp(z[achou].local,"amazonas")==0 
	||strcmp(z[achou].local,"para")==0 ||strcmp(z[achou].local,"rondonia")==0 || strcmp(z[achou].local,"roraima")==0 
	|| strcmp(z[achou].local,"tocantins")==0) 
	{
		char v[] = "norte";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"alagoas")==0||strcmp(z[achou].local,"bahia")==0 ||strcmp(z[achou].local,"ceara")==0 
			||strcmp(z[achou].local,"maranhao")==0 ||strcmp(z[achou].local,"paraiba")==0 || strcmp(z[achou].local,"pernambuco")==0 
			|| strcmp(z[achou].local,"piaui")==0 || strcmp(z[achou].local,"rio grande do norte")==0|| strcmp(z[achou].local,"sergipe")==0)
	
	{
		char v[] = "nordeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"goias")==0||strcmp(z[achou].local,"mato grosso")==0 ||strcmp(z[achou].local,"mato grosso do sul")==0 
			||strcmp(z[achou].local,"distrito federal")==0)
	{
		char v[] = "centro oeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"sao paulo")==0||strcmp(z[achou].local,"rio de janeiro")==0 ||strcmp(z[achou].local,"espirito santo")==0 
			||strcmp(z[achou].local,"minas gerais")==0)
	{
		char v[] = "sudeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if (strcmp(z[achou].local,"parana")==0||strcmp(z[achou].local,"santa catarina")==0 ||strcmp(z[achou].local,"rio grande do sul")==0) 
	{
		char v[] = "sul";
		strcpy(z[achou].regiao, v);
	}
	
	else
	{
		char v[] = "Nao brasileira";
		strcpy(z[achou].regiao, v);
	}

	
	printf("\nDiga sobre a qualidade(Bom, ruim ou regular?:");
	gets( z[achou].qual);
	
	fflush(stdin);
	
	printf("\nDiga sobre a qualidade(Gratis, barato ou caro?):");
	gets( z[achou].preco);
	
	fflush(stdin);
	
	printf("\nDigite um pequeno resumo:");
	gets( z[achou].resum);
	
	printf("%s", z[achou].nome);
	
	
	

menuprin(z, x, achou);
	
}

void altera(struct at z[], char x[], int a)
{
	fflush(stdin);
	char busca[20];
	int i, achou = 0;
	

	printf("\nDigite o nome da atracao que deseja alterar:");
	gets(busca);
	
	for(i=0;i<a;i++)
	{
		if(strcmp(z[i].nome,busca)==0)
		{
			achou = i;
		}
	}	
	printf("Digite as alteracoes");
	
	fflush(stdin);
	
	printf("\nDigite o Nome da atracao:");
	gets(z[achou].nome);
	
	fflush(stdin);
	
	printf("\nDigite o tipo de atracao:");
	gets( z[achou].tipo);
	
	fflush(stdin);
	
	printf("\nDiga o Local da atracao(Estado):");
	gets( z[achou].local);
	
	
	if(strcmp(z[achou].local,"acre")==0||strcmp(z[achou].local,"amapa")==0 ||strcmp(z[achou].local,"amazonas")==0 
	||strcmp(z[achou].local,"para")==0 ||strcmp(z[achou].local,"rondonia")==0 || strcmp(z[achou].local,"roraima")==0 
	|| strcmp(z[achou].local,"tocantins")==0) 
	{
		char v[] = "norte";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"alagoas")==0||strcmp(z[achou].local,"bahia")==0 ||strcmp(z[achou].local,"ceara")==0 
			||strcmp(z[achou].local,"maranhao")==0 ||strcmp(z[achou].local,"paraiba")==0 || strcmp(z[achou].local,"pernambuco")==0 
			|| strcmp(z[achou].local,"piaui")==0 || strcmp(z[achou].local,"rio grande do norte")==0|| strcmp(z[achou].local,"sergipe")==0)
	
	{
		char v[] = "nordeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"goias")==0||strcmp(z[achou].local,"mato grosso")==0 ||strcmp(z[achou].local,"mato grosso do sul")==0 
			||strcmp(z[achou].local,"distrito federal")==0)
	{
		char v[] = "centro oeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if	(strcmp(z[achou].local,"sao paulo")==0||strcmp(z[achou].local,"rio de janeiro")==0 ||strcmp(z[achou].local,"espirito santo")==0 
			||strcmp(z[achou].local,"minas gerais")==0)
	{
		char v[] = "sudeste";
		strcpy(z[achou].regiao, v);
	}
	
	else if (strcmp(z[achou].local,"parana")==0||strcmp(z[achou].local,"santa catarina")==0 ||strcmp(z[achou].local,"rio grande do sul")==0) 
	{
		char v[] = "sul";
		strcpy(z[achou].regiao, v);
	}
	
	else
	{
		char v[] = "Nao brasileira";
		strcpy(z[achou].regiao, v);
	}
	
	fflush(stdin);
	
	printf("\nDiga sobre a qualidade(Bom, ruim ou regular?:");
	gets( z[achou].qual);
	
	fflush(stdin);
	
	printf("\nDiga sobre a qualidade(Gratis, barato ou caro?):");
	gets( z[achou].preco);
	
	fflush(stdin);
	
	printf("\nDigite um pequeno resumo:");
	gets( z[achou].resum);
	
	fflush(stdin);
	
	
menuprin(z, x, a);
}

void ex(struct at z[], char x[], int a)
{
	char apag[20];
	int achou=-1,i;
	printf("Diga o nome da atracao que deseja excluir: ");
	fflush(stdin);
	gets(apag);
	
	for(i=0;i<100;i++)
	{
		if(strcmp(apag,z[i].nome)==0)
		{
			achou = i;
		}
	}
	if(achou<0)
	{
		printf("Nao foi possivel buscar essa descricao");
		menuprin(z, x, a);
	}
	
	char zero[] = "Vazio";
	
	strcpy(z[achou].nome, zero);
	strcpy(z[achou].tipo, zero);
	strcpy(z[achou].local, zero);
	strcpy(z[achou].regiao, zero);
	strcpy(z[achou].qual, zero);
	strcpy(z[achou].preco, zero);
	strcpy(z[achou].resum, zero);
	
	
	for(achou;achou<99;achou++)
	{
		strcpy(z[achou].nome,z[achou+1].nome );
		strcpy(z[achou].tipo, z[achou+1].tipo);
		strcpy(z[achou].local, z[achou+1].local);
		strcpy(z[achou].regiao, z[achou+1].regiao);
		strcpy(z[achou].qual, z[achou+1].qual);
		strcpy(z[achou].preco, z[achou+1].preco);
		strcpy(z[achou].resum, z[achou+1].resum);
	}
	
	a--;
	menuprin(z, x, a);

}

void mostra(struct at z[],char x[], int a)
{
	char mos[20];
	int i;
	
	printf("Digite o nome da atracao que deseja ser exibida:");
	fflush(stdin);
	gets(mos);
	
	for(i=0;i<100;i++)
	{
		if(strcmp(mos,z[i].nome)==0)
		{
			printf("\nNome:%s\n", z[i].nome);
			printf("Tipo:%s\n", z[i].tipo);
			printf("Local:%s\n", z[i].local);
			printf("Qualidade:%s e %s\n", z[i].qual, z[i].preco);
			printf("Resumo:%s\n", z[i].resum);
		}
	}

	menuprin(z, x, a);	
}

void menuprin( struct at z[], char x[], int a)
{	
int op;

printf("\nO senhor(a) esta conectado(a) a regiao %s, diga o que deseja:\n 1-Conectar a outra regiao\n 2-Consultar as atracoes da regiao\n 3-Incluir uma descricao\n 4-Alterar uma descricao\n 5-Excluir uma descricao\n 6-Mostrar uma descricao\n 7-Sair\n Digite a opcao desejada:", x);

scanf("%d", &op);

switch(op)
{
	case 1:regi(z,a);
	break;
	case 2:consul(z, x, a);
	break;
	case 3:criar(z, x, a);
	break;
	case 4:altera(z, x, a);
	break;
	case 5:ex(z, x, a);
	break;
	case 6:mostra(z, x, a);
	case 7: saida(z, a);
}
}
