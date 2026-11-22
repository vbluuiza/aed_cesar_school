#include <iostream>

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct BST {
    Node* root;
    BST() : root(nullptr) {}

    // --- INSERÇÃO (recursiva) ---
    Node* insert(Node* node, int val) {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);

        else node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // --- TRAVESSIAS ---

    // Esquerda -> Raiz -> Direita (ordem crescente na BST)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // Raiz -> Esquerda -> Direita
    void preorder(Node* node) {
        if (!node) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
 
    // Esquerda -> Direita -> Raiz
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    void printInorder()   { inorder(root);   std::cout << "\n"; }
    void printPreorder()  { preorder(root);  std::cout << "\n"; }
    void printPostorder() { postorder(root); std::cout << "\n"; }

    // --- CÓPIA DA ÁRVORE ---
    // Retorna uma cópia completa (pré-ordem garante que a estrutura é preservada)
    Node* copyTree(Node* node) {
        if (!node) return nullptr;

        Node* novo = new Node(node->data);
        novo->left = copyTree(node->left);
        novo->right = copyTree(node->right);
        return novo;
    }

    BST copy() {
        BST nova;
        nova.root = copyTree(root);
        return nova;
    }

    // --- COMPARAÇÃO DE DUAS ÁRVORES ---
    // Retorna 1 se forem iguais, 0 caso contrário
    int compareTrees(Node* a, Node* b) {
        if(!a && !b) return 1;  // ambos nulos: iguais
        if (!a || !b) return 0; // só um é nulo: diferentes
        if(a->data != b->data) return 0;    // dados diferentes
        return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
    }

    int isEqual(BST& other) {
        return compareTrees(root, other.root);
    }

    // --- BUSCA ---
    bool search(Node* node, int val) {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }
 
    bool search(int val) {
        return search(root, val);
    }

    // --- ALTURA DA ÁRVORE ---
    int height(Node* node) {
        if (!node) return 0;
        int left  = height(node->left);
        int right = height(node->right);
        return 1 + (left > right ? left : right);
    }
 
    int height() { return height(root); }

    // --- LIBERA MEMÓRIA ---
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
 
    void clear() {
        clear(root);
        root = nullptr;
    }
};