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

int sizeFila(Fila* tempF){
	Lista* aux = tempF->ini;
	int cont = 0;
	while(aux != NULL){
		cont+=1;
		aux = aux->prox;
	}
	return cont;
}

void removePares(Fila* temF){
	int cont = sizeFila(tempF);
	Lista* aux = tempF->ini;
	if(tempF->ini != NULL){
		while(cont != 0){
			if(tempF->ini->valor % 2 != 0){
				insereFila(tempF, tempF->ini->valor);
				removeFila(tempF);
			}else{
				removeFila(tempF);
			}
			cont--;
		}
	}
}

//Para remover da Fila, considere:
//1- Fila vazia;
//2- Fila com apenas 1 elemento.
void removeFila(Fila* tempF){
	//Pega o inicio da Fila
  Lista* aux = tempF->ini;
//Verifica se a Fila n�o est� vazia
  if(aux!=NULL){
  	//atualiza o inicio com a segunda posi��o
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
  //Recebe o in�cio da Fila
  while(ref!=NULL){
    printf("%d ", ref->valor);
    ref=ref->prox;
  }
  printf("\n");
 
}

int main(){
  //Criando uma Fila com 10-20-30 a partir da fun��o insere
  //Fila vazia
  Fila* F = (Fila*) malloc(sizeof(Fila));
  F->ini = NULL;
  F->fim = NULL;
  
  insereFila(F, 1);
  
  insereFila(F, 2);
  
  insereFila(F, 3);
  
  insereFila(F, 4);
  
  insereFila(F, 5);
  
  imprimeFila(F->ini);
  
  removePares(F);
  
  imprimeFila(F->ini);
 
  return 0;
}
