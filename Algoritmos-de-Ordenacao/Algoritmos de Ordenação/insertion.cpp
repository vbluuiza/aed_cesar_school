#include <iostream>
#include <vector>

using namespace std;

// =========================================================
// 3) INSERTION SORT
// Pega um valor e encaixa ele no lugar certo
// =========================================================

void insertionSort(vector<int>& vetor) {
    int n = vetor.size();

    for (int i = 1; i < n; i++) {
        int valorAtual = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > valorAtual) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = valorAtual;
    }
}

int main() {
    vector<int> arr = {5, 6, 3, 2, 7, 1, 9, 4, 5};
    cout << "Antes de  (Insertion Sort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    insertionSort(arr);
    cout << "Depois de ordernar (Insertion Sort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}