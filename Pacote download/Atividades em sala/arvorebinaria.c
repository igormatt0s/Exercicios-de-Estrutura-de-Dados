#include <stdio.h>
#include <stdlib.h>

//Estrutura de um nó de arvore binária
typedef struct arv{
	int valor;
	struct arv* esq;
	struct arv* dir;
}Arv;

Arv* insereFolha(int info){
	Arv* novo = (Arv*)malloc(sizeof(Arv));
	novo->valor = info;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

int main(){
	Arv* AB = (Arv*)malloc(sizeof(Arv));
	AB->valor AB= 10;
	AB->esq = insereFolha(20);
	AB->esq->dir = insereFolha(5);
	AB->dir = insereFolha(40);
	AB->dir->esq = insereFolha(10);
	return 0;
}
