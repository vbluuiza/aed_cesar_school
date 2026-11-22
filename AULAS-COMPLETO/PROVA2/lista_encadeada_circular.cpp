#include <iostream>

struct NoC {
    int dado;
    NoC* prox;

    NoC(int v) : dado(v), prox(nullptr) {}
};

// inserir no início (circular)
NoC* inserirInicioC(NoC* lista, int valor) {
    NoC* novo = new NoC(valor);

    if (!lista) {
        novo->prox = novo;
        return novo;
    }

    NoC* temp = lista;
    while (temp->prox != lista)
        temp = temp->prox;

    temp->prox = novo;
    novo->prox = lista;

    return novo; // novo vira o início
}

// inserir no fim (circular)
NoC* inserirFimC(NoC* lista, int valor) {
    NoC* novo = new NoC(valor);

    if (!lista) {
        novo->prox = novo;
        return novo;
    }

    NoC* temp = lista;
    while (temp->prox != lista)
        temp = temp->prox;

    temp->prox = novo;
    novo->prox = lista;

    return lista;
}

// imprimir circular
void imprimirC(NoC* lista) {
    if (!lista) return;

    NoC* temp = lista;
    do {
        std::cout << temp->dado << " -> ";
        temp = temp->prox;
    } while (temp != lista);

    std::cout << "(volta ao início)\n";
}

// liberar memória circular
void liberarC(NoC* lista) {
    if (!lista) return;

    NoC* atual = lista->prox;

    while (atual != lista) {
        NoC* temp = atual;
        atual = atual->prox;
        delete temp;
    }

    delete lista;
}

int main() {
    NoC* listaC = nullptr;

    listaC = inserirInicioC(listaC, 1);
    listaC = inserirInicioC(listaC, 2);
    listaC = inserirFimC(listaC, 3);

    imprimirC(listaC);

    liberarC(listaC);

    return 0;
}