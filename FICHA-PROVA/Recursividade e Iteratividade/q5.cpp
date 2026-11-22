#include <iostream>
using namespace std;


// Contagem Regressiva 
void contagem_regressiva(int n) {
    if (n < 0) return;
    cout << n << " ";
    contagem_regressiva(n - 1);
}

int main() {
    contagem_regressiva(5);
    return 0;
}