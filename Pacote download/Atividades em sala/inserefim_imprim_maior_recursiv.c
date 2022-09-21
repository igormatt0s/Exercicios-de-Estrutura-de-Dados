#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
	int valor;
	struct Lista* prox;
	struct Lista* ant;
}Lista;

void imprime(Lista* aux){
	if(aux != NULL){
		printf("\t%d", aux->valor);
		imprime(aux->prox);
	}
	printf("\n");
}

Lista* insereFim_rec(Lista* L, int info){
    if(L == NULL){
    	Lista* novo = (Lista*)malloc(sizeof(Lista));
    	novo->valor = info;
    	novo->prox = NULL;
    	return novo;
	}else{
		L->prox = insereFim_rec(L->prox, info);
	}
    return L;
}

int maior(Lista* L){
	int aux = 0;
	if(L == NULL){
		return 0;
	}else{
		aux = maior(L->prox);
	}
	
	if(aux > L->valor){
		return aux;
	}else{
		return L->valor;
	}
}

Lista* removeLista(Lista* L, int info){
  Lista* aux = L;
  Lista* ant = NULL;

  //Procure pelo valor na lista
  if(aux != NULL && aux->valor != info){
     ant = aux;
     aux = removeLista(aux->prox, info);
  }
 
  if(aux == NULL){//Nao achou o elemento
    return L;
  }else if(ant == NULL){ //Remove do inicio
        L = aux->prox; //Atualiza para segunda posicao
        free(aux);  
  }else{
    ant->prox = aux->prox;
    free(aux);
  }

  return L;
   
}

int main(){
	Lista* L = NULL;
	
	L = insereFim_rec(L, 1000);
	L = insereFim_rec(L, 200);
	L = insereFim_rec(L, 300);
	L = insereFim_rec(L, 40);
	
	imprime(L);
	
	printf("\nMaior: %d\n", maior(L));
	
	removeLista(L, 300);
	
	imprime(L);
	
	return 0;
}
