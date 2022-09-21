#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

typedef struct lista{
	int valor;
	struct lista* prox;
	struct lista* ant;
}Lista;

typedef struct fila{
	Lista* ini;
	Lista* fim;
}Fila;

void insereFila(Fila* tempF, int L){
	//Cria um novo elemento
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->prox = NULL;
  novo->valor = L;
  
  if(tempF->ini == NULL){
  	tempF->ini = novo;
  	tempF->fim = novo;
  }else{  
  	tempF->fim->prox = novo;
  	tempF->fim = novo;
  }
}

void imprime(Lista* aux){
  while(aux != NULL){
      printf("A%d\t", aux->valor);
    aux = aux->prox;
  }
}

int sizeFila(Fila* tempF){
    Lista* aux = tempF->ini;
    int cont = 0;
    while(aux != NULL){
        cont+=1;
        aux = aux->prox;
    }
    return cont;    
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
  Fila* F = (Fila*)malloc(sizeof(Fila));
  F->ini = NULL;
  F->fim = NULL;
  
  Fila* F1 = (Fila*)malloc(sizeof(Fila));
  F1->ini = NULL;
  F1->fim = NULL;
  Fila* F2 = (Fila*)malloc(sizeof(Fila));
  F2->ini = NULL;
  F2->fim = NULL;
  Fila* F3 = (Fila*)malloc(sizeof(Fila));
  F3->ini = NULL;
  F3->fim = NULL;
  Fila* F4 = (Fila*)malloc(sizeof(Fila));
  F4->ini = NULL;
  F4->fim = NULL;
  
  int d = 1;
  while(d != 0){
		printf("\nSelecione o ponto cardeal do avião que entrou no campo da pista: \n");
		printf("\n-1 Lado Oeste\n");
		printf("\n-2 Lado Sul\n");
		printf("\n-3 Lado Norte\n");
		printf("\n-4 Lado Leste\n");
		printf("\nPara sair digite 0\n\n");
		scanf("%d", &d);
		switch(d){
			int b;
			case -1:
				b = 1;
				printf("\nENTROU");
				while(b > 0){
					printf("\nInforme o numero do identificador do avião A");
					scanf("%d", &b);
					if(b > 0)
						insereFila(F1, b);
				}
			break;
			case -2:
				b = 1;
				while(b > 0){
					printf("\nInforme o numero do identificador do avião A");
					scanf("%d", &b);
					if(b > 0)
						insereFila(F2, b);
				}	
			break;
			case -3:
				b = 1;
				while(b > 0){
					printf("\nInforme o numero do identificador do avião A");
					scanf("%d", &b);
					if(b > 0)
						insereFila(F3, b);
					}
			break;
			case -4:
				b = 1;
				while(b > 0){
					printf("\nInforme o numero do identificador do avião A");
					scanf("%d", &b);
					if(b > 0)
						insereFila(F4, b);
					}
			break;
		}
	}
	
	int i;
	
	int c1 = sizeFila(F1);
	int c2 = sizeFila(F2);
	int c3 = sizeFila(F3);
	int c4 = sizeFila(F4);
	int maior = c1;

	if(c2 > maior)
		maior = c2;
	if(c3 > maior)
		maior = c3;
	if(c4 > maior)
		maior = c4;
		
	Lista* L1 = F1->ini;
	Lista* L2 = F2->ini;
	Lista* L3 = F3->ini;
	Lista* L4 = F4->ini;

	for(i = 0; i < maior; i++){
  	  if(L1 != NULL){
		  insereFila(F, L1->valor);
		  L1 = L1->prox;
   	 }
   	 if(L3 != NULL){
		  insereFila(F, L3->valor);
		  L3 = L3->prox;
   	 }
   	 if(L2 != NULL){
		  insereFila(F, L2->valor);
		  L2 = L2->prox;
   	 }
	 if(L4 != NULL){
	 	  insereFila(F, L4->valor);
		  L4 = L4->prox;
     }
	}
	
	imprime(F->ini);
	
  return 0;
}
