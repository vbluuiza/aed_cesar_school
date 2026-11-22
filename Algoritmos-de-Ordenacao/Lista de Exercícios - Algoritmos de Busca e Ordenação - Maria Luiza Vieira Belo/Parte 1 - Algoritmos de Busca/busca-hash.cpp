#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Função hash base
int hashFunc(int v) {
    return v % 10;
}

// 1.
void inserirSemColisao(vector<int>& table, int value) {
    int p = hashFunc(value);
    table[p] = value;
}

void buscarSemColisao(vector<int>& table, int value) {
    int p = hashFunc(value);
    for (int i : table) {
        if (i == p) {
            cout << "Número " << value << " encontrado na posição " << i << endl;
        }
    }
}

void printSemColisao(vector<int>&table) {
    for (int i = 0; i < table.size(); i++) {
        cout << i << ": " << table[i] << endl;
    }
    cout << endl;
}

// 2. 
void buscarEncadeadaColisao(vector<list<int>>& table, int value) {
    int p = hashFunc(value);
    cout << "\nBuscando " << value << " na posição " << p << endl;

    for (int item : table[p]) {
        if (item == value) { 
            cout << "Número " << value << " encontrado na posição " << p << endl; 
            return;
        }
    }
    cout << "Número " << value << " não encontrado." << endl;
}

void inserirColisaoLE(vector<list<int>>& table, int value) {
    int p = hashFunc(value);
    table[p].push_back(value);
    cout << "Inserindo " << value << " na posição " << p << endl;
}

void printHashTableLE(vector<list<int>>& table) {
    for (int i = 0; i < table.size(); i++) {
        cout << i << ": ";
        for (int num : table[i]) {
            cout << num << " -> ";
        }
        cout << "NULL" << endl;
    }
}

// 3.
void inserirSondagemLinear(vector<int>& table, int value) {
    int p = hashFunc(value);
    while (table[p] != -1) {
        p++;
        if (p == 10) {
            p = 0;
        }
    }
    table[p] = value;
}

void buscarSondagemLinear(vector<int>& table, int value) {
    int p = hashFunc(value);
    while (table[p] != -1) {
        if(table[p] == value) {
            cout << "\nNúmero " << value << " encontrado na posição " << p << endl;
            return; 
        }
        p++;
        if (p == 10) { p = 0; }
    }
    cout << "Número " << value << " não encontrado." << endl;
}

void printHashTableSL(vector<int>& table) {
    for (int i = 0; i < table.size(); i++) {
        cout << i << ": " << table[i] << endl;
    }
}

int main() {
    // 1. Obs: professor, impossível fazer essa questão 7 de hash sem colisão com módulo 10: {15, 25, 35, 45, 55}, ai eu mudei só os valores da tabela e fiz a mesma lógica
    vector<int> table3(10, -1);
    inserirSemColisao(table3, 15);
    inserirSemColisao(table3, 26);
    inserirSemColisao(table3, 37);
    inserirSemColisao(table3, 48);
    inserirSemColisao(table3, 59);

    printSemColisao(table3);

    // 2.
    vector<list<int>> table1(10);
    inserirColisaoLE(table1, 12);
    inserirColisaoLE(table1, 22);
    inserirColisaoLE(table1, 32);
    inserirColisaoLE(table1, 42);

    buscarEncadeadaColisao(table1, 22);
    printHashTableLE(table1);

    // 3.
    vector<int> table2(10, -1);
    inserirSondagemLinear(table2, 17);
    inserirSondagemLinear(table2, 27);
    inserirSondagemLinear(table2, 37);
    inserirSondagemLinear(table2, 57);

    buscarSondagemLinear(table2, 37);
    printHashTableSL(table2);

    return 0;
}