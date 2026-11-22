#include <iostream>
using namespace std;


// 1 - Implementação de uma Lista Encadeada Simples
// 2 - Contagem de Elementos na Lista
// 3 - Inserção Ordenada na Lista Encadeada
// 4 - Reverter uma Lista Encadeada
struct No {
    int valor;
    No* prox;
};

void inserirInicio(No*& lista, int valor) {
    No* novo = new No{valor, lista};
    lista = novo;
}

void inserirFim(No*& lista, int valor) {
    No* novo = new No{valor, nullptr};

    if (lista == nullptr) {
        lista = novo;
        return;
    }

    No* aux = lista;
    while (aux->prox != nullptr) aux = aux->prox;
    aux->prox = novo;
}

void removerElemento(No*& lista, int valor) {
    No* atual = lista;
    No* anterior = nullptr;

    while (atual != nullptr && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == nullptr) return;

    if (anterior == nullptr) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual;
}

void exibir(No* lista) {
    while (lista != nullptr) {
        cout << lista->valor << " -> ";
        lista = lista->prox;
    }
    cout << "NULL\n";
}

int contar(No* lista) {
    int cont = 0;
    while (lista != nullptr) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

void inserirOrdenado(No*& lista, int valor) {
    No* novo = new No{valor, nullptr};

    if (lista == nullptr || valor < lista->valor) {
        novo->prox = lista;
        lista = novo;
        return;
    }

    No* atual = lista;
    while (atual->prox != nullptr && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void reverterLista(No*& lista) {
    No* anterior = nullptr;
    No* atual = lista;
    No* proximo = nullptr;

    while (atual != nullptr) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista = anterior;
}

int main() {
    No* lista = nullptr;

    inserirInicio(lista, 10);
    inserirInicio(lista, 5);
    inserirFim(lista, 20);

    exibir(lista);

    removerElemento(lista, 10);
    exibir(lista);

    return 0;
}