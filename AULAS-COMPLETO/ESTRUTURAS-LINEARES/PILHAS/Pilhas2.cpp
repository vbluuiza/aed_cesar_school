#include <iostream>
#include <string>
using namespace std;

struct No {
    char dado;
    No* prox;

    No(char valor, No* proxNo = nullptr) : dado(valor), prox(proxNo) {}
};

// Push com referência para ponteiro
void push(No*& topo, char valor) {
    topo = new No(valor, topo); // já inicializa 'dado' e 'prox'
}

// Pop com referência para ponteiro
char pop(No*& topo) {
    if (!topo) 
        return '\0'; // pilha vazia

    char valor = topo->dado;
    No* temp = topo;
    topo = topo->prox;
    delete temp;
    return valor;
}

// Inverte palavra usando pilha
void inverterPalavra(const string& palavra) {
    No* pilha = nullptr;

    for (char c : palavra)
        push(pilha, c);

    cout << "Palavra invertida: ";
    while (pilha)
        cout << pop(pilha);
    cout << "\n";
}

// Funções auxiliares
void peek(No* topo) {
    if (!topo)
        cout << "Pilha vazia\n";
    else
        cout << "Topo da pilha: " << topo->dado << endl;
}

bool isEmpty(No* topo) {
    return topo == nullptr;
}

int getSize(No* topo) {
    int contador = 0;
    while (topo) {
        contador++;
        topo = topo->prox;
    }
    return contador;
}

int main() {
    No* pilha = nullptr;

    push(pilha, 'A');
    push(pilha, 'B');
    pop(pilha);       // remove 'B'
    push(pilha, 'C');

    peek(pilha);           // Topo da pilha: C
    cout << "Tamanho: " << getSize(pilha) << endl; // 2
    cout << "Vazia? " << isEmpty(pilha) << endl;  // 0 (false)

    char removido = pop(pilha);
    cout << "Removido: " << removido << endl;

    return 0;
}