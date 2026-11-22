#include <iostream>
using namespace std;

// Transformar Soma dos Dígitos em Iterativo
int main() {
    int n = 1234;
    int soma = 0;

    if (n < 0) n = -n;

    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }

    cout << soma << endl;
    return 0;
}