#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct menu
{
	char nome[20];
	int codp;
	int preco;
};


typedef
struct garcom
{
	char nome[20];
	int codg;
}garcom;

typedef
struct dadosped
{
	int cod;
	int preco;
	int quant;
};


typedef
struct ped
{
	struct ped *proxp;
	struct dadosped dados;
}peds;

typedef
struct dadosmesa
{
	int num;
	int codg;
}d;


typedef
struct mesa
{
	struct mesa *antm, *proxm;
	struct dadosmesa dados;
	struct ped *ped;
}d1;

// FUNÇÕES

void mostrag(struct garcom y[])
{
	
	int i;
	for(i=0;i<30;i++)
	{
		if(y[i].codg != -1)
		{
			printf("Nome: %s\nCodigo:%d",y[i].nome, y[i].codg);
		}
	}
}

void mostram(struct menu x[])
{
	int i;
	for(i=0;i<100;i++)
	{
		if(strcmp(x[i].nome,"Vazio")!= 0)
		{
			printf("%s", x[i].nome);
			printf("%d", x[i].codp);
			printf("%d", x[i].preco);
		}		
	}
}

struct dadosmesa dadosm(struct garcom y[])
{
	struct dadosmesa x;
	printf("\nDigite o numero da mesa: ");
	scanf("%d", &x.num);
	mostrag(y);
	printf("\nDigite o codigo do garcom: ");
	scanf("%d", &x.codg);
	return x;
}

struct dadosped dadosp(struct menu x[])
{
	struct dadosped y;
	int i;
	mostram(x);
	printf("Digite o codigo do pedido: ");
	scanf("%d", &y.cod);
	printf("\nDigite a quantidade do pedido: ");
	scanf("%d", &y.quant);
	
	for(i=0;i<100;i++)
	{
		if(y.cod == x[i].codp)
		{
			y.preco = x[i].preco;
		
		}
	}
	
	
	
	
	return y;
}






//PROTOTIPO DAS FUNÇÕES
void menuprin(struct menu x[], struct garcom y[]);
void addmesa(struct garcom y[], struct mesa **z);
void exmesa(struct mesa **z);
void buscamesa(struct mesa **z);
void alteramesa(struct garcom y[], struct mesa **z);
void addpedido(struct menu x[], struct ped **z);
void alterapedido(struct menu x[], struct ped **z);
void exped(struct ped **z);
void conta(struct mesa **z);

//PROTIPO DAS FUNÇÕES DOS ARQUIVOS
//GARCOM
void menug(struct garcom y[]);
void criarg(struct garcom y[]);
void consulg(struct garcom y[]);
void exg(struct garcom y[]);
void alterag(struct garcom y[]);
//MENU
void menum(struct menu x[]);
void criarm(struct menu x[]);
void consulm(struct menu x[]);
void exm(struct menu x[]);
void alteram(struct menu x[]);
//SAIDA
void sai(struct menu x[], struct garcom y[]);



int main()
{
	
	struct menu men[100];
	struct menu auxm;
	
	struct garcom gar[30];
	struct garcom auxg;
	

		int i;
		char zero[] = "Vazio";
		for(i=0;i<100;i++)
		{
			strcpy(men[i].nome, zero);
			men[i].codp = -1;
			men[i].preco = 0;
		}
	
		for(i=0;i<30;i++)
		{
		strcpy(gar[i].nome, zero);
		gar[i].codg = -1;
		}
	
	FILE *m,*g;
	
	m = fopen("menu.dat", "rb");
	i=0;


	if(m != NULL)
	{
	{	
	while(fread(&auxm,sizeof(struct menu), 1, m)!= NULL)
	{
		strcpy(men[i].nome, auxm.nome);
		men[i].codp = auxm.codp;
		men[i].preco = auxm.preco;
	i++;
	}
	}
}

	else
	{
	m = fopen("menu.dat", "wb");
	}
	fclose(m);	

	g = fopen("garcom.dat", "rb");

 	i=0;

	if(g != NULL)
	{
	{	
		while(fread(&auxg,sizeof(struct garcom), 1, g) != NULL)
	{
		strcpy(gar[i].nome, auxg.nome);
		gar[i].codg = auxg.codg;
		i++;
	}
	}
}
else
{
	g = fopen("garcom.dat", "wb");
}
fclose(g);

menuprin(men,gar);

	
return 0;
}

