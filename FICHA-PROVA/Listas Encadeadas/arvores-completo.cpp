#include <iostream>

struct No {
    int data;
    No* esq;
    No* dir;
    No(int val) : data(val), esq(nullptr), dir(nullptr) {}
};

struct BST {
    No* raiz;

    BST() : raiz(nullptr) {}

    // --------------------------------------------------------
    // INSERÇÃO
    // --------------------------------------------------------
    No* inserir(No* no, int valor) {
        if (!no) return new No(valor);
        if (valor < no->data) no->esq = inserir(no->esq, valor);
        else if (valor > no->data) no->dir = inserir(no->dir, valor);
        return no;
    }

    void inserir(int valor) {
        raiz = inserir(raiz, valor);
    }

    int countNodes(No* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodes(root->esq) + countNodes(root->dir);
    }

    int compareSides(No* root) {
    if (root == nullptr)
        return 0; // árvore vazia → lados iguais

    int leftCount = countNodes(root->esq);
    int rightCount = countNodes(root->dir);

    return (leftCount == rightCount) ? 0 : 1;
}

    // --------------------------------------------------------
    // TRAVESSIAS
    // --------------------------------------------------------
    void inorder(No* no) {
        if (!no) return;
        inorder(no->esq);
        std::cout << no->data << " ";
        inorder(no->dir);
    }

    void preorder(No* no) {
        if (!no) return;
        std::cout << no->data << " ";
        preorder(no->esq);
        preorder(no->dir);
    }

    void postorder(No* no) {
        if (!no) return;
        postorder(no->esq);
        postorder(no->dir);
        std::cout << no->data << " ";
    }

    void printInorder()   { inorder(raiz);   std::cout << "\n"; }
    void printPreorder()  { preorder(raiz);  std::cout << "\n"; }
    void printPostorder() { postorder(raiz); std::cout << "\n"; }

    //  --------------------------------------------------------
    // COPIAR ÁRVORE
    // Cria e retorna uma cópia completa da árvore
    // --------------------------------------------------------
    No* copiar(No* no) {
        if (!no) return nullptr;
        No* novo = new No(no->data);
        novo->esq = copiar(no->esq);
        novo->dir = copiar(no->dir);
        return novo;
    }

    BST copiar() {
        BST nova;
        nova.raiz = copiar(raiz);
        return nova;
    }

    // --------------------------------------------------------
    // COMPARAR DUAS ÁRVORES
    // Retorna 1 se iguais, 0 caso contrário
    // --------------------------------------------------------
    int iguais(No* a, No* b) {
        if (!a && !b) return 1;
        if (!a || !b) return 0;
        if (a->data != b->data) return 0;
        return iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
    }

    int iguais(BST& outra) {
        return iguais(raiz, outra.raiz);
    }

    // --------------------------------------------------------
    // MENOR E MAIOR VALOR
    // Na BST: menor = mais à esquerda, maior = mais à direita
    // --------------------------------------------------------
    int menor() {
        if (!raiz) return -1;
        No* curr = raiz;
        while (curr->esq) 
            curr = curr->esq;
        return curr->data;
    }

    int maior() {
        if (!raiz) return -1;
        No* curr = raiz;
        while (curr->dir) 
            curr = curr->dir;
        return curr->data;
    }

    // --------------------------------------------------------
    // CONTAR NÓS NO INTERVALO [a, b]
    // int contarIntervalo(No *raiz, int a, int b)
    // --------------------------------------------------------
    int contarIntervalo(No* no, int a, int b) {
        if (!no) return 0;
        int count = (no->data >= a && no->data <= b) ? 1 : 0;
        count += contarIntervalo(no->esq, a, b);
        count += contarIntervalo(no->dir, a, b);
        return count;
    }

    int contarIntervalo(int a, int b) {
        return contarIntervalo(raiz, a, b);
    }

    // --------------------------------------------------------
    // ESPELHAR A ÁRVORE
    // Troca esquerda e direita de todos os nós recursivamente
    // --------------------------------------------------------
    void espelhar(No* no) {
        if (!no) return;
        No* temp = no->esq;
        no->esq = no->dir;
        no->dir = temp;
        espelhar(no->esq);
        espelhar(no->dir);
    }

    void espelhar() { 
        espelhar(raiz); 
    }

