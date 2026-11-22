#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


/* 
Vizinho mais próximo - Busca binaria
Contexto

Uma corretora possui preços ordenados.

Implemente uma busca binária que encontre o valor mais próximo do procurado.

Exemplo:
[10,20,35,50,70]

Valor:
15

Resultado:
10 ou 20, dependendo da regra definida.
*/
int buscaBinaria(vector<int>& arr, int valor) {
    int inicio = 0;
    int fim = arr.size() - 1;
    int maisPerto = arr[0];

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (arr[meio] == valor) { return arr[meio]; }

        if (abs(arr[meio] - valor) < abs(maisPerto - valor)) {
            maisPerto = arr[meio];
        }

        if (arr[meio] < valor) inicio = meio + 1;
        else { fim = meio - 1; }
    }

    return maisPerto;
}

int main() {
    vector<int> arr = {10, 20, 20, 35, 60};
    cout << buscaBinaria(arr,25) << endl;
    return 0;
}