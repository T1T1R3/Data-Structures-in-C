#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef No* Lista;

No* novoNo(int x){
    No* novo = malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = x;

    return novo;
}

void inicializa_lista(Lista* ap_lista){
    *ap_lista = NULL;
}

void insere_fim(Lista* ap_lista, int valor){
    if(*ap_lista){
        No* newValue = novoNo(valor);
        No* aux = *ap_lista;

        while(aux->proximo){
            aux =aux->proximo;
        }
        aux->proximo = newValue;
    }
    else{
        *ap_lista = novoNo(valor);
    }
}

void insere_inicio(Lista* ap_lista, int valor){
    if(*ap_lista){
        No* novo = novoNo(valor);
        novo->proximo = *ap_lista;
        *ap_lista = novo;
    }
    else{
        *ap_lista = novoNo(valor);
    }

}

int remove_fim(Lista* ap_lista){
    if(*ap_lista){
        int val;
        if(!(*ap_lista)->proximo){
            val = (*ap_lista)->valor;
            free(*ap_lista);
            *ap_lista = NULL;
            return val;
        }
        No* aux = *ap_lista;
        No* remove = NULL;
        while(aux->proximo){
            remove = aux;
            aux = aux->proximo;
        }
        val = aux->valor;
        free(aux);
        remove->proximo = NULL;
        return val;

    }
    else{
        return -1;
    }
}

int remove_inicio(Lista* ap_lista){
    if(*ap_lista){
        No* aux = *ap_lista;
        int valor = aux->valor;
        *ap_lista = aux->proximo;
        free(aux);
        aux = NULL;
        return valor;
    }
    else{
        return -1;
    }
}

bool remove_i_esimo(Lista* ap_lista, int i){
    if(*ap_lista){
        if(i > tamanho(*ap_lista)){
                return false;
        }
        if(i == 1){
            remove_inicio(&(*ap_lista));
            return true;
        }
        else{
            No* aux = *ap_lista;
            No* remove = NULL;
            int contador = 1;
            while(aux->proximo && contador != i){
                contador+=1;
                remove = aux;
                aux = aux->proximo;
                if(aux->proximo && contador == i){
                    remove->proximo = NULL;
                    remove->proximo = aux->proximo;
                    free(aux);
                    return true;
                }
                else if(!aux->proximo){
                    remove_fim(&(*ap_lista));
                    return true;
                }

            }
        }

    }
    else{
        return false;
    }
    return false;
}

int recupera_i_esimo(Lista lista, int i){
    if(lista){
        if(i == 1){
            return lista->valor;

        }
        int contador = 1;
        while(lista){
            if(contador > i){
                return -1;
            }
            if(contador == i && lista){
                return lista->valor;
            }
            lista = lista->proximo;
            contador+=1;
        }
        if(!lista)
            return -1;
    }
    else{
        return -1;
    }

    return -1;
}

int tamanho(Lista lista){
    if(lista){
        int contador = 1;
        while(lista->proximo){
            lista = lista->proximo;
            contador+=1;
        }
        return contador;
    }
    else{
        return -1;
    }

}



int remove_ocorrencias(Lista *ap_lista, int valor){
    if(*ap_lista){
        No* aux = *ap_lista;
        int pos = busca(aux, valor);
        int contadorOcrr = 0;
        while(pos != -1){
            contadorOcrr+=1;
            if(pos+1 == 1){
                remove_inicio(&aux);
            }

            remove_i_esimo(&(*ap_lista), pos+1);
            pos = busca(aux,  valor);
        }
        return contadorOcrr;
    }
    else{
        return -1;
    }

}


int busca(Lista lista, int valor){
    if(lista){
        int contador = 0;
        while(lista->valor != valor && lista->proximo){
            lista = lista->proximo;
            contador+=1;
        }
        if(lista->valor == valor){
                return contador;
            }

        else{
            return -1;
        }

    }
    else{
        return -1;
    }
}


void imprime(Lista lista){
    if(lista){
        printf("(");
        while(lista){
            printf("%d", lista->valor);
            if(lista->proximo){
                printf(",");
            }
            lista = lista->proximo;

        }
        printf(")\n");

    }
    else{
        printf("()\n");
    }
}

void desaloca_lista(Lista *ap_lista){
    No* remove = NULL;
    while(*ap_lista){
        remove = *ap_lista;
        *ap_lista = (*ap_lista)->proximo;
        free(remove);
    }
}

