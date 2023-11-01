#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

TipoDado defineTipo(int grau, int coef){
    TipoDado novo;
    novo.coef = coef;
    novo.grau = grau;

    return novo;
}

No* novoNo(TipoDado x){
    No* novo = malloc(sizeof(No));
    novo->antec = novo;
    novo->prox = novo;
    novo->valor = x;

    return novo;
}

void define_coeficiente(Polinomio pol, int grau, int coef){
    TipoDado novoTipo = defineTipo(grau, coef);
    No* inicial = pol;
    if(coef != 0){
            
    No* novo = novoNo(novoTipo);
    if(pol){
        if(pol->prox == pol){
            pol->prox = novo;
            pol->antec = novo;
            novo->prox = pol;
            novo->antec = pol;
        }
        else if(pol->prox == pol->antec){
            No* aux = pol->prox;
            if(aux->valor.grau < novoTipo.grau){
                aux->prox = novo;

                aux->antec = inicial;
                inicial->prox = aux;

                inicial->antec = novo;

                novo->prox = inicial;
                novo->antec = aux;
            }
            else{
               novo->prox = aux;
               novo->antec = inicial;

               aux->antec = novo;
               inicial->prox = novo;
            }
        }
        else{
            if(novoTipo.grau < pol->prox->valor.grau && novoTipo.grau > 0){
                No* aux = pol->prox;
                inicial->prox = novo;
                novo->prox = aux;
                novo->antec = inicial;

            }
            else{
                pol = pol->prox;
                while(pol->valor.grau < novoTipo.grau && pol != inicial){
                    pol = pol->prox;
                }
                No* aux = pol->antec;
                novo->prox = aux->prox;
                novo->antec = aux;

                aux->prox = novo;
                pol->antec = novo;
            }

        }

    }
    }
}

void inicializa_polinomio(Polinomio* ap_pol){
    No* novo = malloc(sizeof(No));
    TipoDado head = defineTipo(-1,-1);
    novo->valor = head;
    novo->prox = novo;
    novo->antec = novo;
    *ap_pol = novo;
}

void printCoef(Polinomio pol){
    printf("(%d,%d)", pol->valor.grau, pol->valor.coef);
}



void imprime(Polinomio pol){
    if(pol){
        No* inicial = pol;
        printf("[");
        pol = pol->prox;
        if(pol == inicial){
            printf("()");
        }
        else{
            while(pol != inicial){
                printCoef(pol);
                if(pol->prox != inicial){
                    printf(",");
                }
                pol = pol->prox;
            }
        }
        printf("]\n");
    }
}

void desaloca_polinomio(Polinomio *ap_pol){
    No* inicial = *ap_pol;
    No* atual = inicial->prox;
    No* remove = NULL;
    while(atual != inicial){
        remove = atual;
        atual = atual->prox;
        free(remove);
        remove = NULL;
    }
    free(atual);
    atual = NULL;
}

void remove0(Polinomio a){
    No* inicial = a;
    No* remove = NULL;
    No* aux = NULL;
    a = a->prox;

    while(a != inicial){
        if(a->valor.coef == 0){
            a = a->antec;
            remove = a->prox;
            aux = remove->prox;
            a->prox = aux;
            aux->antec = a;

            free(remove);
            remove = NULL;
        }
        a = a->prox;
    }
}

void zera(Polinomio pol){
    No* inicial = pol;
    No* remove = pol->prox;
    No* aux = remove;

    while(remove != inicial){
        aux = aux->prox;
        free(remove);
        remove = NULL;
        remove = aux;
    }


    TipoDado zerado = defineTipo(0, 0);
    No* novo = novoNo(zerado);

    pol->prox = novo;
    pol->antec = novo;
    novo->prox = pol;
    novo->antec = pol;
}

void buscaPos(Polinomio a, int grau, int coef, int verificador){
    No* inicial = a;
    a = a->prox;
    if(verificador == 1){
        while(a->valor.grau != grau && a != inicial){
            a = a->prox;
        }
        if(a->valor.grau == grau){
            a->valor.coef+=coef;
        }
        else{
            define_coeficiente(a, grau, coef);
        }
    }
    if(verificador == 2){
        while(a->valor.grau != grau && a != inicial){
            a = a->prox;
        }
        if(a->valor.grau == grau){
            a->valor.coef-=coef;
        }
        else{
            define_coeficiente(a, grau, coef);
        }
    }
}

void soma(Polinomio res, Polinomio a, Polinomio b){
    if(a && b && res){
        No* inicialA = a;
        No* inicialB = b;

        int soma = 0;

        a = a->prox;
        b = b->prox;
            while(a != inicialA || b != inicialB){
            if(a->valor.grau < b->valor.grau && a->valor.grau != -1){
                buscaPos(res, a->valor.grau, a->valor.coef, 1);
                a = a->prox;
            }
            else if(b->valor.grau < a->valor.grau && b->valor.grau != -1){
                buscaPos(res, b->valor.grau, b->valor.coef, 1);
                b = b->prox;
            }
            else if(b->valor.grau == a->valor.grau){
                soma = b->valor.coef + a->valor.coef;
                buscaPos(res, a->valor.grau, soma, 1);
                a = a->prox;
                b = b->prox;
            }
            else if(a->valor.grau == -1 && b->valor.grau != -1){
                buscaPos(res, b->valor.grau, b->valor.coef, 1);
                b = b->prox;
            }
            else if(b->valor.grau == -1 && a->valor.grau != -1){
                buscaPos(res, a->valor.grau, a->valor.coef, 1);
                a = a->prox;
            }
        }   
        remove0(res);  
    }
}

void subtrai(Polinomio res, Polinomio a, Polinomio b){
    if(a && b && res){
        No* inicialA = a;
        No* inicialB = b;

        int sub = 0;

        a = a->prox;
        b = b->prox;

        while(a != inicialA || b != inicialB){
            if(a->valor.grau < b->valor.grau && a->valor.grau != -1){
                buscaPos(res, a->valor.grau, a->valor.coef, 2);
                a = a->prox;
            }
            else if(b->valor.grau < a->valor.grau && b->valor.grau != -1){
                buscaPos(res, b->valor.grau, 0-b->valor.coef, 2);
                b = b->prox;
            }
            else if(b->valor.grau == a->valor.grau){
                sub = a->valor.coef - b->valor.coef;
                buscaPos(res, a->valor.grau, sub, 2);
                a = a->prox;
                b = b->prox;
            }
            else if(a->valor.grau == -1 && b->valor.grau != -1){
                buscaPos(res, b->valor.grau, b->valor.coef, 2);
                b = b->prox;
            }
            else if(b->valor.grau == -1 && a->valor.grau != -1){
                buscaPos(res, a->valor.grau, a->valor.coef, 2);
                a = a->prox;
            }
        } 
        remove0(res);  
    }

}
