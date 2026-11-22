#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return;
}

int esperaramDemais(vector<int>& arr, int tempo) {
    int contador = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > tempo) {
            contador++;
        }
    }
    return contador;
}

void printArr(vector<int>arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    printArr(arr);
    insertionSort(arr);
    printArr(arr);
    int limiteTempo;
    cout << "Limite de tempo: ";
    cin >> limiteTempo;

    int qtdEsperaramDemais = esperaramDemais(arr, limiteTempo);
    cout << "Quantidade de pacientes que esperaram mais que o limite informado: " << qtdEsperaramDemais << endl;
    return 0;
}