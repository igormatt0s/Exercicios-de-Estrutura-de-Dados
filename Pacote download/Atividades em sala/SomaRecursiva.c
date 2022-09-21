#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

int plus(int n){
	
	if(n == 1){
		return n;
	}else{
		return n + plus(n - 1);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n, soma;
	
	printf("\nInforme os números inteiros: \n");
	scanf("%d", &n);
	
	soma = plus(n);
  	
  	printf("\nA soma dos %d primeiros números é igual a: %d", n, soma);
  
  return 0;
}
