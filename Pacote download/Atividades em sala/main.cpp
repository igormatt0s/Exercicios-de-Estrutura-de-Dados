
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
  int hora;
  int minutos;
  int segundos;  
}Tempo;

typedef struct{
  int num;
  char marca[20];
  Tempo* entrada;
  Tempo* saida;
}Estacionamento;

int main() {
  Tempo* tempo;
  Estacionamento* carro1;
  carro1 = (Estacionamento*) malloc(sizeof(Estacionamento));
  carro1->entrada = (Tempo*) malloc(sizeof(Tempo));
  carro1->saida = (Tempo*) malloc(sizeof(Tempo));

  carro1->num = 123456;
  strcpy(carro1->marca, "Honda");
  
  carro1->entrada->hora = 13;
  carro1->entrada->minutos = 30;
  carro1->entrada->segundos = 15;
  
  carro1->saida->hora = 14;
  carro1->saida->minutos = 30;
  carro1->saida->segundos = 15;

  printf("%d\n%s\n%d:%d:%d\n%d:%d:%d", carro1->num, carro1->marca, carro1->entrada->hora, carro1->entrada->minutos, carro1->entrada->segundos, carro1->saida->hora, carro1->saida->minutos, carro1->saida->segundos);
  
  /*
  printf("%d\n", (int) sizeof(Estacionamento));
  printf("%d\n", (int) sizeof(Tempo));
  printf("%d\n", (int) sizeof(Estacionamento*));
  printf("%d\n", (int) sizeof(Tempo*));
  */
  
  free(carro1->entrada);
  free(carro1->saida);
  free(carro1);
  
return 0;
}
