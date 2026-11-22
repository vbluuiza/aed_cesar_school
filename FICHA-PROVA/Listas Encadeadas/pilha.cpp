#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct Stack {
    Node* top;
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    // Empilha — O(1)
    void push(int val) {
        Node* novo = new Node(val);
        novo->next = top;
        top = novo;
    }

    // Desempilha — O(1)
    int pop() {
        if (isEmpty()) {
            std::cout << "Pilha vazia.\n";
            return -1;
        }

        Node* temp = top;
        int val = temp->data;
        top = top->next;

        delete temp;
        return val;
    }

     // Olha o topo sem remover
    int peek() {
        if (isEmpty()) return 1;
        return top->data;
    }

    // Imprime do topo à base
    void print() {
        if (isEmpty()) {
            std::cout << "Pilha vazia.\n";
            return;
        }
        Node* curr = top;
        std::cout << "TOP -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " -> BASE\n";
    }

    // Libera memória
    void clear() {
        while (!isEmpty()) pop();
    }
};

int main() {
    Stack pilha;
 
    std::cout << "=== PILHA (STACK) ===\n\n";
 
    // Empilhando
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
 
    std::cout << "Após push(10), push(20), push(30):\n";
    pilha.print();
    // Saída: TOP -> 30 -> 20 -> 10 -> BASE
 
    // Desempilhando
    int val = pilha.pop();
    std::cout << "Pop retornou: " << val << "\n";
    pilha.print();
    // Saída: TOP -> 20 -> 10 -> BASE
 
    // Peek
    std::cout << "Topo atual: " << pilha.peek() << "\n";
 
    pilha.clear();
    return 0;
}