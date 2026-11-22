#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string nome;
    int codigo;
    float preco;
};

void exibirProduto(const Produto& p) {
    cout << "\n--- Produto ---\n";
    cout << "Nome: " << p.nome << endl;
    cout << "Codigo: " << p.codigo << endl;
    cout << "Preco: R$ " << p.preco << endl;
}

int main() {
    Produto p;

    cout << "Nome do produto: ";
    getline(cin, p.nome);

    cout << "Codigo: ";
    cin >> p.codigo;

    cout << "Preco: ";
    cin >> p.preco;

    exibirProduto(p);
    return 0;
}