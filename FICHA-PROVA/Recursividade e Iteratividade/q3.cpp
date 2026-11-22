#include <iostream>
using namespace std;

// Soma dos Dígitos de um Número
int soma_digitos(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    cout << soma_digitos(1234) << endl;
    return 0;
}