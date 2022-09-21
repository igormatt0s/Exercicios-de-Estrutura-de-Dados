#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

typedef struct{
  Lista* ini;
  Lista* fim;
}Fila;

//Para remover da Fila, considere:
//1- Fila vazia;
//2- Fila com apenas 1 elemento.
void removeFila(Fila* tempF){
	//Pega o inicio da Fila
  Lista* aux = tempF->ini;
//Verifica se a Fila não está vazia
  if(aux!=NULL){
  	//atualiza o inicio com a segunda posição
  	tempF->ini = aux->prox;
  	//Remove o elemento
  	free(aux);
  	
  	//Verifica se a Fila tinha apenas 1 elemento
  	//Atualiza o fim para NULL
  	if(tempF->ini == NULL){
  		tempF->fim = NULL;
	  }
  }
}

void insereFila(Fila* tempF, int info){
  //Cria o novo elemento;
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->valor = info;
  novo->prox = NULL;

  //Testar Fila vazia
  if(tempF->ini==NULL){
    tempF->ini = novo;
    tempF->fim = novo;
  }else{  
    //Ligar o ultimo elemento com o novo
    tempF->fim->prox = novo;
    //Atualizo o ponteiro fim
    tempF->fim = novo;
  }
}

void imprimeFila(Lista* ref){
  //Recebe o início da Fila
  while(ref!=NULL){
    printf("%d ", ref->valor);
    ref=ref->prox;
  }
  printf("\n");
 
}

int main(){
  //Criando uma Fila com 10-20-30 a partir da função insere
  //Fila vazia
  Fila* F = (Fila*) malloc(sizeof(Fila));
  F->ini = NULL;
  F->fim = NULL;
  
  insereFila(F, 10);
  
  insereFila(F, 20);
  
  insereFila(F, 30);
  
  removeFila(F);
  
  imprimeFila(F->ini);
 
  return 0;
}
