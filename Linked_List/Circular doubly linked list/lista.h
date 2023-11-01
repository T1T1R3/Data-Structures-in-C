#ifndef __LISTA_H__
#define __LISTA_H__
/*
 * Implemente as seguintes funcoes utilizando uma lista circular
 * duplamente ligada com no cabeca.*
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

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista);

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor);

/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor);

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista);

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista);

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor);

/* Busca elemento valor na lista. 
   Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor);

/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau, 
   e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau);

/* Imprime a lista na saida padrao, no formato:
   [(1,3),(2,3),(4,2),(3,1),(4,17)]
   em uma linha separada. */
void imprime(Lista lista);

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista);

/* Abaixo uma gambiarra necessaria para o run.codes */
/*#include "lab02.c"*/
#endif
