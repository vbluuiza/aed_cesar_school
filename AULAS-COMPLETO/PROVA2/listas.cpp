#include <iostream>
using namespace std;

struct No {
    int dado;
    No* prox;

    No(int valor) : dado(valor), prox(nullptr) {}
};

// Inserir no início da lista
No* inserirInicio(No* lista, int valor) {
    No* novo = new No(valor);
    novo->prox = lista;
    return novo;
}

void removerDuplicados(No* lista) {
    No* atual = lista;

    while (atual != nullptr && atual->prox != nullptr) {

        if (atual->dado == atual->prox->dado) {
            No* temp = atual->prox;

            atual->prox = temp->prox;

            delete temp;
        } 
        else {
            atual = atual->prox;
        }
    }
}

// Inserir no final da lista
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

// Inserir antes de um valor buscado
No* inserirMeio(No* lista, int valorNovo, int valorBusca) {
    No* novo = new No(valorNovo);

    if (!lista)
        return novo;

    No* temp = lista;

    while (temp->prox && temp->prox->dado != valorBusca) {
        temp = temp->prox;
    }

    novo->prox = temp->prox;
    temp->prox = novo;

    return lista;
}

// Imprimir a lista
void imprimirLista(No* lista) {
    No* temp = lista;

    while (temp) {
        cout << temp->dado << " -> ";
        temp = temp->prox;
    }

    cout << "NULL\n";
}

// Liberar memória
void liberarLista(No* lista) {
    while (lista) {
        No* temp = lista;
        lista = lista->prox;
        delete temp;
    }
}

int main() {
    No* lista = nullptr;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);

    cout << "Antes:\n";
    imprimirLista(lista);

    removerDuplicados(lista);

    cout << "Depois:\n";
    imprimirLista(lista);

    return 0;
}