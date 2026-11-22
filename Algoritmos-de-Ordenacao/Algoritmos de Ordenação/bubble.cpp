#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// =========================================================
// 1) BUBBLE SORT
// Compara elementos vizinhos e troca se estiverem fora de ordem
// =========================================================

void bubbleSort(vector<int>& vetor) {
    int n = vetor.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 6, 3, 2, 7, 1, 9, 4, 5};
    cout << "Antes de  (Bubble Sort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    bubbleSort(arr);
    cout << "Depois de ordernar (Bubble Sort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}