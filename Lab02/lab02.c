#include<stdio.h>
#include<string.h>
#include "lista.h"

int main() {
  int conta, posicao, grau, coef;
  char comando[300];
  Lista l;
  TipoDado dado;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      insere_inicio(l, dado);
      printf("Inserido (%d,%d) no inicio.\n", dado.grau, dado.coef);
    }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      insere_fim(l, dado);
      printf("Inserido (%d,%d) no fim.\n", dado.grau, dado.coef);
    }else if (strcmp(comando, "remove_inicio") == 0) {
      dado = remove_inicio(l);
      printf("Removido (%d,%d) do inicio.\n", dado.grau, dado.coef);      
    }else if (strcmp(comando, "remove_fim") == 0) {
      dado = remove_fim(l);
      printf("Removido (%d,%d) do fim.\n", dado.grau, dado.coef);      
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      conta = remove_ocorrencias(l, dado);
      printf("Removidas %d ocorrencias de (%d,%d).\n", conta, dado.grau, dado.coef);      
    }else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d%d", &dado.grau, &dado.coef) != 2) return 1;
      posicao = busca(l, dado);
      if (posicao == -1) {
	printf("Valor (%d,%d) nao encontrado na lista.\n", dado.grau, dado.coef);
      }else {
	printf("Valor (%d,%d) encontrado na posicao %d.\n", dado.grau, dado.coef, posicao);     
      }
    }else if (strcmp(comando, "coeficiente_do_grau") == 0) {
      if(scanf("%d", &grau) != 1) return 1;
      coef = coeficiente_do_grau(l, grau);
      printf("Coeficiente de grau %d = %d.\n", grau, coef);
    }else if (strcmp(comando, "imprime") == 0) {
      imprime(l);
    }else {
      printf("Comando invalido.\n");
      return 2;
    }
  }
  desaloca_lista(&l);
  return 0;
}
