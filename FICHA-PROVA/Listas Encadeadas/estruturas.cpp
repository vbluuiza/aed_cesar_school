#include <iostream>

struct No {
    int data;
    No* next;
    No(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    No* head;

    LinkedList() : head(nullptr) {}

    // Insere no final
    void inserir(int val) {
        No* novo = new No(val);
        if (!head) { head = novo; return; }
        No* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = novo;
    }

    // Conta os nós da lista
    int contar() {
        int count = 0;
        No* curr = head;
        while (curr) { count++; curr = curr->next; }
        return count;
    }

    // Retorna 1 se valor existe, 0 caso contrário
    int buscar(int valor) {
        No* curr = head;
        while (curr) {
            if (curr->data == valor) return 1;
            curr = curr->next;
        }
        return 0;
    }

    // Remove duplicatas consecutivas
    // Entrada: 10 -> 10 -> 20 -> 30 -> 30 -> 30 -> 40
    // Saída:   10 -> 20 -> 30 -> 40
    void removerDuplicatasConsecutivas() {
        No* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                No* dup = curr->next;
                curr->next = dup->next;
                delete dup;
                // não avança: pode ter mais duplicatas em sequência
            } else {
                curr = curr->next;
            }
        }
    }

    // Inverte a lista usando uma pilha auxiliar
    void inverter() {
        if (!head) return;

        // empilha tudo
        No* pilha = nullptr;
        No* curr = head;
        while (curr) {
            No* novo = new No(curr->data);
            novo->next = pilha;
            pilha = novo;
            curr = curr->next;
        }

        // libera a lista atual
        curr = head;
        while (curr) {
            No* temp = curr;
            curr = curr->next;
            delete temp;
        }

        // reconstrói a partir da pilha
        head = nullptr;
        while (pilha) {
            No* temp = pilha;
            pilha = pilha->next;
            inserir(temp->data);
            delete temp;
        }
    }

    void print() {
        if (!head) { std::cout << "NULL\n"; return; }
        No* curr = head;
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " -> NULL\n";
    }

    void clear() {
        while (head) {
            No* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

struct Stack {
    No* top;

    Stack() : top(nullptr) {}

    bool isEmpty() { return top == nullptr; }

    // Empilha
    void push(int valor) {
        No* novo = new No(valor);
        novo->next = top;
        top = novo;
    }

    // Remove e retorna o topo
    int pop() {
        if (isEmpty()) { std::cout << "Pilha vazia.\n"; return -1; }
        No* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    // Olha o topo sem remover
    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    void print() {
        if (isEmpty()) { std::cout << "Pilha vazia.\n"; return; }
        No* curr = top;
        std::cout << "TOP -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " -> BASE\n";
    }

    void clear() { while (!isEmpty()) pop(); }
};


struct Queue {
    No* front;
    No* back;

    Queue() : front(nullptr), back(nullptr) {}

    bool isEmpty() { return front == nullptr; }

    // Insere no final
    void enqueue(int valor) {
        No* novo = new No(valor);
        if (!back) { front = back = novo; return; }
        back->next = novo;
        back = novo;
    }

    // Remove do início
    int dequeue() {
        if (isEmpty()) { std::cout << "Fila vazia.\n"; return -1; }
        No* temp = front;
        int val = temp->data;
        front = front->next;
        if (!front) back = nullptr;
        delete temp;
        return val;
    }

    // Olha o próximo sem remover
    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }

    // Remove os N primeiros elementos
    void removerN(int n) {
        for (int i = 0; i < n; i++) {
            if (isEmpty()) {
                std::cout << "Fila ficou vazia antes de completar " << n << " remocoes.\n";
                return;
            }
            dequeue();
        }
    }

    // Transfere todos os elementos para uma lista
    void paraLista(LinkedList& lista) {
        while (!isEmpty()) lista.inserir(dequeue());
    }

    void print() {
        if (isEmpty()) { std::cout << "Fila vazia.\n"; return; }
        No* curr = front;
        std::cout << "FRONT -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " <- BACK\n";
    }

    void clear() { while (!isEmpty()) dequeue(); }
};


int main() {

    // LISTA
    std::cout << "=== LISTA ===\n";
    LinkedList lista;
    lista.inserir(10);
    lista.inserir(10);
    lista.inserir(20);
    lista.inserir(30);
    lista.inserir(30);
    lista.inserir(30);
    lista.inserir(40);

    std::cout << "Original: "; lista.print();

    lista.removerDuplicatasConsecutivas();
    std::cout << "Sem dup:  "; lista.print(); // 10->20->30->40

    std::cout << "Contar: " << lista.contar() << "\n";    // 4
    std::cout << "Buscar 20: " << lista.buscar(20) << "\n"; // 1
    std::cout << "Buscar 99: " << lista.buscar(99) << "\n"; // 0

    lista.inverter();
    std::cout << "Invertida: "; lista.print(); // 40->30->20->10
    std::cout << "\n";

    // PILHA
    std::cout << "=== PILHA ===\n";
    Stack pilha;
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.print(); // TOP -> 30 -> 20 -> 10

    std::cout << "Pop: " << pilha.pop() << "\n"; // 30
    std::cout << "Peek: " << pilha.peek() << "\n"; // 20
    pilha.print();
    std::cout << "\n";

    // FILA
    std::cout << "=== FILA ===\n";
    Queue fila;
    fila.enqueue(1);
    fila.enqueue(2);
    fila.enqueue(3);
    fila.enqueue(4);
    fila.enqueue(5);
    fila.print(); // FRONT -> 1->2->3->4->5

    std::cout << "Dequeue: " << fila.dequeue() << "\n"; // 1
    fila.removerN(2); // remove 2 e 3
    fila.print(); // FRONT -> 4->5
    std::cout << "\n";

    // FILA → LISTA (sistema de atendimento)
    std::cout << "=== FILA PARA LISTA (atendimento) ===\n";
    Queue atendimento;
    atendimento.enqueue(100);
    atendimento.enqueue(200);
    atendimento.enqueue(300);
    std::cout << "Fila: "; atendimento.print();

    LinkedList historico;
    atendimento.paraLista(historico);
    std::cout << "Fila apos: "; atendimento.print();  // vazia
    std::cout << "Historico: "; historico.print();    // 100->200->300

    lista.clear();
    historico.clear();
    return 0;
}