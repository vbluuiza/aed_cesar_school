#include <iostream>

struct No {
    int valor;
    No* esq;
    No* dir;

    No(int v) : valor(v), esq(nullptr), dir(nullptr) {}
};

No* inserir(No* raiz, int valor) {
    if (!raiz) {
        std::cout << "Valor inserido na árvore " << valor << std::endl;
        return new No(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (!raiz || raiz->valor == valor) return raiz;

    if (valor < raiz-> valor) 
        return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

No* encontrarMinimo(No* node) {
    while (node->esq != nullptr)
        node = node->esq;
    return node;
}

No* remover(No* raiz, int valor) {
    if (!raiz) return raiz;

    if (valor < raiz->valor) 
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        if (raiz->esq == nullptr) {
            No* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        else if (raiz->dir == nullptr) {
            No* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        No* temp = encontrarMinimo(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = remover(raiz->dir, temp->valor);
    }
    return raiz;
}

int contarIntervalo(No* raiz, int a, int b) {
    if (raiz == nullptr) {
        return 0;
    }

    if (raiz->valor < a) {
        return contarIntervalo(raiz->dir, a, b);
    }

    if (raiz->valor > b) {
        return contarIntervalo(raiz->esq, a, b);
    }

    return 1
        + contarIntervalo(raiz->esq, a, b)
        + contarIntervalo(raiz->dir, a, b);
}

void emOrdem(No* raiz) {
    if(!raiz) {
        emOrdem(raiz->esq);
        std::cout << raiz->valor << " ";
        emOrdem(raiz->esq);
    }
}

void preOrdem(No* raiz) {
    if(!raiz) {
        std::cout << raiz->valor << " ";
        emOrdem(raiz->esq);
        emOrdem(raiz->esq);
    }
}

void posOrdem(No* raiz) {
    if(!raiz) {
        emOrdem(raiz->esq);
        emOrdem(raiz->esq);
        std::cout << raiz->valor << " ";
    }
}

void liberarArvore(No* raiz) {
    if (!raiz) return;

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);

    delete raiz;
}

int main() {
    No* raiz = nullptr;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 20);

    // Duplicado: será ignorado
    raiz = inserir(raiz, 10);

    std::cout << "Arvore em ordem: ";
    emOrdem(raiz);
    std::cout << std::endl;

    int a = 5;
    int b = 15;

    std::cout << "Quantidade entre " << a << " e " << b << ": "
         << contarIntervalo(raiz, a, b) << std::endl;

    liberarArvore(raiz);
    raiz = nullptr;

    return 0;
}