#include <iostream>
using namespace std;

//  Inverter uma Fila Usando uma Pilha 
struct No {
    int dado;
    No* proximo;
    No(int x) : dado(x), proximo(nullptr) {}
};

struct Fila {
    No* inicio;
    No* fim;
    
    Fila() : inicio(nullptr), fim(nullptr) {}
    
    void push(int x) {
        No* novo = new No(x);
        if (fim == nullptr) {
            inicio = fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
    }
    
    void pop() {
        if (inicio != nullptr) {
            No* temp = inicio;
            inicio = inicio->proximo;
            if (inicio == nullptr) fim = nullptr;
            delete temp;
        }
    }
    
    int front() {
        return inicio->dado;
    }
    
    bool empty() {
        return inicio == nullptr;
    }
    
    ~Fila() {
        while (!empty()) pop();
    }
};

struct Pilha {
    No* topo;
    
    Pilha() : topo(nullptr) {}
    
    void push(int x) {
        No* novo = new No(x);
        novo->proximo = topo;
        topo = novo;
    }
    
    void pop() {
        if (topo != nullptr) {
            No* temp = topo;
            topo = topo->proximo;
            delete temp;
        }
    }
    
    int top() {
        return topo->dado;
    }
    
    bool empty() {
        return topo == nullptr;
    }
    
    ~Pilha() {
        while (!empty()) pop();
    }
};

void inverterFila(Fila& fila) {
    Pilha pilha;

    while (!fila.empty()) {
        pilha.push(fila.front());
        fila.pop();
    }

    while (!pilha.empty()) {
        fila.push(pilha.top());
        pilha.pop();
    }
}

int main() {
    Fila fila;
    fila.push(1);
    fila.push(2);
    fila.push(3);

    inverterFila(fila);

    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }

    return 0;
}