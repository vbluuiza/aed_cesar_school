#include <iostream>
#include <vector>
using namespace std;

// Transformar Maior Elemento em Iterativo
int main() {
    vector<int> vet = {4, 9, 2, 15, 7};
    int maior = vet[0];

    for (int i = 1; i < vet.size(); i++) {
        if (vet[i] > maior) maior = vet[i];
    }

    cout << maior << endl;
    return 0;
}