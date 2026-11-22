#include <iostream>
//#include <stdlib.h>
#include <string.h>

using namespace std;

struct No {
    string nome;
    No* prox;

    No(const string& nome, No* p = nullptr) : nome(nome), prox(p) {}
};

struct Fila{
    No* frente;
    No* atras;

    Fila(No* h = nullptr, No* t = nullptr) : frente(h), atras(t) {}
};

Fila* criarFila() {
    return new Fila();
}

void enfileirar(Fila* f, const string& nome) {
    No* novo = new No(nome);

    if (!f->atras) {
        f->frente = f->atras = novo;
        return;
    }
    f->atras->prox = novo;
    f->atras = novo;
}

void desenfileirar(Fila* f) {
    if (!f->frente) 
        return;

    No* temp = f->frente;
    f->frente = f->frente->prox;

    if (!f->frente) 
        f->atras = nullptr;
    delete temp;
}

void imprimirFila(Fila* f) {
    No* temp = f->frente;
    while (temp) {
        cout << temp->nome << " <- ";
        temp = temp->prox;
    }
    cout << "NULL \n";
}

void liberarMemoria(Fila*& f) {
    if (!f) return;

    No* atual = f->frente;

    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        delete temp;
    }

    delete f;
    f = nullptr;

    std::cout << "Fila liberada!\n";
}

int main() {
    Fila* fila = criarFila();
    enfileirar(fila, "Ana");
    enfileirar(fila, "Bruno");
    enfileirar(fila, "Carlos");
    imprimirFila(fila);

    desenfileirar(fila);
    imprimirFila(fila);

    liberarMemoria(fila);

    return 0;
}
