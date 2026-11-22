#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    No* prox;

    No(const string& n) : nome(n), prox(nullptr) {}
};

struct Fila {
    No* frente;
    No* atras;
    
    Fila() : frente(nullptr), atras(nullptr) {}
};

Fila* criarFila() {
    Fila* f = new Fila();
    return f;
}

void enfileirar(Fila* f, const string& nome) {
    No* novo = new No(nome);

    if (f->atras == nullptr) {
        f->frente = f->atras = novo;
        return;
    }

    f->atras->prox = novo;
    f->atras = novo;
}

void desenfileirar(Fila* f) {
    if (!f->frente) return;

    No* temp = f->frente;
    f->frente = f->frente->prox;
    
    if(!f->frente)
        f->atras = nullptr;
    delete temp;
}


void imprimirFila(Fila* f) {
    No* temp = f->frente;
    while(temp) {
        cout << temp->nome << " <-";
        temp = temp->prox;
    }
    cout << "NULL \n";
}

int main() {
    Fila f;

    enfileirar(&f, "Ana");
    enfileirar(&f, "Carlos");
    enfileirar(&f, "Maria");

    imprimirFila(&f);
}