#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void q1(vector<int>& arr, int valor) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) {
            cout << "Posição: " << i << endl;
        }
    }
}

void q2(vector<int>& arr, int valor) {
    int contador = 0;
    int comparacoes = 0;
    bool encontrado = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) {
            contador++;
            encontrado = true;
        }
        comparacoes++;
        
    }
    if (encontrado == true) {
        cout << "Valor foi encontrado" << endl;
        cout << contador << endl;
        cout << "Total de comparações: " << comparacoes << endl;

    }
}

void bs(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bsr(vector<int>& arr, int n) {
    if (n == 1) { return; }
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
    bsr(arr, n - 1);
}

int q3(vector<int>& arr, int valor, int inicio, int fim, int comparacoes) {
    if (inicio > fim) { return -1; }

    int meio = (inicio + fim) / 2;
    comparacoes++;

    if (arr[meio] == valor) { 
        cout << "Valor: " << valor << " encontrado." << endl;
        cout << "Quantidade de comparações: " << comparacoes << endl;
        return comparacoes;
    }

    if (arr[meio] < valor) {
        return q3(arr, valor, meio + 1, fim, comparacoes);
    } else {
        return q3(arr, valor, inicio, meio - 1, comparacoes);
    }
} 

int q4(vector<int>& arr, int valor, int inicio, int fim) {
    if (inicio > fim) {
        cout << "Elemento deveria ser inserido na posição: " << inicio << endl;
        return inicio; 
    }

    int meio = (inicio + fim) / 2;
    
    if (arr[meio] == valor) {
        return meio;
    }

    if (arr[meio] < valor) {
        return q4(arr, valor, meio + 1, fim);
    } else {
        return q4(arr, valor, inicio, meio - 1);
    }


}
void printArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // 1.
    vector<int> arr = {4, 8, 2, 8, 5, 8, 1};
    q1(arr, 8);
    cout << endl;

    // 2.
    q2(arr, 8);
    cout << endl;

    // 3.
    bs(arr);
    printArr(arr);
    int comp = 0;
    int comparacoes = q3(arr, 8, 0, arr.size() -1, comp);

    int posicao = q3(arr, 8, 0, arr.size() -1, comp);

    // 4.
    int pos = q4(arr, 3, 0, arr.size() - 1);
    return 0;
}