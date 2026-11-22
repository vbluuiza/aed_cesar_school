#include <iostream>
#include <vector>
using namespace std;

// Maior Elemento em um Vetor
int maior_elemento(const vector<int>& vet, int n) {
    if (n == 1) return vet[0];
    int maiorRestante = maior_elemento(vet, n - 1);
    return max(vet[n - 1], maiorRestante);
}

int main() {
    vector<int> vet = {4, 9, 2, 15, 7};
    cout << maior_elemento(vet, vet.size()) << endl;
    return 0;
}