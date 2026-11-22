#include <iostream>
#include <string>
using namespace std;

// Inverter uma String Usando uma Pilha
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
    
    char top() {
        return topo->dado;
    }
    
    bool empty() {
        return topo == nullptr;
    }
    
    ~Pilha() {
        while (!empty()) pop();
    }
};

int main() {
    string s;
    cout << "Digite uma string: ";
    getline(cin, s);

    Pilha pilha;
    for (char c : s) pilha.push(c);

    cout << "Invertida: ";
    while (!pilha.empty()) {
        cout << pilha.top();
        pilha.pop();
    }
    cout << endl;

    return 0;
}