#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

//in�cio da Struct Lista
typedef struct listaD{
	int valor;
	struct listaD* prox;
	struct listaD* ant;
}ListaD;

ListaD* insereIni(ListaD* L, int info){
  ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
  novo->valor = info;
  novo->ant = NULL;
  novo->prox = L;
  
  if(L != NULL)
  	L->ant = novo;
  
  return novo;
}

ListaD* insereFim(ListaD* L, int info){
  ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
  novo->ant = NULL;
  novo->valor = info;
  novo->prox = NULL;
  
  if(L == NULL){
    return novo;
	}
  //Percorre  lista para encontrar o atual �ltimo
  ListaD* aux = L;
  //Percorre at� o �ltimo elemento
  while(aux->prox != NULL){
    aux = aux->prox;
    
    //Conecta o �ltimo elemento da lista com o novo elemento alocado
    aux->prox = novo;
    novo->ant = aux;
	}
	return L;
}

ListaD* deslocaMaior(ListaD* L){
   ListaD* aux = L; //Percorre lista
   ListaD* maior = L;// Guarda o maior encontrado
  
  //Lista vazia
  if(L == NULL){
  	return L;
  }
  
   //La�o para percorrer a lista inteira e encontrar o maior
   while(aux != NULL){
     if(maior->valor < aux->valor){
  
       maior = aux;
     }
     aux = aux->prox;
  
   }
   
   if(maior->ant == NULL){//Teste inicio
   	return L;
   }else if(maior->prox == NULL){//Teste fim
   //atualiza o penultimo para o fim
   	maior->ant->prox = maior->prox;
   }else{//Teste meio da lista
   maior->ant->prox = maior->prox;
   maior->prox->ant = maior->ant;
	}
	
	//Desloca o maior para o in�cio
	maior->prox = L;
	L->ant = maior;
	maior->ant == NULL;

	//Retorna o novo in�cio
   return maior;
}

ListaD* removeLista(ListaD* L, int info){
	ListaD* aux = L;
	
	while(aux != NULL && aux->valor != info){
		aux = aux->prox;
	}
	
	if(aux->ant == NULL){//elemento est� no in�cio
		aux->prox->ant = NULL; //atualizo o valor da segunda posi��o com ant == NULL
		//ou ax->prox->ant = aux->ant
		L = aux->prox; //guarda o endere�o da segunda posi��o
		free(aux); //remove a primeira posi��o
	}else(aux->prox = NULL){//Remove elemento no fim
		aux->ant->prox = NULL;
		free(aux);
	}else{//Remove elemento no meio da lista
		aux->ant->prox = aux->prox; //liga o anterior com o pr�ximo
		aux->prox->ant = aux->ant; //liga  o pr�ximo com o anterior

    	free(aux);
	}
	
	return L;
	
}

void imprime(ListaD* aux){
	while(aux != NULL){
		printf("\t%d", aux->valor);
		aux = aux->prox;
	}
	printf("\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	ListaD* pref = NULL;
	pref = (ListaD*)malloc(sizeof(ListaD));
	pref->ant = NULL;
	pref->prox = (ListaD*) malloc(sizeof(ListaD));
	pref->valor = 10;
	
	pref->prox->valor = 20;
	pref->prox->prox = NULL;
	pref->prox->ant = pref;
	
	pref = insereIni(pref, 5);
	imprime(pref);
	pref = insereFim(pref, 15);
	pref = insereFim(pref, 35);
	imprime(pref);
	
	pref = deslocaMaior(pref);
	imprime(pref);
	
	pref = removeLista(pref, 15);
	imprime(pref);
	
	return 0;
}
