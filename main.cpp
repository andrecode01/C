#include <stdio.h>
#include <stdlib.h>


typedef struct publicacao t_pub;
struct publicacao
{
	
	int cod;
	char nome[15];
	int ed;
	int ano;
	
	t_pub *pub_esq;
	t_pub *pub_dir;
		
};

typedef struct arvore_livraria t_liv;
struct arvore_livraria
{
	t_pub *pub_raiz;
	int qtd_pub;
	int altura;
};


int exibir_menu(void);

int main(){
	
	
	//	MENU
	int opcao;	
	do
	{
		switch(opcao = exibir_menu())
		{
//			case 1:
//				listar(lista);
//				break;
		}
	} while (opcao != 0);
	//	MENU	
	
	return 0;
}

int exibir_menu(void){
	int opcao;
	
	printf("\n\n\n\t=====-   MENU   -========\n");
	printf("\n\t1 - Inserir Publicação  	=\n");
	printf("\n\t0 - Sair             		=\n");
	printf("\n\tOpcao:	             		=\n\t- ");
	
	scanf("%d", &opcao);
	printf("\n\t-=====================\n");		
	return (opcao);
}






