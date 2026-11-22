#include <iostream>
#include <vector>
#include <list>
using namespace std;

int hashFunc(int v) {
    return v % 10;
}

// 1. Insercao com encadeamento de colisoes
void inserirColisaoLE(vector<list<int>>& table, int value) {
    int p = hashFunc(value);

    table[p].push_back(value);

    cout << "Inserindo " << value
         << " na posicao " << p << endl;
}

// 2. Busca por hash
void buscarEncadeadaColisao(vector<list<int>>& table, int value) {
    int p = hashFunc(value);

    cout << "\nBuscando " << value
         << " na posicao " << p << endl;

    for (int item : table[p]) {
        cout << "Verificando: " << item << endl;

        if (item == value) {
            cout << "Numero " << value
                 << " encontrado na posicao "
                 << p << endl;
            return;
        }
    }

    cout << "Numero " << value
         << " nao encontrado." << endl;
}

// 3. Impressao da tabela hash
void printHashTableLE(vector<list<int>>& table) {
    cout << "\nTabela Hash:\n";

    for (int i = 0; i < table.size(); i++) {
        cout << i << ": ";

        for (int num : table[i]) {
            cout << num << " -> ";
        }

        cout << "NULL" << endl;
    }
}

int main() {
    vector<list<int>> table(10);

    inserirColisaoLE(table, 12);
    inserirColisaoLE(table, 22);
    inserirColisaoLE(table, 32);
    inserirColisaoLE(table, 42);

    printHashTableLE(table);

    buscarEncadeadaColisao(table, 22);

    return 0;
}
