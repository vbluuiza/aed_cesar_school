#include <iostream>
using namespace std;

// Implementação de uma Pilha com Vetor 
class Pilha {
private:
    static const int MAX = 100;
    int dados[MAX];
    int topo;

public:
    Pilha() : topo(-1) {}

    bool isEmpty() {
        return topo == -1;
    }

    void push(int valor) {
        if (topo < MAX - 1) {
            dados[++topo] = valor;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return dados[topo--];
        }
        return -1;
    }

    int top() {
        if (!isEmpty()) return dados[topo];
        return -1;
    }
};

int main() {
    Pilha p;
    p.push(10);
    p.push(20);

    cout << "Topo: " << p.top() << endl;
    cout << "Pop: " << p.pop() << endl;
    cout << "Topo: " << p.top() << endl;

    return 0;
}