void menuprin(struct menu x[], struct garcom y[])
{
	int es, busca=-1;
	struct mesa *z, *ajuda;
	
	z = (struct mesa*) malloc(sizeof(struct mesa));
	z = NULL;
	while(es != 11)
	{
	printf("\nDigite[1] para adiconar uma mesa\nDigite[2] para excluir uma mesa\nDigite[3] para buscar uma mesa\nDigite[4] para alterar apenas os dados de uma mesa\nDigite[5] para adicionar um pedido\nDigite[6] para alterar um pedido\nDigite[7] para excluir um pedido\nDigite[8] para fechar a conta de uma mesa\nDigite[9] para acessar o menu dos garcons\nDigite[10] para acessar o menu dos pedidos\n\nDigite sua escolha: ");
	
	scanf("%d", &es);
	
	switch(es)
	{
		case(1):addmesa(y, &z);
		break;
		case(2):exmesa(&z);
		break;
		case(3):buscamesa(&z);
		break;
		case(4):alteramesa(y, &z);
		break;
		case(5):ajuda = z;
				printf("\nDigite o codigo da mesa que deseja adicionar o pedido: ");
				scanf("%d", &busca);
	
				while(ajuda != NULL && ajuda->dados.num != busca)
				{
				ajuda = ajuda->proxm;
				}
	
				struct ped *p = ajuda->ped;	
				addpedido(x, &p);	
				ajuda->ped = p;
				break;
	    case(6):ajuda = z;
				printf("\nDigite o codigo da mesa que deseja alterar o pedido: ");
				scanf("%d", &busca);
	
				while(ajuda != NULL && ajuda->dados.num != busca)
				{
				ajuda = ajuda->proxm;
				}
	
				struct ped *p2 = ajuda->ped;	
				alterapedido(x, &p2);	
				ajuda->ped = p2;
				break;
		case(7):ajuda = z;
				printf("\nDigite o codigo da mesa que deseja alterar o pedido: ");
				scanf("%d", &busca);
	
				while(ajuda != NULL && ajuda->dados.num != busca)
				{
				ajuda = ajuda->proxm;
				}
	
				struct ped *p3 = ajuda->ped;	
				exped (&p3);	
				ajuda->ped = p3;
				break;
		case(8):conta(&z);
		break;
		case(9):menug(y);
		break;
		case(10):menum(x);
		break;
		case(11):free(z);
		sai(x, y);
			
	}
	
	}
	

}

void addmesa(struct garcom y[], struct mesa **z)
{
	struct mesa *novo;
	struct mesa *aux;
	
	novo = (struct mesa*) malloc(sizeof(struct mesa));
		if(novo){
		novo->dados = dadosm(y);
		novo->proxm = NULL;
		novo->ped = (struct ped*)malloc(sizeof(struct ped));
		novo->ped = NULL;
		//Verificar se é o primeiro
		if(*z == NULL)
		{
			novo->antm = NULL;
			*z = novo;
		}
		else
		{
			aux = (*z);
			while(aux->proxm != NULL)
			{
				aux= aux->proxm;
			}
			
			aux->proxm = novo;
			novo->antm = aux;
		}
	}
	else
	{
		printf("Erro ao alocar memoria");
	}
	
	fflush(stdin);
	
}

void exmesa(struct mesa **z)
{
	struct mesa *aux, *ex = NULL;
	int busca=-1;
	printf("Digite o codigo da mesa que deseja remover:");
	scanf("%d", &busca);

	
	printf("%d", busca);
	
	if(*z)
	{
		if((*z)->dados.num == busca)
		{
			ex = *z;
			*z = ex->proxm;
			if(*z)
			{
				(*z)->antm = NULL;
			}
		}
		else
		{
			aux = *z;
			while(aux->proxm!=NULL && aux->proxm->dados.num != busca)
			{
				aux = aux->proxm;
			}
				if(aux->proxm)
				{
					ex = aux->proxm;
					aux->proxm = ex->proxm;
					
					if(aux->proxm != NULL)
					{
						aux->proxm->antm = aux;
					}
				}
		}
	}
	else
	{
		printf("Lista vazia, por favor preencher antes de usar essa funcao");
	}
	free(ex);
}

