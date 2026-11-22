#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    // Construtor: inicializa valor e filhos
    No(int v) : valor(v), esquerda(nullptr), direita(nullptr) {}
};

// Inserção usando referência para ponteiro
void inserir(No*& raiz, int valor) {
    if (!raiz) {
        raiz = new No(valor);
        return;
    }
    if (valor < raiz->valor)
        inserir(raiz->esquerda, valor);
    else
        inserir(raiz->direita, valor);
}

// Encontrar o nó com maior valor à esquerda (para remoção)
No* maximo(No* raiz) {
    while (raiz->direita)
        raiz = raiz->direita;
    return raiz;
}

// Remoção usando referência para ponteiro
void remover(No*& raiz, int valor) {
    if (!raiz) return;

    if (valor < raiz->valor)
        remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        remover(raiz->direita, valor);
    else {
        // Nó encontrado
        if (!raiz->esquerda && !raiz->direita) { // folha
            delete raiz;
            raiz = nullptr;
        } else if (!raiz->esquerda) { // só direita
            No* temp = raiz;
            raiz = raiz->direita;
            delete temp;
        } else if (!raiz->direita) { // só esquerda
            No* temp = raiz;
            raiz = raiz->esquerda;
            delete temp;
        } else { // dois filhos
            No* temp = maximo(raiz->esquerda);
            raiz->valor = temp->valor;
            remover(raiz->esquerda, temp->valor);
        }
    }
}

// Impressão em ordem
void imprimirEmOrdem(No* raiz) {
    if (!raiz) return;
    imprimirEmOrdem(raiz->esquerda); // 1. Percorre a subárvore esquerda
    cout << raiz->valor << " "; // 2. Imprime o valor do nó atual
    imprimirEmOrdem(raiz->direita); // 3. Percorre a subárvore direita
}

void imprimirPreOrdem(No* raiz) {
    if (!raiz) return;
    cout << raiz->valor << " ";
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirPosOrdem(No* raiz) {
    if (!raiz) return;
    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    cout << raiz->valor << " ";
}

No* buscar(No* raiz, int valor) {
    if (!raiz || raiz->valor == valor) return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

int main() {
    No* raiz = nullptr;

    inserir(raiz, 10);
    inserir(raiz, 5);
    inserir(raiz, 15);
    inserir(raiz, 3);
    inserir(raiz, 7);
    inserir(raiz, 12);
    inserir(raiz, 18);

    cout << "Árvore em ordem: ";
    imprimirEmOrdem(raiz);
    cout << endl;

    cout << "Árvore em pré-ordem: ";
    imprimirPreOrdem(raiz);
    cout << endl;

    cout << "Árvore em pós-ordem: ";
    imprimirPosOrdem(raiz);
    cout << endl;

    cout << "Removendo 5...\n";
    remover(raiz, 5);

    cout << "Árvore em ordem após remoção: ";
    imprimirEmOrdem(raiz);
    cout << endl;

    return 0;
}