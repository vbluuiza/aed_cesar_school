#include <iostream>
using namespace std;

//  Implementação de uma Fila com Vetor
class Fila {
private:
    static const int MAX = 100;
    int dados[MAX];
    int inicio, fim;

public:
    Fila() : inicio(0), fim(0) {}

    bool isEmpty() {
        return inicio == fim;
    }

    void enqueue(int valor) {
        if (fim < MAX) dados[fim++] = valor;
    }

    int dequeue() {
        if (!isEmpty()) return dados[inicio++];
        return -1;
    }

    int front() {
        if (!isEmpty()) return dados[inicio];
        return -1;
    }
};

int main() {
    Fila f;
    f.enqueue(10);
    f.enqueue(20);

    cout << "Front: " << f.front() << endl;
    cout << "Dequeue: " << f.dequeue() << endl;
    cout << "Front: " << f.front() << endl;

    return 0;
}