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
	int quant_ingredientes;
		
};

struct lista
{
	t_receita *pri_receita;
	t_receita *temp;
	int quant_receitas;
	int quant_ingredientes;	
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
	lista->quant_ingredientes = 0;
	

//	< MENU > ===========================
	int opcao;	
	do
	{
		switch(opcao = exibir_menu())
		{
			case 1:	
				cadastrar_receita(lista);
					break;
		}
	} while (opcao != 0);
	
	
	
	
	return 0;
}

int exibir_menu(void){
	int opcao;

	printf("\n\t1 - Cadastrar Receita\n");
	printf("\n\t3 - Listar Receitas\n");
	printf("\n\tOpcao:");
	
	scanf("%d", &opcao);
	printf("\n");

	return (opcao);
}

void cadastrar_receita(t_lista *lista){
	
	
	t_receita *receita_CR = (t_receita *) calloc(1, sizeof(t_receita));
	
	char letra;
	int tamanho_nome = 0;
	
	fflush(stdin);
	printf("\n\tInforma o nome da receita:\n");
	while ((letra = getchar()) != '\n')
	{
		receita_CR->nome = (char *) realloc(receita_CR->nome, ++tamanho_nome * sizeof(char));
		receita_CR->nome[tamanho_nome - 1] = letra;
	}
	
	receita_CR->prox_receita = NULL;
	receita_CR->pri_ingrediente = NULL;
	receita_CR->quant_ingredientes = 0;
	
	
//  ADICIONANDO OS INGREDIENTES À RECEITA_CR =================================================== 
	int adc_ingredientes = 404;
	do {
		
		t_ingrediente *ingrediente_CR = (t_ingrediente *) calloc(1, sizeof(t_ingrediente));
		
		fflush(stdin);
		printf("\n\tInforma o nome do Ingrediente:\n");
		while ((letra = getchar()) != '\n')
		{
			//receita_CR->pri_ingrediente-> = (char *) realloc(receita_CR->nome, ++tamanho_nome * sizeof(char));
			//receita_CR->nome[tamanho_nome - 1] = letra;
		}
		
	} while(adc_ingredientes != 0);
	
	
	
	
}














