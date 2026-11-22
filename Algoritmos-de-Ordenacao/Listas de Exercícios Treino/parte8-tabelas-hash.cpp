#include <iostream>
#include <vector>
#include <list>

using namespace std;

int hashFunc(int v, int tam) {
    return v % tam;
}

void q21HashSemColisao(vector<int>& arr, int v) {
    int p = hashFunc(v, 10);
    arr[p] = v;
}

bool q22HashSemColisaoSimularBuscas(vector<int>& arr, int v) {
    int p = hashFunc(v, 10);

    if (arr[p] == v) {
        cout << v << " encontrado na posição: " << p << endl;
        return true;
    }

    cout << v << " não encontrado." << endl;
    return false;
}

void q23HashComEncadeamento(vector<list<int>>& arr, int v) {
    int p = hashFunc(v, 10);
    arr[p].push_back(v);
}

void q24HashBusca(vector<list<int>>& arr, int v) {
    int p = hashFunc(v, 10);
    int percorridos = 0;

    for (int valor: arr[p]) {
        percorridos++;

        if(valor == v) {
            cout << v << " encontrado!" << endl;
            cout << "Posicao da tabela: " << p << endl;
            cout << "Posicao na lista: " << p << endl;
            cout << "Elementos percorridos: " << percorridos << endl;
            return;
        }
        p++;
    }
    cout << v << " nao encontrado." << endl;
    cout << "Posicao da tabela: " << p << endl;
    cout << "Elementos percorridos: " << percorridos << endl;
}


void q25e26HashSondagemLinear(vector<int>& arr, int v) {
    int p = hashFunc(v, 7);
    int colisoes = 0;

    while(arr[p] != -1) {
        colisoes++;

        p = (p + 1) % arr.size();

        // p++;
        // if (p == arr.size()) {
        //     p = 0;
        // }
    }
    arr[p] = v;

    cout << v << " inserido na posicao " << p << endl;
    cout << "Colisoes: " << colisoes << endl;
}

int main() {
    vector<int> q21(10, -1);

    q21HashSemColisao(q21, 12);
    q21HashSemColisao(q21, 15);
    q21HashSemColisao(q21, 37);
    q21HashSemColisao(q21, 44);
    q21HashSemColisao(q21, 51);
    q22HashSemColisaoSimularBuscas(q21, 12);

    return 0;
}