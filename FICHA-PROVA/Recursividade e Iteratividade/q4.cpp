#include <iostream>
using namespace std;

// Produto de Dois Números Usando Somas Sucessivas
int produto(int a, int b) {
    if (b == 0) return 0;
    if (b < 0) return -produto(a, -b);
    return a + produto(a, b - 1);
}

int main() {
    cout << produto(5, 3) << endl;
    return 0;
}