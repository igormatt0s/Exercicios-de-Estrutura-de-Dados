#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

int main(){
  Lista* ref;
  Lista *temp;
  ref = (Lista*)malloc(sizeof(Lista));
  ref->valor = 10;
  ref->prox = (Lista*)malloc(sizeof(Lista));
  ref->prox->valor = 20;
  ref->prox->prox = (Lista*)malloc(sizeof(Lista));
  ref->prox->prox->valor = 30;
  ref->prox->prox->prox = NULL;
  
  temp = ref;
  //Percorre até encontrar o final que é o próprio NULL
  while(temp != NULL){
  	if(temp->valor <=  0)
  	temp->valor = 1;
  	
  	//Deslocar o temp para a próxima posição
  	temp = temp->prox;
  }
  
  printf("%d\n%d\n%d\n", ref->valor, ref->prox->valor, ref->prox->prox->valor);
  
return 0;
}
