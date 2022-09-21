#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

//início da Struct Lista
typedef struct lista{
	int valor;
	struct lista* prox;
}Lista;

typedef struct fila{
	Lista* ini;
	Lista* fim;
}Fila;

void insereFila(Fila* tempF, int info){
	//Cria um novo elemento
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->prox = NULL;
  novo->valor = info;
  
  //Testar fila vazia
  if(tempF->fim == NULL){
  	tempF->ini = novo;
  	tempF->fim = novo;
  }else{  
  //Ligar o último elemento com o novo
  tempF->fim->prox = novo;
  //Atualiza o ponteiro fim
  tempF->fim = novo
}
}

void imprimeFila(Lista* ref){
	//Recebe o início da Fila
	while(ref !=NULL){
		printf("%d", ref->valor);
		ref= ref->prox;
	}
	printf("\n");
}

int main(){
	//Caso 1: Fila vazia;
	Fila* F = (Fila*)malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;
	
	//Caso 2: Fila com 1 elemento;
	F->ini = (Lista*)malloc(sizeof(Lista));
	F->ini->valor = 10;
	F->ini->prox = NULL;
	F->fim = F->ini;
	
	//Caso 3: Fila com 2 elementos;
	Lista* aux = (Lista*) malloc(sizeof(Lista));
	aux->valor = 20;
	aux->prox = NULL;
	
	F->fim->prox = aux;
	F->fim = aux;
	
	insereFila(F, 20);
	
	imprimeFila(F->ini);
	
	return 0;
}
