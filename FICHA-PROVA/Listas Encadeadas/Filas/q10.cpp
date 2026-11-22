#include <iostream>
using namespace std;

// Fila Circular
class FilaCircular {
private:
    static const int MAX = 5;
    int dados[MAX];
    int inicio, fim, qtd;

public:
    FilaCircular() : inicio(0), fim(0), qtd(0) {}

    bool isEmpty() { return qtd == 0; }
    bool isFull() { return qtd == MAX; }

    void enqueue(int valor) {
        if (!isFull()) {
            dados[fim] = valor;
            fim = (fim + 1) % MAX;
            qtd++;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int valor = dados[inicio];
            inicio = (inicio + 1) % MAX;
            qtd--;
            return valor;
        }
        return -1;
    }
};

int main() {
    FilaCircular f;
    f.enqueue(1);
    f.enqueue(2);
    f.enqueue(3);

    cout << f.dequeue() << endl;
    f.enqueue(4);

    return 0;
}