    // --------------------------------------------------------
    // REMOÇÃO — três casos
    //
    // Caso 1: nó folha          → deleta direto
    // Caso 2: nó com um filho   → pai aponta para o filho
    // Caso 3: nó com dois filhos → substitui pelo sucessor
    //         (menor valor da subárvore direita)
    // --------------------------------------------------------
    No* remover(No* no, int valor) {
        if (!no) return nullptr;

        if (valor < no->data) {
            no->esq = remover(no->esq, valor);
        } else if (valor > no->data) {
            no->dir = remover(no->dir, valor);
        } else {    
            // Casos 1 e 2 — sem filho esquerdo
            if (!no->esq) {
                No* temp = no->dir;
                delete no;
                return temp;
            }
            // Caso 2 — sem filho direito
            if (!no->dir) {
                No* temp = no->esq;
                delete no;
                return temp;
            }
            // Caso 3 — dois filhos: encontra o sucessor
            No* sucessor = no->dir;
            while (sucessor->esq) sucessor = sucessor->esq;
            no->data = sucessor->data;
            no->dir = remover(no->dir, sucessor->data);
        }
        return no;
    }

    void remover(int valor) {
        raiz = remover(raiz, valor);
    }
    void clear(No* no) {
        if (!no) return;
        clear(no->esq);
        clear(no->dir);
        delete no;
    }

    void clear() { clear(raiz); raiz = nullptr; }
};

int main() {
    BST arvore;
    arvore.inserir(50);
    arvore.inserir(30);
    arvore.inserir(70);
    arvore.inserir(20);
    arvore.inserir(40);
    arvore.inserir(80);

    std::cout << "=== TRAVESSIAS ===\n";
    std::cout << "Inorder   (crescente): "; arvore.printInorder();
    std::cout << "Preorder  (raiz 1o):   "; arvore.printPreorder();
    std::cout << "Postorder (raiz ultimo): "; arvore.printPostorder();
    std::cout << "\n";

    // Copiar
    std::cout << "=== COPIAR ===\n";
    BST copia = arvore.copiar();
    std::cout << "Copia inorder: "; copia.printInorder();
    std::cout << "\n";

    // Comparar
    std::cout << "=== COMPARAR ===\n";
    std::cout << "arvore == copia: " << arvore.iguais(copia) << "\n"; // 1
    BST outra;
    outra.inserir(1);
    outra.inserir(2);
    std::cout << "arvore == outra: " << arvore.iguais(outra) << "\n"; // 0
    std::cout << "\n";

    // Menor e maior
    std::cout << "=== MENOR E MAIOR ===\n";
    std::cout << "Menor: " << arvore.menor() << "\n"; // 20
    std::cout << "Maior: " << arvore.maior() << "\n"; // 80
    std::cout << "\n";

    // Contar intervalo
    std::cout << "=== CONTAR INTERVALO [30, 70] ===\n";
    std::cout << "Contagem: " << arvore.contarIntervalo(30, 70) << "\n"; // 30,40,50,70 = 4
    std::cout << "\n";

    // Espelhar
    std::cout << "=== ESPELHAR ===\n";
    std::cout << "Antes:  "; arvore.printInorder();
    arvore.espelhar();
    std::cout << "Depois: "; arvore.printInorder();
    arvore.espelhar(); // volta ao estado original
    std::cout << "\n";

    // Remover — 3 casos
    std::cout << "=== REMOCAO ===\n";
    std::cout << "Antes:                        "; arvore.printInorder();

    arvore.remover(20); // caso 1: folha
    std::cout << "Apos remover 20 (folha):      "; arvore.printInorder();

    arvore.remover(80); // caso 1: folha (sem filhos agora)
    std::cout << "Apos remover 80 (folha):      "; arvore.printInorder();

    arvore.remover(70); // caso 2: 70 tinha 80, mas agora não tem filho — era folha
    // para demonstrar caso 2 de verdade, inserir um nó com um filho
    arvore.inserir(70);
    arvore.inserir(65); // 70 agora tem só filho esquerdo
    std::cout << "Apos reinserir 70 e 65:       "; arvore.printInorder();
    arvore.remover(70); // caso 2: um filho (65)
    std::cout << "Apos remover 70 (um filho):   "; arvore.printInorder();

    arvore.remover(30); // caso 3: dois filhos (nenhum agora — 20 foi removido, mas 40 ainda está)
    std::cout << "Apos remover 30 (dois filhos): "; arvore.printInorder();

    arvore.clear();
    copia.clear();
    return 0;
}