//Igor Araujo de Mattos - 2346443

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct Arvore{
    int info;
    int fbal;
    struct Arvore* esq;
    struct Arvore* dir;
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

Arv* abb_busca(Arv* r, int v){
    if(r == NULL ) return NULL ;
    else if(r->info > v) return abb_busca(r->esq, v);
    else if(r->info < v) return abb_busca(r->dir, v);
    else return r;
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

void print2DTree(Arv *root, int space){
    if (root == NULL)
        return;
        
    space += COUNT;

    print2DTree(root->dir, space);
    int i = 0;
        for(i = COUNT; i < space; i++)
          printf(" ");
      
    printf("%d\n", root->info);

    print2DTree(root->esq, space);
}

void print2DFbal(Arv *root, int space){
    if (root == NULL)
        return;
        
    space += COUNT;

    print2DFbal(root->dir, space);
    int i = 0;
        for (i = COUNT; i < space; i++)
          printf(" ");
          
    printf("%d\n", root->fbal);

    print2DFbal(root->esq, space);
}

int calculaAltura(Arv* a){
  int esq,dir;
  if(a==NULL){
      return -1;
  }else{  
    esq = calculaAltura(a->esq);
    dir = calculaAltura(a->dir);
  }  

  if(esq>dir)
      return esq + 1;
  else
    return dir + 1;
}
void calculaFbal(Arv* a){
    if(a!=NULL){
      calculaFbal(a->esq);
      a->fbal = calculaAltura(a->esq) - calculaAltura(a->dir);
      calculaFbal(a->dir);
    }
}

int main(){
    Arv* abb;
    abb = abb_cria();
    abb = abb_insere(abb, 10);
    abb = abb_insere(abb, 8);
    abb = abb_insere(abb, 12);
    abb = abb_insere(abb, 6);
    
    print2DTree(abb, 0);
    calculaFbal(abb);
    printf("\n\n");
    print2DFbal(abb, 0);
    
    return 0;
}
