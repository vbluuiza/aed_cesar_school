#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

void bubble(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void imprimir(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int contarOcorrencias(vector< int>& arr, int valor, int inicio, int fim) {
    if (inicio > fim) { return 0; }

    int meio = (inicio + fim) / 2;
    

    if (arr[meio] == valor) { 
        int contador = 1;
        
        int esquerda = meio - 1;
        while (esquerda >= 0 && arr[esquerda] == valor) {
            contador++;
            esquerda--;
        }

        int direita = meio + 1;
        while(direita < arr.size() && arr[direita] == valor) {
            contador++;
            direita++;
        }
        return contador;
    }

    if (arr[meio] < valor) {
        return contarOcorrencias(arr, valor, meio + 1, fim);
    } else {
        return contarOcorrencias(arr, valor, inicio, meio -1);
    }
}


void selectionSortDecrescente(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int max_index = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        swap(arr[i], arr[max_index]);
    }
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

void ordenarApenasPares(vector<int>& arr) {
    vector<int> pares;

    // 1. Pega apenas os números pares
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            pares.push_back(arr[i]);
        }
    }

    // 2. Ordena os pares usando Insertion Sort
    insertionSort(pares);

    // 3. Coloca os pares ordenados de volta nas posições onde tinha par
    int posicaoPar = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = pares[posicaoPar];
            posicaoPar++;
        }
    }
}

int main() {
    vector<int> arr = {10, 4, 8, 2, 7, 1, 4, 4, 6};
    imprimir(arr);
    bubble(arr);
    imprimir(arr);
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    
    int q17 = contarOcorrencias(arr, 4, 0, arr.size() - 1);
    cout << q17 << endl;

    imprimir(arr2);
    selectionSortDecrescente(arr2);
    imprimir(arr2);

    vector<int> arr3 = {9, 8, 3, 4, 7, 6, 1, 2, 5, 0};
    // 9, _, 3, _, 7, _, 1, _, 5, _
    // 8, 4, 6, 2, 0
    // 0, 2, 4, 6, 8
    // 9, 0, 3, 2, 7, 4, 1, 6, 5, 8
    return 0;
}