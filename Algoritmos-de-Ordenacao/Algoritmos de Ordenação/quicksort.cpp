#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =========================================================
// 2) QUICK SORT
// Escolhe um pivô e separa os menores de um lado
// e os maiores do outro
// =========================================================

int particionar(vector<int>& vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }

    swap(vetor[i + 1], vetor[fim]);

    return i + 1;
}

void quickSort(vector<int>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, posicaoPivo - 1);
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

int main() {
    vector<int> arr = {3, 7, 8, 5, 4, 2, 6, 1};
    cout << "Antes de  (Quicksort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);
    cout << "Depois de ordernar (Quicksort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}