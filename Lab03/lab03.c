#include<stdio.h>
#include<string.h>
#include "polinomio.h"

int main() {
  int grau, coef, num_coef;
  char comando[300];
  char polinomio[123];
  char polA[123];
  char polB[123];
  char polC[123];
  Polinomio P[30];
  char c;
  int i;
  for (c = 'A'; c <= 'Z'; c++) {
    inicializa_polinomio(&(P[c-'A']));
  }
  
  while(scanf(" %s", comando) == 1) {
    if (strcmp(comando, "define_coeficiente") == 0) {
      if(scanf(" %s [ %d ] = %d", polinomio, &grau, &coef) != 3) return 1;
      define_coeficiente(P[polinomio[0]-'A'], grau, coef);
      printf("Definido %s [ %d ] = %d .\n", polinomio, grau, coef);

    }else if (strcmp(comando, "le_polinomio") == 0) {
      if(scanf(" %s %d", polinomio, &num_coef) != 2) return 1;
      for (i = 0; i < num_coef; ++i) {
	if (scanf(" %d %d", &grau, &coef) != 2) return 1;
	define_coeficiente(P[polinomio[0]-'A'], grau, coef);
	printf("Definido %s [ %d ] = %d .\n", polinomio, grau, coef);
      }

    }else if (strcmp(comando, "zera") == 0) {
      if(scanf(" %s", polinomio) != 1) return 1;
      zera(P[polinomio[0]-'A']);
      printf("Zerado %c.\n", polinomio[0]);

    }else if (strcmp(comando, "soma") == 0) {
      if(scanf(" %s = %s + %s", polA, polB, polC) != 3) return 1;
      soma(P[polA[0]-'A'], P[polB[0]-'A'], P[polC[0]-'A']);
      printf("Somado %c = %c + %c .\n", polA[0], polB[0], polC[0]);

    }else if (strcmp(comando, "subtrai") == 0) {
      if(scanf(" %s = %s - %s", polA, polB, polC) != 3) return 1;
      subtrai(P[polA[0]-'A'], P[polB[0]-'A'], P[polC[0]-'A']);
      printf("Subtraido %c = %c - %c .\n", polA[0], polB[0], polC[0]);

    /* }else if (strcmp(comando, "multiplica") == 0) { */
    /*   if(scanf(" %s = %s * %s", polA, polB, polC) != 3) return 1; */
    /*   soma(P[polA[0]-'A'], P[polB[0]-'B'], P[polC[0]-'C']); */
    /*   printf("Somado %c = %c + %c .\n", polA[0], polB[0], polC[0]); */

    }else if (strcmp(comando, "imprime") == 0) {
      if(scanf(" %s", polA) != 1) return 1;
      imprime(P[polA[0]-'A']);

    }else {
      printf("Comando invalido.\n");
      return 2;
    }
  }
  for (c = 'A'; c <= 'Z'; c++) {
    desaloca_polinomio(&(P[c-'A']));
  }
  return 0;
}
