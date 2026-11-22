#include <iostream>
#include <string>
using namespace std;

struct Carro {
    string modelo;
    int ano;
    float preco;
};

int main() {
    Carro* c = new Carro;

    cout << "Modelo: ";
    getline(cin, c->modelo);

    cout << "Ano: ";
    cin >> c->ano;

    cout << "Preco: ";
    cin >> c->preco;

    cout << "\n--- Carro ---\n";
    cout << "Modelo: " << c->modelo << endl;
    cout << "Ano: " << c->ano << endl;
    cout << "Preco: R$ " << c->preco << endl;

    delete c;
    return 0;
}