void buscamesa(struct mesa **z)
{
	struct mesa *aux = NULL;
	int soma=0,somap = 0;
	int busca=-1;
	
	aux = *z;
	struct ped *aux2 = aux->ped;
	
	
	printf("\nDigite o codigo da mesa que deseja busca: ");
	scanf("%d", &busca);
	
	while(aux != NULL && aux->dados.num != busca)
	{
		aux = aux->proxm;
	}
	if(aux != NULL)
	{
		printf("\nNumero: %d\nCodigo do garcom que esta atendando: %d\n", aux->dados.num, aux->dados.codg);
		while(aux->ped != NULL)
		{
			somap = 0;
			somap = (aux->ped->dados.preco*aux->ped->dados.quant);
			printf("\n--------------------------\n");
			printf("Codigo do pedido: %d\nQuantidade: %d\nPreco:%d\n",aux->ped->dados.cod, aux->ped->dados.quant, aux->ped->dados.preco);
			soma = soma +(aux->ped->dados.preco*aux->ped->dados.quant);
			aux->ped = aux->ped->proxp;
			printf("Total do pedido:R$ %d\n", somap);
			printf("--------------------------\n");
		}	
	}
		printf("Total ate agora:%d\n", soma);
		
}

void alteramesa(struct garcom y[], struct mesa **z)
{
	struct mesa *aux = NULL;
	int busca = -1;
	
	aux = *z;
	printf("Digite o codigo da mesa que deseja busca: ");
	scanf("%d", &busca);
	
	while(aux != NULL && aux->dados.num != busca)
	{
		aux = aux->proxm;
	}
	
	aux->dados = dadosm(y);
}

void addpedido(struct menu x[], struct ped **p)
{
	struct ped *aux, *novo;
	novo = malloc(sizeof(struct ped));
	
	if(novo)
	{
		novo->dados = dadosp(x);
		novo->proxp = NULL;
		
		if(*p == NULL)
		{
			
			*p = novo;
		}
		else
		{
			aux = *p;
			while(aux->proxp)
			{
				aux = aux->proxp;
			}
			aux->proxp = novo;
		}
	}
	
}

void alterapedido(struct menu x[], struct ped **z)
{
	struct ped *aux,*aux2=NULL;
	int busca=0;
	int soma;
	
	
	aux = *z;
	aux2 = aux;
	
	while(aux2!=NULL)
	{
			soma = 0;
			printf("\n--------------------------\n");
			printf("Codigo do pedido: %d\nQuantidade: %d\nPreco:%d\n",aux2->dados.cod, aux2->dados.quant, aux2->dados.preco);
			soma = (aux2->dados.preco*aux2->dados.quant);
			printf("Total do pedido:R$ %d\n", soma);
			printf("--------------------------\n");
			aux2 = aux2->proxp;	
	}
	printf("\nDiga o codigo do pedido que deseja alterar: ");
	scanf("%d",&busca);
	aux = *z;
	
	while(aux!=NULL && aux->dados.cod != busca)
	{
		aux = aux->proxp;
	}
	
	printf("Digite o codigo do pedido: ");
	scanf("%d", &aux->dados.cod);
	printf("\nDigite a quantidade do pedido: ");
	scanf("%d", &aux->dados.quant);
	
	int i;
	
	for(i=0;i<100;i++)
	{
		if(aux->dados.cod == x[i].codp)
		{
			aux->dados.preco = x[i].preco;
		}
	
}
}

void exped(struct ped **z)
{
	struct ped *aux, *aux2, *ex = NULL;
	
	int busca=0;
	int soma;
	
	
	aux = *z;
	aux2 = aux;
	
	while(aux2!=NULL)
	{
			soma = 0;
			printf("\n--------------------------\n");
			printf("Codigo do pedido: %d\nQuantidade: %d\nPreco:%d\n",aux2->dados.cod, aux2->dados.quant, aux2->dados.preco);
			soma = (aux2->dados.preco*aux2->dados.quant);
			printf("Total do pedido:R$ %d\n", soma);
			printf("--------------------------\n");
			aux2 = aux2->proxp;	
	}
	
	
	printf("Digite o codigo do pedido que deseja remover:");
	scanf("%d", &busca);

	if(*z)
	{
		if((*z)->dados.cod == busca)
		{
			ex = *z;
			*z = ex->proxp;
		}
		else
		{
			aux = *z;
			while(aux->proxp!=NULL && aux->proxp->dados.cod != busca)
			{
				aux = aux->proxp;
			}
				if(aux->proxp)
				{
					ex = aux->proxp;
					aux->proxp = ex->proxp;
				}
		}
	}
	
	free(ex);
	
	
}


