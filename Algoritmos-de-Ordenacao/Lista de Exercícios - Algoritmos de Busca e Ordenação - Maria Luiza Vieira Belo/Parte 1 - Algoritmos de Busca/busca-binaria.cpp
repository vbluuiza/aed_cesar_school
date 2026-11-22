#include <iostream>
#include <vector>
using namespace std;

// 1.
void encontrarNumeroBBR(vector<int>& arr, int inicio, int fim, int alvo) {
    if (inicio > fim) { 
        cout << "Número " << alvo << " não encontrado" << endl;
        return; 
    
    }
    int meio = (inicio + fim) / 2;

    if (arr[meio] == alvo) { 
        cout << "Número encontrado: " << arr[meio] << endl;
        return;
    }

    if (arr[meio] < alvo) {
     encontrarNumeroBBR(arr, meio + 1, fim, alvo);
    } else {
        encontrarNumeroBBR(arr, inicio, meio -1, alvo);
    }
}

// 2.
void contarQuantasComparacoesParaEncontrarValor(vector<int>& arr, int inicio, int fim, int alvo, int contador) {
    if (inicio > fim) { 
        cout << "Número " << alvo << " não encontrado" << endl;
        cout << "Quantidade de comparações: " << contador << endl;
        return;
    }
    int meio = (inicio + fim) / 2;
    contador++;

    if (arr[meio] == alvo) {
        cout << "Número encontrado: " << arr[meio] << endl;
        cout << "Quantidade de comparações: " << contador << endl;
        return;
    }

    if (arr[meio] < alvo) {
        return contarQuantasComparacoesParaEncontrarValor(arr, meio + 1, fim, alvo, contador);
    } else {
        return contarQuantasComparacoesParaEncontrarValor(arr, inicio, meio - 1, alvo, contador);
    }
}

// 3.
int descobrirPosicaoInsercao(vector<int>& arr, int inicio, int fim, int alvo) {
    if (inicio > fim) { return inicio; }

    int meio = (inicio + fim) / 2;

    if (arr[meio] == alvo) { return meio; }

    if (arr[meio] < alvo) { 
        return descobrirPosicaoInsercao(arr, meio + 1, fim, alvo);
    } else {
        return descobrirPosicaoInsercao(arr, inicio, meio - 1, alvo);
    }

}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};
    // 1.
    encontrarNumeroBBR(arr, 0, arr.size() - 1, 25);
    
    // 2.
    int alvo = 100;
    int contador = 0;
    vector<int> arr2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    contarQuantasComparacoesParaEncontrarValor(arr2, 0, arr.size() - 1, alvo, contador);


    // 3.
    vector<int> arr3 = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int buscarNumero = 27;
    int posicao = descobrirPosicaoInsercao(arr3, 0, arr.size() - 1, buscarNumero);
    cout << "Posição de inserção do " << buscarNumero << ": " << posicao << endl;

    return 0;
}