//Igor Araujo de Mattos - 2346443

#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;


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

int intermediarios(Arv* r){
    int c = 0;
    if(r == NULL)
        return 0;
    else if(r->dir != NULL){
        c += intermediarios(r->dir);
        if(r->esq != NULL)
            c += intermediarios(r->esq);
        return ++c;
    }
    else{
        return 0;
    }
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
  
  int soma = intermediarios(abb);
  
  abb_imprime(abb);
  
  printf("\n%d\n", soma);
 
  return 0;
 
}
