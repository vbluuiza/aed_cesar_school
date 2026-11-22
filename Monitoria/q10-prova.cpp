#include <iostream>
using namespace std;

// QUESTÃO 10 – Um sistema financeiro utiliza busca binária para localizar contas. Em alguns casos, o sistema informa que encontrou a conta, mas retorna uma posição incorreta. (0,25)

int buscaBinaria(int v[], int n, int valor){
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if(v[meio] == valor)
            return meio;

        if(valor < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}