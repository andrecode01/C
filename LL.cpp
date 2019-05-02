#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct ingrediente t_ingrediente;
struct ingrediente
{
	char *nome;
	t_ingrediente *prox_ingrediente;	
};


typedef struct receita t_receita;
struct receita
{
	char *nome;
	t_receita *prox_receita;
	t_ingrediente *pri_ingrediente;
	t_ingrediente *temp;
	int quant_ingredientes;
		
};

struct lista
{
	t_receita *pri_receita;
	t_receita *temp;
	int quant_receitas;
//	int quant_ingredientes;	
};
typedef struct lista t_lista;

int exibir_menu(void);

void cadastrar_receita(t_lista *lista);

int main() {
	
//	CRIANDO A < LISTA > ====================================
	t_lista *lista = (t_lista *) calloc(1, sizeof(t_lista));
	lista->pri_receita = NULL;
	lista->temp = NULL;
	lista->quant_receitas = 0;
//	lista->quant_ingredientes = 0;
	

//	< MENU > ===========================
	int opcao;	
	do
	{
		switch(opcao = exibir_menu())
		{
			case 2:	
				cadastrar_receita(lista);
					break;
		}
	} while (opcao != 0);
	
	
	
	
//	TESTES
	
	printf("\n\n\t1a RECEITA: %s\n", lista->pri_receita->nome);
	printf("\n\t\tINGREDIENTE: - %s", lista->pri_receita->pri_ingrediente->nome);	
	printf("\n\t\tINGREDIENTE: - %s", lista->pri_receita->pri_ingrediente->prox_ingrediente->nome);
	
	printf("\n\n\t2a RECEITA: %s\n", lista->pri_receita->prox_receita->nome);
	printf("\n\t\tINGREDIENTE: - %s", lista->pri_receita->prox_receita->pri_ingrediente->nome);	
	printf("\n\t\tINGREDIENTE: - %s", lista->pri_receita->prox_receita->pri_ingrediente->prox_ingrediente->nome);
	
	return 0;
}

int exibir_menu(void){
	int opcao;
	
	printf("\n\n\n\t=====-   MENU   -=====\n");
	printf("\n\t1 - Listar Receitas  =\n");
	printf("\n\t2 - Inserir Receita  =\n");
	printf("\n\t0 - Sair             =\n");
	printf("\n\tOpcao:	             =\n\t- ");
	
	scanf("%d", &opcao);
	printf("\n\t-=====================\n");		
	return (opcao);
}

void cadastrar_receita(t_lista *lista){
	
	
	t_receita *receita_CR = (t_receita *) calloc(1, sizeof(t_receita));
	
	char letra;
	int tamanho_nome = 0;
	
	fflush(stdin);
	printf("\n\n\tInforma o nome da receita:	\n\t-");
	while ((letra = getchar()) != '\n')
	{
		
		receita_CR->nome = (char *) realloc(receita_CR->nome, ++tamanho_nome * sizeof(char));
		receita_CR->nome[tamanho_nome - 1] = letra;
		
	}
	fflush(stdin);
	
	receita_CR->prox_receita = NULL;
	receita_CR->pri_ingrediente = NULL;
	receita_CR->temp = NULL;
	receita_CR->quant_ingredientes = 0;
	
	
//  ADICIONANDO OS INGREDIENTES A RECEITA_CR =================================================== 
	int adc_ingredientes = 1;
	do {
		
		char letra2;
		int tamanho_nome2 = 0;
		
		printf("\n\tInforma 1 para adcionar mais um ingrediente, 0 para finalizar.	\n\t-");
		scanf("%d", &adc_ingredientes);
		
		if(adc_ingredientes == 1){
		
			t_ingrediente *ingrediente_CR = (t_ingrediente *) calloc(1, sizeof(t_ingrediente));
			
			fflush(stdin);
			printf("\n\tInforma o nome do Ingrediente:	\n\t-");
			while ((letra2 = getchar()) != '\n')
			{
				ingrediente_CR->nome = (char *) realloc(ingrediente_CR->nome, ++tamanho_nome2 * sizeof(char));
				ingrediente_CR->nome[tamanho_nome2 - 1] = letra2;
			}
			fflush(stdin);
			
			ingrediente_CR->prox_ingrediente = NULL;
			
			if(receita_CR->quant_ingredientes == 0){
				
				receita_CR->pri_ingrediente = ingrediente_CR;
				receita_CR->temp = ingrediente_CR;
				receita_CR->quant_ingredientes++;
				
			} else{
				
				receita_CR->temp->prox_ingrediente = ingrediente_CR;
				receita_CR->temp = ingrediente_CR;
				receita_CR->quant_ingredientes++;
				
			}
			
		}
		
		
	
	} while(adc_ingredientes != 0);
	
	
//  ADICIONANDO A RECEITA NA LISTA ===================================================
	if(lista->quant_receitas == 0){
		
		lista->pri_receita = receita_CR;
		lista->temp = receita_CR;
		
		} else {
		
		if(lista->quant_receitas > 0){
			
			int cont = 0;
			printf("\n\tLugares disponiveis:\n");
			lista->temp = lista->pri_receita;
			
			do {
				
				printf("\n\t%d <- Posicao\n", cont);
				printf("\n\t %do| Nome: %s\n", cont+1, lista->temp->nome);
				
				cont++;
				
				if(cont < lista->quant_receitas)
				lista->temp = lista->temp->prox_receita;
				
			} while (lista->quant_receitas > cont);
			printf("\n\t%d <- Posicao\n", cont);	
		}
		
		int opin;
		printf("\n\tEm qual posicao voce deseja inserir?	\n\t-");
		scanf("%d", &opin);
		
		int j;
		
		if(opin == 0){
			
			lista->temp = lista->pri_receita;
			lista->pri_receita = receita_CR;
			lista->pri_receita->prox_receita = lista->temp;	
			
		} else {
		
		for(j = 0; j < opin; j++){
			
			if(j == 0)
			
			lista->temp = lista->pri_receita;
			
			else{
				
				lista->temp = lista->temp->prox_receita;
				
			}
			
		}
		
		receita_CR->prox_receita = lista->temp->prox_receita;
		lista->temp->prox_receita = receita_CR;
		
		}
	}
	
	lista->quant_receitas++;
	
}
