#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int exp_y(int x, int y) {
    if (y != 0)
        // sum() function calls itself
        return x * exp_y(x,y-1);
    else
        return 1;
}

int sum(int n) {
    if (n != 0)
        // sum() function calls itself
        return n + sum(n-1);
    else
        return n;
}

int fatorial (int n){
  if (n == 0)
    return 1;
  else if (n<0){
    printf("\nErro: fatorial de numero negativo!\n");  
    exit(0);
  }
  return n*fatorial(n-1);
}

//function to count digits
int countDigits(int num)
{
    int count=0;
     
    if(num>0)
        count = 1 + countDigits(num/10);
    else
        return 0;
   
    return count;
}

int main(){

  //Exercício1
  int fat=1;  
  fat=fatorial(5);
  printf("Fatorial: %d\n",fat);

  //Exercício2
  int count=0;    
  count=countDigits(50);
  printf("Total de digitos: %d\n",count);

  //Exercício3
  int soma=0;    
  soma=sum(6);
  printf("Total da soma: %d\n",soma);

  //Exercício4
  int exp_xy=0;    
  exp_xy=exp_y(2,5);
  printf("Total: %d\n",exp_xy);
 
  return 0;
}
