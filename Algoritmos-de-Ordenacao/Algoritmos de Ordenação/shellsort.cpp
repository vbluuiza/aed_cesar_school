#include <iostream>
#include <vector>
using namespace std;

// =========================================================
// 1) SHELL SORT
// Usa um "gap" para comparar elementos mais distantes
// D  epois vai diminuindo esse gap até chegar em 1
// =========================================================

void shellSort(vector<int>& vetor) {
    int n = vetor.size();

    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            int valorAtual = vetor[i];
            int j = i;

            while (j >= gap && vetor[j - gap] > valorAtual) {
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }

            vetor[j] = valorAtual;
        }
    }
}

int main() {
    vector<int> arr = {3, 7, 8, 5, 4, 2, 6, 1};
    cout << "Antes de  (Shell Sort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    shellSort(arr);
    cout << "Depois de ordernar (Shell Sort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}