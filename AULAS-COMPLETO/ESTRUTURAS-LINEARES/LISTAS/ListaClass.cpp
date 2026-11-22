#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;

    No(int v) : valor(v), prox(nullptr) {}
};


class Lista {
private: // Só a própria classe acessa
    No* head;

public: // Qualquer um pode acessar
    Lista() {   // Construtor, executa quando cria a lista
        head = nullptr;
    }


    void inserirInicio(int valor) { // Método 1
        No* novo = new No(valor);
        novo->prox = head;
        head = novo;
    }


    void inserirFim(int valor) {
        No* novo = new No(valor);

        if (!head) {
            head = novo;
            return;
        }

        No* atual = head;
        while (atual->prox) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }


    void remover(int valor) {
        No** atual = &head;

        while (*atual && (*atual)->valor != valor) {
            atual = &(*atual)->prox;
        }

        if (*atual) {
            No* temp = *atual;
            *atual = temp->prox;
            delete temp;
        }
    }


    void imprimir() {
        No* atual = head;

        while (atual) {
            cout << atual->valor << " -> ";
            atual = atual->prox;
        }

        cout << "NULL" << endl;
    }

    ~Lista() {  // Destruidor (Chamado automaticamente)
        No* atual = head;

        while (atual) {
            No* temp = atual;
            atual = atual->prox;
            delete temp;
        }
    }
};

int main() {
    Lista lista;

    lista.inserirInicio(10);
    lista.inserirInicio(5);
    lista.inserirFim(20);
    lista.inserirFim(30);
    lista.inserirFim(50);

    lista.imprimir();

    lista.remover(10);

    lista.imprimir();


    return 0;
}