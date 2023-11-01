#ifndef __LISTA_H__
#define __LISTA_H__
/*
 * Implemente as seguintes funcoes utilizando uma lista ligada. 
 * Voce deve implementar uma versao sem no cabeca. 
 */
typedef struct No_aux {
  int valor;
  struct No_aux * proximo;
} No;
typedef No * Lista;

typedef enum{false, true} bool;

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista);

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor);

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor);

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista);

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
int remove_inicio(Lista * ap_lista);

/* Remove o i-ésimo elemento da lista, caso ele exista. Retorna se o elemento 
foi removido. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
bool remove_i_esimo(Lista * ap_lista, int i);

/* Retorna o valor do i-ésimo elemento da lista, caso ele exista. 
Retorna -1 caso contrário. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
int recupera_i_esimo(Lista lista, int i);

/* Retorna o tamanho da lista. */
int tamanho(Lista lista);

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor);

/* Busca elemento valor na lista. 
   Retorna a posição na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado.
*/
int busca(Lista lista, int valor);

/* Imprime a lista na saida padrao, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
 */
void imprime(Lista lista);

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista);


/* Abaixo uma gambiarra necessaria para o run.codes */
#include "lab01.c"
#endif
