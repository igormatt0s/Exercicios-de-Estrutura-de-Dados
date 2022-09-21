#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

Lista* insereFim(Lista* L, int info){
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->valor = info;
  novo->prox = NULL;
  
  if(L == NULL)
    return novo;
  //Percorre  lista para encontrar o atual �ltimo
  Lista* aux = L;
  //Percorre até o último elemento
  while(aux->prox != NULL){
    aux = aux->prox;
    
    //Conecta o último elemento da lista com o novo elemento alocado
    aux->prox = novo;
  }
  return L;
}

Lista* insereIni(Lista* L, int info){
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->valor = info;
  novo->prox = L;
  return novo;
}

void imprime(Lista* aux){
  while(aux != NULL){
      printf("%d\n", aux->valor);
    aux = aux->prox;
  }

}

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
  
  imprime(ref);
printf("\n\n");
  ref = insereIni(ref, 5);
  imprime(ref);
  
  printf("\n\n");
  ref = insereFim(ref, 40);
  imprime(ref);
  
return 0;
}
