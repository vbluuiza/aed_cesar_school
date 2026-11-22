#include <iostream>
#include <vector>
using namespace std;

// 1.
void encontrarNumero(vector<int>& arr, int valor) {
    bool encontrado = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) {
            cout << "Número " << valor << " encontrado" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Número " << valor << " não encontrado" << endl;
    }
}

// 2.
void contarVezesApareceUmNumero(vector<int>& arr, int valor) {
    int contador = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) { contador ++; }
    }
    cout << "A quantidade de vezes que o número " << valor << " aparece é: " << contador << endl;
}

// 3.
int buscarNumeroERetornarOIndiceOuMenos1(vector<int>& arr, int valor) {
    int indice = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) {
            indice = i;
            break;
        }
    }
    return indice;
}
int main() {
    vector<int> arr = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};
    // 1.
    int valorProcurado = 25;
    encontrarNumero(arr, valorProcurado);
    
    // 2.
    int contarNumero = 7;
    vector<int> arr2 = {7, 3, 5, 7, 9, 2, 7, 1, 4, 6};
    contarVezesApareceUmNumero(arr2, contarNumero);

    // 3.
    int buscarNumero = 55;
    vector<int> arr3 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int numeroDeVezesQue55Aparece = buscarNumeroERetornarOIndiceOuMenos1(arr3, buscarNumero);
    cout << numeroDeVezesQue55Aparece << endl;

    return 0;
}