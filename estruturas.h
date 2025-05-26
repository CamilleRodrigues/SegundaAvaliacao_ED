#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula* inserir(int valor, Celula* lista) {
    Celula* novo = (Celula*) malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    }

    Celula* p = lista;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return lista;
}

int contar(Celula* lista) {
    int quantidade = 0;
    for (Celula* p = lista; p != NULL; p = p->prox) {
        quantidade++;
    }
    return quantidade;
}

void exibir(Celula* lista) {
    for (Celula* p = lista; p != NULL; p = p->prox) {
        cout << p->dado << " ";
    }
    cout << endl;
}

bool estaContido(int valor, Celula* lista) {
    for (Celula* p = lista; p != NULL; p = p->prox) {
        if (valor == p->dado) {
            return true;
        }
    }
    return false;
}

Celula* remover(int valor, Celula* lista) {
    Celula* p = lista;
    Celula* ant = NULL;
    while (p != NULL) {
        if (p->dado == valor) {
            if (ant == NULL) {
                Celula* temp = lista;
                lista = lista->prox;
                free(temp);
                return lista;
            } else {
                ant->prox = p->prox;
                free(p);
                return lista;
            }
        }
        ant = p;
        p = p->prox;
    }
    return lista;
}

Celula* removerPares(Celula* lista) {
    Celula* p = lista;
    Celula* ant = NULL;
    while (p != NULL) {
        if (p->dado % 2 == 0) {
            Celula* temp = p;
            if (ant == NULL) {
                lista = p->prox;
                p = lista;
            } else {
                ant->prox = p->prox;
                p = p->prox;
            }
            free(temp);
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return lista;
}

Celula* unirListas(Celula* listaA, Celula* listaB) {
    if (listaA == NULL) return listaB;

    Celula* p = listaA;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = listaB;
    return listaA;
}

void ordenarLista(Celula* listaC) {
    if (!listaC) return;

    bool trocou;
    Celula* p;
    do {
        trocou = false;
        p = listaC;
        while (p->prox != NULL) {
            if (p->dado > p->prox->dado) {
                int temp = p->dado;
                p->dado = p->prox->dado;
                p->prox->dado = temp;
                trocou = true;
            }
            p = p->prox;
        }
    } while (trocou);
}

void deletarLista(Celula* &listaC) {
    Celula* p = listaC;
    while (p != NULL) {
        Celula* temp = p;
        p = p->prox;
        free(temp);
    }
    listaC = NULL;  
}
