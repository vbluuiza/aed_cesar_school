#include <iostream>
using namespace std;

//  Transformar Produto de Dois Números em Iterativo
int main() {
    int a = 5, b = 3, resultado = 0;
    bool negativo = false;

    if (b < 0) {
        b = -b;
        negativo = true;
    }

    for (int i = 0; i < b; i++) {
        resultado += a;
    }

    if (negativo) resultado = -resultado;

    cout << resultado << endl;
    return 0;
}