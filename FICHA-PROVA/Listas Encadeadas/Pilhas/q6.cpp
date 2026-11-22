#include <iostream>
#include <string>
using namespace std;

// Verificar se uma Expressão com Parênteses Está Correta 
struct No {
    char dado;
    No* proximo;
    No(char x) : dado(x), proximo(nullptr) {}
};

struct Pilha {
    No* topo;
    
    Pilha() : topo(nullptr) {}
    
    void push(char x) {
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
    
    bool empty() {
        return topo == nullptr;
    }
    
    ~Pilha() {
        while (!empty()) pop();
    }
};

bool verificar(const string& s) {
    Pilha pilha;

    for (char c : s) {
        if (c == '(') pilha.push(c);
        else if (c == ')') {
            if (pilha.empty()) return false;
            pilha.pop();
        }
    }

    return pilha.empty();
}

int main() {
    string expr = "(())()";
    cout << (verificar(expr) ? "Valido" : "Invalido") << endl;
    return 0;
}