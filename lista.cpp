#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct aluno t_aluno;
struct aluno
{
	char *nome;
	long cpf;
	t_aluno *prox_aluno;
	
};


struct lista
{
	t_aluno *pri_aluno;
	t_aluno *temp;
	int qtda;
	
};
typedef struct lista t_lista;


int exibir_menu(void);

void cadastrar_aluno(t_lista **lista);

void exibir_alunos(t_lista *listas);

int main() {
	
	t_lista *listas = (t_lista *) calloc(1, sizeof(t_lista));
	listas->pri_aluno = NULL;
	listas->temp = NULL;
	listas->qtda = 0;
	
	
	int opcao;
	
	do
	{
		switch(opcao = exibir_menu())
		{
			case 1:	
				cadastrar_aluno(&listas);
					break;
			case 3:
				exibir_alunos(listas);
					break;
		}
	} while (opcao != 0);
	
	
	return 0;
}

int exibir_menu(void){
	int opcao;

	printf("\n\t1 - Cadastrar Aluno(a)\n");
	printf("\n\t3 - Listas Alunos\n");
	printf("\n\tOpcao:");
	
	scanf("%d", &opcao);
	printf("\n");

	return (opcao);
}

void cadastrar_aluno(t_lista **listas){
	
	t_aluno *aluno = (t_aluno *) calloc(1, sizeof(t_aluno));
	
	char letra;
	int tamanho_nome = 0, i;
	
	printf("\tInforme o CPF do(a) aluno(a): \n");
	scanf("%d", &aluno->cpf);

	fflush(stdin);
	printf("\tInforme o nome do aluno(a) aluno(a): \n");
	while ((letra = getchar()) != '\n')
	{
		aluno->nome = (char *) realloc(aluno->nome, ++tamanho_nome * sizeof(char));
		aluno->nome[tamanho_nome - 1] = letra;
	}
	
	aluno->prox_aluno = NULL;
	
	if(listas[0]->qtda == 0){
		
		listas[0]->pri_aluno = aluno;
		listas[0]->temp = aluno;
		
		} else {
		
		if(listas[0]->qtda > 0){
			int cont = 0;
			printf("\tLugares disponiveis:\n");
			listas[0]->temp = listas[0]->pri_aluno;
			do {
				printf("\t%d <- Posicao\n", cont);
				printf("\t %do| Nome: %s\n", cont+1, listas[0]->temp->nome);
				
				cont++;
				
				if(cont < listas[0]->qtda)
				listas[0]->temp = listas[0]->temp->prox_aluno;
				
			} while (listas[0]->qtda > cont);
			printf("\t%d <- Posicao\n", cont);	
		}
		
		int opin;
		printf("\tEm qual posicao voce quer inserir?\n");
		scanf("%d", &opin);
		
		int j;
		
		if(opin == 0){
			
			listas[0]->temp = listas[0]->pri_aluno;
			listas[0]->pri_aluno = aluno;
			listas[0]->pri_aluno->prox_aluno = listas[0]->temp;	
			
		} else {
		
		for(j = 0; j < opin; j++){
			
			if(j == 0)
			listas[0]->temp = listas[0]->pri_aluno;
			else{
				
				listas[0]->temp = listas[0]->temp->prox_aluno;
				
			}
			
		}
		
		aluno->prox_aluno = listas[0]->temp->prox_aluno;
		listas[0]->temp->prox_aluno = aluno;
		}
	}
	
	listas[0]->qtda++;
	
}

void exibir_alunos(t_lista *listas){
	
	
	if(listas->qtda > 0){
		int cont = 0;
		
		listas->temp = listas->pri_aluno;
		do {
					
		printf("\n\t   =========   \n");
		printf("\tCPF: %d\n", listas->temp->cpf);
		printf("\tNome: %s\n", listas->temp->nome);
		printf("\t   =========   \n");
		
		cont++;
		
		if(cont < listas->qtda)
		listas->temp = listas->temp->prox_aluno;
			
		} while (listas->qtda > cont);	
	}
	
}
