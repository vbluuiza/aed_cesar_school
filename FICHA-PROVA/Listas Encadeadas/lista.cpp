#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    // Insere no início — O(1)
    void insertFront(int val) {
        Node* novo = new Node(val);
        novo->next = head;
        head = novo;
    }

    // Insere no final — O(n)
    void insertEnd(int val) {
        Node* novo = new Node(val);
        if (!head) { 
            head = novo; 
            return; 
        }
        Node* curr = head;
        while (curr->next) 
            curr = curr->next;
        curr->next = novo;
    }

    // Remove o primeiro nó — O(1)
    void removeFront() {
        if (!head) {
            std::cout << "Lista vazia.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove o último nó — O(n)
    void removeEnd() {
        if (!head) {
            std::cout << "Lista vazia.\n";
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node* curr = head;
        while (curr->next->next) curr = curr->next;
        delete curr->next;
        curr->next = nullptr;
    }

    // Busca um valor — retorna true se encontrar
    bool search(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    void print() {
        if (!head) {
            std::cout << "Lista vazia.\n";
            return;
        }
        Node* curr = head;
        while(curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    void clear() {
        while (head) removeFront();
    }
};

int main() {
    LinkedList lista;
 
    std::cout << "=== LISTA ENCADEADA ===\n\n";
 
    // Inserindo elementos
    lista.insertEnd(10);
    lista.insertEnd(20);
    lista.insertEnd(30);
    lista.insertFront(5);
 
    std::cout << "Após inserções:\n";
    lista.print();
    // Saída: 5 -> 10 -> 20 -> 30 -> NULL
 
    // Removendo
    lista.removeFront();
    std::cout << "Após removeFront:\n";
    lista.print();
    // Saída: 10 -> 20 -> 30 -> NULL
 
    lista.removeEnd();
    std::cout << "Após removeEnd:\n";
    lista.print();
    // Saída: 10 -> 20 -> NULL
 
    // Busca
    std::cout << "Busca por 20: " << (lista.search(20) ? "encontrado" : "não encontrado") << "\n";
    std::cout << "Busca por 99: " << (lista.search(99) ? "encontrado" : "não encontrado") << "\n";
 
    lista.clear();
    return 0;
}
 