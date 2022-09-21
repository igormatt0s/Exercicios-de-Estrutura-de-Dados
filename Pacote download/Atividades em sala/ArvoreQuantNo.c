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
    else {// achou o nó a remover
     //nó sem filhos
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        // nó só tem filho à direita
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        // só tem filho à esquerda
        else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        // nó tem os dois filhos
        else {
            Arv* f = r->esq;
            while (f->dir != NULL) {
                  f = f->dir;
            }
            r->info = f->info; // troca as informações
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
   }
   return r;
}

int abb_quantNo(Arv* r){
	int c = 0;
	if(r == NULL)
		return 0;
	else{
		c += abb_quantNo(r->dir);
		c += abb_quantNo(r->esq);
		return ++c;
	}
	
}

int abb_somaNo(Arv* r){
	int c = 0;
	if(r == NULL)
		return 0;
	else{
		c += abb_somaNo(r->dir) + abb_somaNo(r->esq);
		c += r->info;
		return c;
	}
	
}

int abb_maioresNo(Arv* r, int x){
	int c = 0;
	if(r == NULL)
		return 0;
	
	c += abb_maioresNo(r->dir, x);
	c += abb_maioresNo(r->esq, x);
	
	if(r->info > x)
		return ++c;
	else
		return c;
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
  
  int cont = abb_quantNo(abb);
  
  int soma = abb_somaNo(abb);
  
  //abb = abb_retira(abb, 15); 
  abb_imprime (abb);
  printf("\n%d\n", cont);
  
  printf("\n%d\n", soma);
 
 int maiores = abb_maioresNo(abb, 5);
 
 printf("\n%d\n", maiores);
 
  return 0;
 
}
