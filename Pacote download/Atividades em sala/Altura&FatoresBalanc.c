#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
{
    int info;
    int fbal;
    struct Arvore* esq;
    struct Arvore* dir;
}Arv;

Arv* abb_cria(void){
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

int calcAlt(Arv* r){
	int d = 0;
	int e = 0;
	if(r == NULL)
		return 0;
	else{
		if(r->dir != NULL)
			d += calcAlt(r->dir);
		else
			e += calcAlt(r->esq);

		if(d > e)
			return d;
		else{
			return e;
		}
	}
}

int fatorbal(Arv* r){
	if(r != NULL){
		fatorbal(r->esq);
		
}

void imprimefbal(int fbal){
		//printf("\nO fator de balanceamento do no: ", fbal);
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
	
	int altura = calcAlt(abb);
	printf("\nA altura eh: ", &altura);
	
	abb_imprime(abb);
	
	fatorbal(abb);
	
	return 0;
}
