#include <iostream>
using namespace std;

struct No {
    int dado;
    No* prox;

    No(int n) : dado(n), prox(nullptr) {}
};

No* empilhar(No* topo, int valor) {
    No* novo = new No(valor);
    novo->prox = topo;
    return novo;
}

No* desempilhar(No* topo, int& valor) {
    if (!topo) return nullptr;

    No* temp = topo;
    valor = topo->dado;
    topo = topo->prox;

    delete temp;
    return topo;
}

void imprimir(No* topo) {
    while (topo) {
        cout << topo->dado << " -> ";
        topo = topo->prox;
    }
    cout << "NULL\n";
}

int main() {
    No* topo = nullptr;

    topo = empilhar(topo, 10);
    topo = empilhar(topo, 20);
    topo = empilhar(topo, 30);

    imprimir(topo);

    int removido;
    topo = desempilhar(topo, removido);

    cout << "Removido: " << removido << endl;
    imprimir(topo);

    while (topo) {
        topo = desempilhar(topo, removido);
    }

    return 0;
}