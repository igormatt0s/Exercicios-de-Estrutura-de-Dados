//Igor Araujo de Mattos - 2346443

#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
}Arv;

Arv* abb_cria(void){
   return NULL;
}

void abb_imprime(Arv* a){
    if(a != NULL){
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_insere(Arv* a, int v){
    if(a==NULL){
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if(v < a->info)
         a->esq = abb_insere(a->esq,v);
    else
         a->dir = abb_insere(a->dir,v);
    return a;
}
       
int testa_abb(Arv* a){

    int cont = 0;


    if (a == NULL){
        return 0;
    }
    
    else if (a->esq == NULL){
        if (a->dir == NULL) {
            return 0;
        }
        else {
            if(a->dir->info > a->info){
                cont += testa_abb(a->dir);
            }
            else{
                cont += 1 + testa_abb(a->dir);
            }
        }
    }

    else if (a->dir == NULL){
        if (a->esq != NULL) {
            if(a->esq->info < a->info){
                cont += testa_abb(a->esq);
            }
            else{
                cont += 1 + testa_abb(a->esq);
            }
        }
    }

    else{
        if(a->dir->info > a->info){
            cont += testa_abb(a->dir);
        }
        else{
            cont += + 1 + testa_abb(a->dir);
        }
        if(a->esq->info < a->info){
            cont += testa_abb(a->esq);
        }
        else{
            cont += + 1 + testa_abb(a->esq);
        }
    }
    return cont;
}

int main(){
  Arv* abb;
  abb = abb_cria();
  abb = abb_insere(abb, 15);
  abb = abb_insere(abb, 10);
  abb = abb_insere(abb, 22);
  abb = abb_insere(abb, 5);
  abb = abb_insere(abb, 12);
  abb = abb_insere(abb, 14);
  abb = abb_insere(abb, 23);
  
  abb_imprime (abb);
  
  int testa_arv = testa_abb(abb);
  
  if(testa_arv == 0){
        printf("\nArvore e ABB!\n");
    }
    else{
        printf("\nArvore nao e ABB!\n");
    }
 
  return 0;
 
}
