#include <iostream>
#include "includes/claude-lista.h"

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct Queue {
    Node* front; // Quem sai primeiro
    Node* back; // Quem entrou por último

    Queue() : front(nullptr), back(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    // Entra na fila pelo back — O(1)
    void enqueue(int val) {
        Node* novo = new Node(val);
        if (!back) {
            front = back = novo;
            return;
        }
        back->next = novo;
        back = novo;
    }

    // Sai da fila pelo front — O(1)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Fila vazia.\n";
            return -1;
        }

        Node* temp = front;
        int val = temp->data;
        front = front->next;

        if(!front) 
            back = nullptr; // fila ficou vazia

        delete temp;
        return val;
    }

    // Olha quem está na frente sem remover
    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }

    // Imprime a fila do front ao back
    void print() {
        if (isEmpty()) {
            std::cout << "Fila vazia.\n";
            return;
        }
        Node* curr = front;
        std::cout << "FRONT -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " <- BACK\n";
    }

    // Remove os N primeiros elementos
    void removeN(int n) {
        for (int i = 0; i < n; i++) {
            if (isEmpty()) {
                std::cout << "Fila ficou vazia antes de remover " << n << " elementos.\n";
                return;
            }
            // if (!q.front) break;
            dequeue();
        }
    }
    void atender(Queue& fila, LinkedList& historico) {
        if (!fila.front) return;
        int cliente = fila.dequeue();
        historico.insertEnd(cliente);
    }

    void clear() {
        while (!isEmpty()) dequeue();
    }
};

int main() {
    Queue fila;
 
    std::cout << "=== FILA (QUEUE) ===\n\n";
 
    // Inserindo
    fila.enqueue(1);
    fila.enqueue(2);
    fila.enqueue(3);
    fila.enqueue(4);
    fila.enqueue(5);
 
    std::cout << "Após inserções:\n";
    fila.print();
    // Saída: FRONT -> 1 -> 2 -> 3 -> 4 -> 5 <- BACK
 
    // Removendo um
    int atendido = fila.dequeue();
    std::cout << "Atendido: " << atendido << "\n";
    fila.print();
    // Saída: FRONT -> 2 -> 3 -> 4 -> 5 <- BACK
 
    // Removendo N primeiros
    std::cout << "Removendo os 2 primeiros:\n";
    fila.removeN(2);
    fila.print();
    // Saída: FRONT -> 4 -> 5 <- BACK
 
    // Peek
    std::cout << "Próximo a sair: " << fila.peek() << "\n";
 
    fila.clear();
    return 0;
}