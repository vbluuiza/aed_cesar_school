#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
    float altura;
};

int main() {
    Pessoa p;

    cout << "Nome: ";
    getline(cin, p.nome);

    cout << "Idade: ";
    cin >> p.idade;

    cout << "Altura: ";
    cin >> p.altura;

    cout << "\n--- Dados da Pessoa ---\n";
    cout << "Nome: " << p.nome << endl;
    cout << "Idade: " << p.idade << endl;
    cout << "Altura: " << p.altura << endl;

    return 0;
}