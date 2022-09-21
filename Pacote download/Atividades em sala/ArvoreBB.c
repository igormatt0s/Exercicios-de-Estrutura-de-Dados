#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* abb_cria (void)
{
   return NULL;
}

void abb_imprime (Arv* a)
{
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca (Arv* r, int v)
{
    if (r == NULL ) return NULL ;
    else if (r->info > v) return abb_busca (r->esq, v);
    else if (r->info < v) return abb_busca (r->dir, v);
    else return r;
}

Arv* abb_insere (Arv* a, int v)
{
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
         a->esq = abb_insere(a->esq,v);
    else // v > a->info
         a->dir = abb_insere(a->dir,v);
    return a;
}

       

Arv* abb_retira (Arv* r, int v){
    if (r == NULL)
       return NULL;
    else if (r->info > v)
         r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
         r->dir = abb_retira(r->dir, v);
    else {// achou o n� a remover
     //n� sem filhos
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        // n� s� tem filho � direita
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        // s� tem filho � esquerda
        else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        // n� tem os dois filhos
        else {
            Arv* f = r->esq;
            while (f->dir != NULL) {
                  f = f->dir;
            }
            r->info = f->info; // troca as informa��es
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
   }
   return r;
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
  
  abb = abb_retira(abb, 15);
  abb_imprime (abb);
 
  return 0;
 
}
