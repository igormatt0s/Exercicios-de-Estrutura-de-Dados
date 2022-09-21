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

Arv* avl_cria(void){
   return NULL;
}

void avl_imprime(Arv* a){
    if(a != NULL){
        avl_imprime(a->esq);
        printf("%d\n",a->info);
        avl_imprime(a->dir);
    }
}

Arv* avl_insere(Arv* a, int v){
    if(a!=NULL){
        if(a->info>v){
            a->esq = avl_insere(a->esq,v);
        }
        if(a->info<v){
            a->dir = avl_insere(a->dir,v);
        }
        
        if(calculaAltura(a->esq) - calculaAltura(a->dir) == 2 || calculaAltura(a->esq) - calculaAltura(a->dir) == -2){
		    a = balanceia(a); 
		}		
		return a;	
        
    }
    else{
        Arv* b = (Arv*)malloc(sizeof(Arv));
        b->info = v;
        b->esq = (Arv*)NULL;
        b->dir = (Arv*)NULL;
        b->fbal = 0;
        return b;
    }
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
int balanceia(Arv* a){
    if(a!=NULL){
        a->esq = balanceia(a->esq);
        a->dir = balanceia(a->dir);
        if(calculaAltura(a->esq) - calculaAltura(a->dir) == 2 || calculaAltura(a->esq) - calculaAltura(a->dir) == -2){
            if(a->esq != NULL){
                if(calculaAltura(a->esq) - calculaAltura(a->dir) == 2 && calculaAltura(a->esq->esq) - calculaAltura(a->esq->dir) > 0){
                    Arv* temp;
                    Arv* q;
                    q = a->esq;
                    temp = q->dir;
                    q->dir = a;
                    a->esq = temp;
                    a = q;
                    return a;
                }
                if(calculaAltura(a->esq) - calculaAltura(a->dir) == 2 && calculaAltura(a->esq->esq) - calculaAltura(a->esq->dir) < 0){
                    Arv* temp;
                    Arv* q;
                    q = a->esq->dir;
                    temp = q->esq;
                    q->esq = a->esq;
                    a->esq->dir = temp;
                    a->esq = q;
                    q = a->esq;
                    temp = q->dir;
                    q->dir = a;
                    a->esq = temp;
                    a = q;
                    return a;
                }
            }
            if(a->dir != NULL){
                if(calculaAltura(a->esq) - calculaAltura(a->dir) == -2 && calculaAltura(a->dir->esq) - calculaAltura(a->dir->dir) < 0){
                    Arv* temp;
                    Arv* q;
                    q = a->dir;
                    temp = q->esq;
                    q->esq = a;
                    a->dir = temp;
                    a = q;
                    return a;
                }
                if(calculaAltura(a->esq) - calculaAltura(a->dir) == -2 && calculaAltura(a->dir->esq) - calculaAltura(a->dir->dir) > 0){
				    Arv* temp;
                    Arv* q;
                    q = a->dir->esq;
                    temp = q->dir;
                    q->dir = a->dir;
                    a->dir->esq = temp;
                    a->dir = q;
                    q = a->dir;
                    temp = q->esq;
                    q->esq = a;
                    a->dir = temp;
                    a = q;
                    return a;
                }
            }
        }
        else
            return a;
    }
    else
        return a;
}

int main(){
    Arv* avl;
    avl = avl_cria();
    avl = avl_insere(avl, 10);
    avl = avl_insere(avl, 8);
    avl = avl_insere(avl, 12);
    avl = avl_insere(avl, 6);
    avl = avl_insere(avl, 4);
    avl = avl_insere(avl, 14);
    avl = avl_insere(avl, 16);
    
    print2DTree(avl, 0);
    calculaFbal(avl);
    
    printf("\n\n");
    print2DFbal(avl, 0);
    
    return 0;
}
