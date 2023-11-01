#ifndef __POLINOMIO_H__
#define __POLINOMIO_H__
/*
 * Implemente as seguintes funcoes de um Tipo Abstrato de Dados de um 
 * Polinômio de coeficientes inteiros. Utilize uma lista circular
 * duplamente ligada com no cabeca, mantendo sempre os coeficientes 
 * ordenados por grau. Somente os coeficientes nao zero devem ser armazenados.
 */

typedef struct {
  int grau;
  int coef;
}TipoDado;

typedef struct No_aux {
  TipoDado valor;
  struct No_aux * antec;  
  struct No_aux * prox;
} No;
typedef No * Lista;
typedef Lista Polinomio;

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol);

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef);

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol);

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b);

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b);


/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol);

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol);

/* Abaixo uma gambiarra necessaria para o run.codes */
#include "lab03.c"
#endif
