#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =========================================================
// 2) SELECTION SORT
// Procura o menor elemento e coloca na posição correta
// =========================================================s

void selectionSort(vector<int>& vetor) {
    int n = vetor.size();

    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;

        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }

        swap(vetor[i], vetor[indiceMenor]);
    }
}

int main() {
    vector<int> arr = {5, 6, 3, 2, 7, 1, 9, 4, 5};
    cout << "Antes de  (Selection Sort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    selectionSort(arr);
    cout << "Depois de ordernar (Selection Sort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}