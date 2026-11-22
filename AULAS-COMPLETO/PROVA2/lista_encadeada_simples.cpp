#include <iostream>
using namespace std;

struct No {
    int dado;
    No* prox;

    No(int v) : dado(v), prox(nullptr) {}
};

// inserir no início
No* inserirInicio(No* lista, int valor) {
    No* novo = new No(valor);
    novo->prox = lista;
    return novo;
}

// inserir no fim
No* inserirFim(No* lista, int valor) {
    No* novo = new No(valor);

    if (!lista)
        return novo;

    No* temp = lista;
    while (temp->prox)
        temp = temp->prox;

    temp->prox = novo;
    return lista;
}

// imprimir
void imprimir(No* lista) {
    while (lista) {
        cout << lista->dado << " -> ";
        lista = lista->prox;
    }
    cout << "NULL\n";
}

// liberar memória
void liberar(No* lista) {
    while (lista) {
        No* temp = lista;
        lista = lista->prox;
        delete temp;
    }
}

int main() {
    No* lista = nullptr;

    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirFim(lista, 30);

    imprimir(lista);

    liberar(lista);
   
    return 0;
}