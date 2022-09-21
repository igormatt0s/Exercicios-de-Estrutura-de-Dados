#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

int dig(float n){
	if(10 > n){
		return 1;
	}else{
		return 1 + dig(n/10);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int digitos;
	float n;
	
	printf("\nInforme os números inteiros: \n");
	scanf("%.2f", &n);
	
	digitos = dig(n);
  	
  	printf("\nA quantidade de digitos é: %.2f", digitos);
  
  return 0;
}