void conta(struct mesa **z)
{
	struct mesa *aux, *ex = NULL;
	int busca=-1,somap,soma=0;	
	printf("Digite o codigo da mesa que deseja fechar:");
	scanf("%d", &busca);

	
	if(*z)
	{
		if((*z)->dados.num == busca)
		{
			while((*z)->ped != NULL)
	      {
			somap = 0;
			somap = ((*z)->ped->dados.preco*(*z)->ped->dados.quant);
			printf("\n--------------------------\n");
			printf("Codigo do pedido: %d\nQuantidade: %d\nPreco:%d\n",(*z)->ped->dados.cod, (*z)->ped->dados.quant, (*z)->ped->dados.preco);
			soma = soma +((*z)->ped->dados.preco*(*z)->ped->dados.quant);
			(*z)->ped = (*z)->ped->proxp;
			printf("Total do pedido:R$ %d\n", somap);
			printf("--------------------------\n");
		  }	
	
		printf("Total:%d\n", soma);
			ex = *z;
			*z = ex->proxm;
			if(*z)
			{
				(*z)->antm = NULL;
			}
		}
		else
		{
			aux = *z;
			while(aux->proxm!=NULL && aux->proxm->dados.num != busca)
			{
				aux = aux->proxm;
			}
			
				if(aux->proxm)
				{
					while(aux->ped != NULL)
				{
				somap = 0;
				somap = (aux->ped->dados.preco*aux->ped->dados.quant);
				printf("\n--------------------------\n");
				printf("Codigo do pedido: %d\nQuantidade: %d\nPreco:%d\n",aux->ped->dados.cod, aux->ped->dados.quant, aux->ped->dados.preco);
				soma = soma +(aux->ped->dados.preco*aux->ped->dados.quant);
				aux->ped = aux->ped->proxp;
				printf("Total do pedido:R$ %d\n", somap);
				printf("--------------------------\n");
				}	
			    
				printf("Total ate agora:%d\n", soma);
					ex = aux->proxm;
					aux->proxm = ex->proxm;
					
					if(aux->proxm != NULL)
					{
						aux->proxm->antm = aux;
					}
				}
			}
	}
	else
	{
		printf("Lista vazia, por favor preencher antes de usar essa funcao");
	}
	free(ex);
}

void menug(struct garcom y[])
{
	int es2=0;
	
	fflush(stdin);
	
	
	while(es2<5)
	{
		printf("Digite[1] para adiconar um garcom\nDigite[2] para consultar um garcom\nDigite[3] Para excluir um garcom\nDigite[4] para alterar um garcom\nDigite[5] para voltar\n\nDigite sua escolha:");
		scanf("%d",&es2);
		switch(es2)
	{
		case(1):criarg(y);
		break;
		case(2):consulg(y);
		break;
		case(3):exg(y);
		break;
		case(4):alterag(y);
		break;
		case(5):break;
	}
}
}


void criarg(struct garcom y[])
{
	int achou=0;
	
	while(strcmp((y[achou].nome),"Vazio") != 0)
	{
		achou++;
	}
	

	fflush(stdin);
	
	printf("\nDigite o Nome do garcom:");
	gets(y[achou].nome);
	
	fflush(stdin);
	
	printf("\nDigite o codigo do garcom:");
	scanf("%d", &y[achou].codg);
}

void consulg(struct garcom y[])
{
	int i, x;

	printf("\nDigite o codigo do garcom que deseja consultar:");
	scanf("%d", &x);
	
	for(i=0; i<30; i++)
	{
		if(y[i].codg == x)
		{
		printf("\nNome:%s\n", y[i].nome);
		printf("\nCodigo:%d\n", y[i].codg);
		}
	}


}

void exg(struct garcom y[])
{
	int achou,i;
	printf("Diga o codigo do garcom que deseja excluir: ");
	scanf("%d", &achou);
	
	for(i=0;i<30;i++)
	{
		if(y[i].codg == achou)
		{
			achou = i;
		}
	}
	
	char zero[] = "Vazio";
	
	strcpy(y[achou].nome, zero);
	y[achou].codg = 0;
	
	
	for(achou;achou<29;achou++)
	{
		strcpy(y[achou].nome,y[achou+1].nome );
		y[achou].codg = y[achou+1].codg;	
	}
}

