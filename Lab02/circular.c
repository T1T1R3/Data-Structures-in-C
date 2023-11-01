#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


No* novoNo(TipoDado x){
    No* novo = malloc(sizeof(No));
    novo->prox = novo;
    novo->antec = novo;
    novo->valor = x;

    return novo;
}

TipoDado novoTipo(int x, int y){
    TipoDado teste;
    teste.coef = x;
    teste.grau = y;

    return teste;
}

void inicializa_lista(Lista * ap_lista){
    *ap_lista = novoNo(novoTipo(-1, -1));
}

void imprime(Lista lista){
    printf("[");
    No* inicial = lista;
    lista = lista->prox;

    while(lista != inicial){
        printf("(%d,%d)", lista->valor.grau, lista->valor.coef);
        if(lista->prox != inicial){
            printf(",");
        }
        lista = lista->prox;
    }

    printf("]\n");

}

void insere_fim(Lista ap_lista, TipoDado valor){
    if(ap_lista){
        No* inicial = ap_lista;
        No* novo = novoNo(valor);

        No* aux = inicial->antec;
        if(ap_lista->prox == ap_lista){
            ap_lista->prox = novo; //1
            ap_lista->antec = novo; //3
            novo->antec = ap_lista; //2
            novo->prox = ap_lista; //4
        }
        else{
            aux->prox = novo;

            inicial->antec = novo;

            novo->prox = inicial;
            novo->antec = aux;
        }
    }
}

void insere_inicio(Lista ap_lista, TipoDado valor){
    if(ap_lista){
        No* inicial = ap_lista;
        No* aux = ap_lista->prox;
        No* novo = novoNo(valor);

        novo->prox = inicial->prox;
        novo->antec = inicial;

        inicial->prox = novo;
        aux->antec = novo;
    }
}

int confirmador(TipoDado valor1, TipoDado valor2){
    if(valor1.coef == valor2.coef && valor1.grau == valor2.grau){
        return 1;
    }
    else{
        return 0;
    }
}

int busca(Lista lista, TipoDado valor){
    if(lista){
        No* inicial = lista;
        lista = lista->prox;
        int contador = 0;;
        if(confirmador(valor, lista->valor) != 0){
            return 0;
        }
        lista = lista->prox;
        while(lista != inicial){
            contador += 1;
            if(confirmador(valor, lista->valor) != 0){
                return contador;
            }
            lista = lista->prox;
        }
        if(lista == inicial){
            return -1;
        }
        return 0;
    }
    else{
        return 0;
    }
}

int coeficiente_do_grau(Lista lista, int grau){
    if(lista){
        if(lista->valor.grau == grau){
            return lista->valor.coef;
        }
        else{
            No* inicial = lista;
            lista = lista->prox;
            if(lista->valor.grau == grau){
                return lista->valor.coef;
            }
            while(lista != inicial){
                if(lista->valor.grau == grau){
                    return lista->valor.coef;
                }
                lista = lista->prox;
            }
            if(lista == inicial){
                return 0;
            }
            return 0;
        }
    }
    else{
        return 0;
    }
}

TipoDado remove_fim(Lista ap_lista){
    TipoDado valor = novoTipo(-1,-1);
    if(ap_lista){
        No* inicial = ap_lista;
        if(ap_lista->prox == ap_lista){
            valor = inicial->valor;
            free(ap_lista);
            ap_lista = NULL;
            return valor;
        }
        No* primeiro = inicial->prox;

        if(primeiro->prox == inicial){
            valor = primeiro->valor;
            free(primeiro);
            primeiro = NULL;
            inicial->prox = inicial;
            inicial->antec = inicial;
            return valor;
        }

        else{
            No* ultimo = inicial->antec->antec;
            No* remove = NULL;
            remove = ultimo->prox;
            ultimo->prox = remove->prox;
            inicial->antec = ultimo;

            valor = remove->valor;

            free(remove);
            remove = NULL;

            return valor;
        }

    }
    return valor;
}

TipoDado remove_inicio(Lista ap_lista){
    TipoDado valor = novoTipo(-1,-1);
    if(ap_lista){
        No* inicial = ap_lista;

        if(ap_lista->prox == inicial){
            valor = ap_lista->valor;
            free(ap_lista);
            ap_lista = NULL;

            return valor;
        }
        if(ap_lista->prox->prox == inicial){
            valor = inicial->prox->valor;
            free(inicial->prox);
            inicial->prox = inicial;

            return valor;

        }

        else{
            No* primeiro = inicial->prox->prox;
            No* remove = inicial->prox;

            inicial->prox = primeiro;
            primeiro->antec = inicial;

            valor = remove->valor;

            free(remove);
            remove = NULL;

            return valor;
        }
    }
    return valor;
}


void removeNo(Lista anterior, Lista proximo){
    No* remove = anterior->prox;
    anterior->prox = proximo;
    proximo->antec = anterior;

    free(remove);
    remove = NULL;
}

int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    if(ap_lista){
        No* inicial = ap_lista;
        int contador = 0;

        if(ap_lista->prox == inicial){
            return 0;
        }

        if(confirmador(valor, ap_lista->prox->valor) != 0){
            remove_inicio(ap_lista);
            contador+=1;
        }
        

        ap_lista = ap_lista->prox;


        while(ap_lista != inicial){
            if(confirmador(valor, ap_lista->valor) != 0){
                removeNo(ap_lista->antec, ap_lista->prox);
                contador+=1;
            }
            ap_lista = ap_lista->prox;
        }

        return contador;
    }
    else{
        return 0;
    }
}


void desaloca_lista(Lista *ap_lista){
    if(ap_lista){
        No* inicial = *ap_lista;
        No* remove = NULL;
        *ap_lista = (*ap_lista)->prox;
        while(*ap_lista != inicial){
            remove = *ap_lista;
            *ap_lista = (*ap_lista)->prox;
            free(remove);
            remove = NULL;
        }

        if(*ap_lista == inicial){
            free(*ap_lista);
            *ap_lista = NULL;
        }

    }

}

