#include<stdio.h>
#include<string.h>
#include "lista.h"

int main() {
  int x, conta, posicao;
  char comando[300];
  Lista l;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_inicio(&l, x);
      printf("Inserido %d no inicio.\n", x);
    }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_fim(&l, x);
      printf("Inserido %d no fim.\n", x);
    }else if (strcmp(comando, "remove_inicio") == 0) {
      x = remove_inicio(&l);
      printf("Removido %d do inicio.\n", x);      
    }else if (strcmp(comando, "remove_fim") == 0) {
      x = remove_fim(&l);
      printf("Removido %d do fim.\n", x);      
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      conta = remove_ocorrencias(&l, x);
      printf("Removidas %d ocorrencias de %d.\n", conta, x);      
    }else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      posicao = busca(l, x);
      if (posicao == -1) {
	printf("Valor %d nao encontrado na lista.\n", x);
      }else {
	printf("Valor %d encontrado na posicao %d.\n", x, posicao);            
      }
    }else if (strcmp(comando, "remove_i_esimo") == 0) {
      if(scanf("%d", &posicao) != 1) return 1;
      bool sucesso = remove_i_esimo(&l, posicao);
      if (sucesso) {
        printf("Elemento na posicao %d removido.\n", posicao);
      } else {
        printf("Elemento na posicao %d nao removido.\n", posicao);
      }
    }else if (strcmp(comando, "recupera_i_esimo") == 0) {
      if(scanf("%d", &posicao) != 1) return 1;
      int tam = tamanho(l);
      if(posicao <= tam) {
        int valor = recupera_i_esimo(l, posicao);
        printf("Valor %d do elemento na posicao %d.\n", valor, posicao);
      } else {
        printf("Posicao %d não existe na lista de tamanho %d.\n", posicao, tam);
      }
    }else if (strcmp(comando, "tamanho") == 0) {
      printf("Lista com tamanho %d.\n", tamanho(l));      
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