void alterag(struct garcom y[])
{
	int achou,i;
	
	printf("Diga o codigo do garcom que deseja alterar: ");
	scanf("%d", &achou);
	
	for(i=0;i<30;i++)
	{
		if(y[i].codg == achou)
		{
			achou = i;
		}
	}
	
	printf("\nDigite o Nome do garcom:");
	gets(y[achou].nome);
	fflush(stdin);
	
	printf("\nDigite o codigo do garcom:");
	scanf("%d", &y[achou].codg);
}

void menum(struct menu x[])
{
	int es2=0;
	
	
	while(es2<5)
	{
		printf("Digite[1] para adiconar um pedido\nDigite[2] para consultar um menu\nDigite[3] Para excluir um pedido\nDigite[4] para alterar um pedido\nDigite[5] para voltar\n\nDigite sua escolha:");
		scanf("%d",&es2);
		switch(es2)
	{
		case(1):criarm(x);
		break;
		case(2):consulm(x);
		break;
		case(3):exm(x);
		break;
		case(4):alteram(x);
		break;
		case(5):break;
	}
	}
}


void criarm(struct menu x[])
{
	int achou=0;
	
	while(strcmp((x[achou].nome),"Vazio") != 0)
	{
		achou++;
	}
	
	printf("\nDigite o Nome do pedido:");
	gets(x[achou].nome);
	
	fflush(stdin);
	
	printf("\nDigite o codigo do pedido:");
	scanf("%d", &x[achou].codp);
	
	printf("\nDigite o preco do pedido: ");
	scanf("%d", &x[achou].preco);
}

void consulm(struct menu x[])
{
	int i, achou;

	printf("\nDigite o codigo do pedido que deseja consultar:");
	scanf("%d", &achou);
	
	for(i=0; i<100; i++)
	{
		if(x[i].codp == achou)
		{
		printf("\nNome:%s\n", x[i].nome);
		printf("\nCodigo:%d\n", x[i].codp);
		printf("\nPreco:%d\n", x[i].preco);
		}
	}	
}

void exm(struct menu x[])
{
	int achou,i;
	printf("Diga o codigo do garcom que deseja excluir: ");
	scanf("%d", &achou);
	
	for(i=0;i<100;i++)
	{
		if(x[i].codp == achou)
		{
			achou = i;
		}
	}
	
	char zero[] = "Vazio";
	
	strcpy(x[achou].nome, zero);
	x[achou].codp = 0;
	x[achou].preco = 0;
	
	
	
	for(achou;achou<99;achou++)
	{
		strcpy(x[achou].nome,x[achou+1].nome );
		x[achou].codp = x[achou+1].codp;
		x[achou].preco = x[achou+1].preco;	
	}
}

void alteram(struct menu x[])
{
	int achou,i;
	
	printf("Diga o codigo do garcom que deseja alterar: ");
	scanf("%d", &achou);
	
	for(i=0;i<100;i++)
	{
		if(x[i].codp == achou)
		{
			achou = i;
		}
	}
	
	printf("\nDigite o Nome do pedido:");
	gets(x[achou].nome);
	
	fflush(stdin);
	
	printf("\nDigite o codigo do pedido:");
	scanf("%d", &x[achou].codp);
	
	printf("\nDigite o preco do pedido: ");
	scanf("%d", &x[achou].preco);

}

void sai(struct menu x[], struct garcom y[])
{
	struct garcom aux;
	struct menu aux2;
	int i=0,a=0;
	FILE *g,*m;
	g = fopen("garcom.data","wb");
	
	
	for(i=0;i<30;i++)
	{
		if(strcmp(y[i].nome, "Vazio"))
		{
			a++;
		}
	}
	fwrite(y, sizeof(struct garcom), a, g);
	fclose(g);
	
	m = fopen("menu.data","wb");
	a = 0;
	
	for(i=0;i<100;i++)
	{
		if(strcmp(x[i].nome, "Vazio"))
		{
			a++;
		}
	}
	
	fwrite(x, sizeof(struct menu), a, m);
	fclose(m);
	
	exit(0);
}

