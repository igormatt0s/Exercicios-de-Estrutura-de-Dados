#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

//Estrutura de um noh
// da arvore binaria
typedef struct arv{
  int valor;
  struct arv* esq;
  struct arv* dir;
}Arv;

Arv* insereFolha(int info ){
  Arv* novo = (Arv*) malloc(sizeof(Arv));
  novo->valor = info;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;  
}

int nivel(Arv* node){
	int soma_esq = 0;
	int soma_dir = 0;
	
	if(node == NULL){
		return -1;
	}else{
		soma_esq += 1 + nivel(node->esq);
		soma_dir += 1 + nivel(node->dir);
	}
	if(soma_esq > soma_dir){
		return soma_esq;
	}else{
		return soma_dir;
	}
}

// Pós-Ordem
void printPostorder(Arv* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->esq);

    // then recur on right subtree
    printPostorder(node->dir);

    // now deal with the node
    printf("%d ", node->valor);
    printf("%d ", cont);
}

// In-Ordem
void printInorder(Arv* node)
{
    if (node == NULL)
        return;

    printInorder(node->esq);
 
 	printf("%d ", node->valor);

    printInorder(node->dir);
}

// Pré-Ordem
void printPreorder(Arv* node)
{
    if (node == NULL)
        return;
        
    printf("%d ", node->valor);

    printPreorder(node->esq);

    printPreorder(node->dir);
}

//Imprime formatado
void print2DTree(Arv *root, int space)
{
    // Caso base;
    if (root == NULL)
        return;

    // Aumento da distância entre os níveis
    space += COUNT;

    // Avalia primeiro o nó direita
  // Vai empilhar todas subárvores direitas;
    print2DTree(root->dir, space);

    // Imprime o nó no retorno da recursão
        for (int i = COUNT; i < space; i++)
          printf(" ");
    printf("%d\n", root->valor);

    // Avalia o nó esquerda
    print2DTree(root->esq, space);
}

int main(){
  Arv* AB = (Arv*) malloc(sizeof(Arv));
  AB->valor = 10;
  AB->esq =  insereFolha(20);
  AB->esq->dir = insereFolha(5);
  AB->dir = insereFolha(40);  
  AB->dir->esq = insereFolha(15);

  print2DTree(AB, 1);
  printf("Nivel: %d\n", nivel(AB));
  return 0;
}
