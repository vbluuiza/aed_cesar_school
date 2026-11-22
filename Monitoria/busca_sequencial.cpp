#include <iostream>
using namespace std;

int main() {
    int numeros[] = {2, 5, 7, 8, 1, 9, 3, 4, 6};
    int tamanho = 9;
    int alvo = 8;
    int posicao = -1;

    for (int i = 0; i < tamanho; i++) {
        cout << "Verificando: " << numeros[i] << endl;

        if (numeros[i] == alvo) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        cout << "Encontrado na posicao: " << posicao << endl;
    } else {
        cout << "Numero nao encontrado." << endl;
    }

    return 0;
}
