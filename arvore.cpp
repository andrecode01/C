#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct no t_no;
struct no{
	
	int no_id;
	t_no *no_esq;
	t_no *no_dir;
};

struct arvore{
	
	int altura;
	int qtd_nos;
	t_no *raiz;
	t_no *no_temp;
};
typedef struct arvore t_arvore;

void inserir_nos(t_arvore *arvore, int valorB);

int busca(t_arvore *arvore, int valorB);

int exibir_menu(void);


int main(int argc, char** argv) {
	
	t_arvore *arvore = (t_arvore *) calloc(1, sizeof(t_arvore));
	arvore->altura = 0;
	arvore->qtd_nos = 0;
	arvore->raiz = NULL;
	arvore->no_temp = NULL;
	
	int opcao, valorB;
	
	do
	{
		switch(opcao = exibir_menu())
		{
			case 1:	
				inserir_nos(arvore, valorB);
				break;
		}
	} while (opcao != 0);
	
	printf("\n\tID da Raiz: %d", arvore->raiz->no_id);

	return 0;
}

int exibir_menu(void){
	int opcao;

	printf("\n\t1 - Inserir No\n");
	printf("\n\tOpcao:");
	
	scanf("%d", &opcao);
	printf("\n");

	return (opcao);
}

void inserir_nos(t_arvore *arvore, int valorB){
	
	t_no *no_bot = (t_no *) calloc(1, sizeof(t_no));
	
	printf("\n\tInserir ID do no:");
	scanf("%d", &no_bot->no_id);
	
	no_bot->no_esq = NULL;
	no_bot->no_dir = NULL;


	
	if(arvore->raiz == NULL){
		
		arvore->raiz = no_bot;
		arvore->qtd_nos++;	
		arvore->altura++;

		arvore->no_temp = arvore->raiz;

	} 
  else{

    arvore->no_temp = arvore->raiz;

    int valorBtemp;

    valorB = no_bot->no_id;

    do{

      valorBtemp = busca(arvore, valorB);

    }while(valorBtemp != 0);

  }				
}

int busca(t_arvore *arvore, int valorB){

  if(valorB > arvore->no_temp->no_id){

    

  }


}
