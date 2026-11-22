#include <iostream>
using namespace std;

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = 9;
    int alvo = 9;

    int inicio = 0;
    int fim = tamanho - 1;
    int posicao = -1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        cout << "Verificando: " << numeros[meio] << endl;

        if (numeros[meio] == alvo) {
            posicao = meio;
            break;
        } 
        else if (numeros[meio] < alvo) {
            inicio = meio + 1;
            
        } else {
            fim = meio - 1;
        }
    }

    if (posicao != -1) {
        cout << "Encontrado na posição: " << posicao << endl;
    } else {
        cout << "Número nao encontrado." << endl;
    }

    return 0;
}
