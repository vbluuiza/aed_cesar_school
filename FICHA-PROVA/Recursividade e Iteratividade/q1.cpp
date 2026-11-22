#include <iostream>
using namespace std;

// Número de Dígitos de um Inteiro
int contar_digitos(int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    return 1 + contar_digitos(n / 10);
}

int main() {
    cout << contar_digitos(555) << endl;
    return 0;
}