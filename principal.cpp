#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "estruturas.h"

int main() {
    srand(time(NULL));

    Celula* listaA = NULL;
    Celula* listaB = NULL;
    Celula* listaC = NULL;

    for (int i = 0; i < 30; i++) {
        listaA = inserir(rand() % 100, listaA);
        listaB = inserir(rand() % 100, listaB);
    }

    cout << "Lista A: " << contar(listaA);
    exibir(listaA);
    
    cout << "Lista B: " << contar(listaB);
    exibir(listaB);

    int valor;
    cout << "Digite um valor para verificar na lista A: ";
    cin >> valor;

    cout << valor << (estaContido(valor, listaA) ? " está " : " não está ") << "na lista A.\n";

    listaA = removerPares(listaA);
    cout << "Lista A após remover pares: ";
    exibir(listaA);

    listaC = unirListas(listaA, listaB);
    cout << "Lista C após concatenar as listas A e B: ";
    exibir(listaC);

    ordenarLista(listaC);
    cout << "Lista ordenada:\n";
    exibir(listaC);

    deletarLista(listaC);

    return 1;
}
