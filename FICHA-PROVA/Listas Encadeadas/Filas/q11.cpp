#include <iostream>
#include <string>
using namespace std;

struct No {
    string dado;
    No* proximo;
    No(string x) : dado(x), proximo(nullptr) {}
};

struct Fila {
    No* inicio;
    No* fim;
    
    Fila() : inicio(nullptr), fim(nullptr) {}
    
    void push(string x) {
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
    
    string front() {
        return inicio->dado;
    }
    
    bool empty() {
        return inicio == nullptr;
    }
    
    ~Fila() {
        while (!empty()) pop();
    }
};

int main() {
    Fila fila;

    fila.push("Ana");
    fila.push("Bruno");
    fila.push("Carlos");

    while (!fila.empty()) {
        cout << "Atendendo: " << fila.front() << endl;
        fila.pop();
    }

    return 0;
}