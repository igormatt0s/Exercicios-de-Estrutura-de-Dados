#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
	int valor;
	struct lista* prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;

//Insere
void push(Pilha* P, int info){
	Lista* aux = (Lista*) malloc(sizeof(Lista));
	aux->valor = info;
	aux->prox = P->topo;
	P->topo = aux;
}

//Remove
void pop(Pilha* P){
	Lista* aux = P->topo;
	
	if(aux != NULL){
		P->topo = P->topo->prox;
		free(aux);
	}	
}

void imprime(Pilha P){
	Lista* aux = P>topo;
	while(P->topo != NULL){
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
}

int main(){
	Pilha* P = (Pilha*) malloc(sizeof(Pilha));
	P->topo = NULL;
	
	P->topo = (Lista*) malloc(sizeof(Lista));
	P->topo->valor = 10;
	P->topo->prox = NULL;
	
	Lista* aux = (Lista*) malloc(sizeof(Lista));
	aux->valor = 20;
	aux->prox = P->topo;
	P->topo = aux;
	
	push(P, 30);
	
	imprime(P);
	
	pop(P);
	
	imprime(P);
	
	return 0;
}
