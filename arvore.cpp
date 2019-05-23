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
	t_no *no_temp2;
	t_no *no_temp3;
	
};
typedef struct arvore t_arvore;

void inserir_nos(t_arvore *arvore, int valorB);

void excluir_nos(t_arvore *arvore, int valorB);

int busca_inc(t_arvore *arvore, int valorB);

int busca_exc(t_arvore *arvore, int valorB);

int exibir_menu(void);


int main(int argc, char** argv) {
	
	t_arvore *arvore = (t_arvore *) calloc(1, sizeof(t_arvore));
	arvore->altura = 0;
	arvore->qtd_nos = 0;
	arvore->raiz = NULL;
	arvore->no_temp = NULL;
	arvore->no_temp2 = NULL;
	arvore->no_temp3 = NULL;
	
	int opcao, valorB;
	
	do
	{
		switch(opcao = exibir_menu())
		{
			case 1:	
				inserir_nos(arvore, valorB);
				break;
			case 2:
				excluir_nos(arvore, valorB);
				break;
		}
	} while (opcao != 0);
	
	printf("\n=======%d\n", arvore->raiz->no_id);
	printf("=====%d", arvore->raiz->no_esq->no_id);
	printf("=======  ==%d\n", arvore->raiz->no_dir->no_id);
	printf("\t\t\t%d", arvore->raiz->no_esq->no_esq->no_id);
	printf("=======  ==  %d\n", arvore->raiz->no_dir->no_dir->no_id);
	printf("=======  %d", arvore->raiz->no_dir->no_dir->no_esq->no_id);
	

	return 0;
}

int exibir_menu(void){
	int opcao;

	printf("\n\t1 - Inserir No\n");
	printf("\n\t2 - Excluir No\n");
	printf("\n\tOpcao:");
	
	scanf("%d", &opcao);
	printf("\n");

	return (opcao);
}

void inserir_nos(t_arvore *arvore, int valorB){
	
	t_no *no_bot = (t_no *) calloc(1, sizeof(t_no));
	
	printf("\n\tInserir ID do No:");
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

      valorBtemp = busca_inc(arvore, valorB);
	  
	  if(valorBtemp == 1){
	  	
	  	arvore->no_temp->no_dir = no_bot;
	  	valorBtemp = 0;
	  	
	  }
	  
	  if(valorBtemp == 2){
	  	
	  	arvore->no_temp->no_esq = no_bot;
	  	valorBtemp = 0;
	  	
	  }
	    

    }while(valorBtemp != 0);

  }				
}

int busca_inc(t_arvore *arvore, int valorB){

	if(valorB > arvore->no_temp->no_id){
		
		if(arvore->no_temp->no_dir == NULL)
		return 1;
		else{
		arvore->no_temp = arvore->no_temp->no_dir;
		return 100;
		}	
		
	} else{
		
		if(arvore->no_temp->no_esq == NULL)
		return 2;
		else{
		arvore->no_temp = arvore->no_temp->no_esq;
		return 100;
		}
		
	}
}

void excluir_nos(t_arvore *arvore, int valorB){
	
/*
	SEM FILHOS == REMOVER;
	
	UM FILHO == REMOVER O PAI E COLOCAR O FILHO NO LUGAR;
	
	DOIS FILHOS == 
		SUBSTITUIR PELO MAIOR NÓ DA ESQUERDA; || 
		SUBSTITUIR PELO MENOR NÓ DA DIREITA; EM SEGUIDA >
		EXCLUIR O NÓ USADO PARA SUBSTITUIR;
*/	

	
	
	printf("\n\tExcluir No com ID:");
	scanf("%d", &valorB);
	
	
	if(arvore->raiz->no_id == valorB){
		
		if(arvore->raiz->no_dir == NULL && arvore->raiz->no_dir == NULL){
			arvore->raiz = NULL;
			arvore->qtd_nos--;
			valorB = 0;
		}
		
	}
	
	

    int valorBtemp;

    do{
    	
    	
    	
	    
    }while(valorBtemp != 0);
	
	
}

int busca_exc(t_arvore *arvore, int valorB){

	
	
	
	
}
