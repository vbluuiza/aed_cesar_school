#include <iostream>
using namespace std;

// Pilha implementada com lista encadeada
struct No {
    int dado;
    No* proximo;
    No(int x) : dado(x), proximo(nullptr) {}
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

int main() {
    int n;
    cout << "Numero decimal: ";
    cin >> n;

    if (n == 0) {
        cout << "Binario: 0\n";
        return 0;
    }

    Pilha pilha;
    while (n > 0) {
        pilha.push(n % 2);
        n /= 2;
    }

    cout << "Binario: ";
    while (!pilha.empty()) {
        cout << pilha.top();
        pilha.pop();
    }
    cout << endl;

    return 0;
}