#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Funcionario {
    string nome;
    string cargo;
    float salario;
};

int main() {
    int n;
    cout << "Quantidade de funcionarios: ";
    cin >> n;
    cin.ignore();

    vector<Funcionario> funcionarios(n);

    for (int i = 0; i < n; i++) {
        cout << "\nFuncionario " << i + 1 << endl;

        cout << "Nome: ";
        getline(cin, funcionarios[i].nome);

        cout << "Cargo: ";
        getline(cin, funcionarios[i].cargo);

        cout << "Salario: ";
        cin >> funcionarios[i].salario;
        cin.ignore();
    }

    cout << "\n--- Lista de Funcionarios ---\n";
    for (const auto& f : funcionarios) {
        cout << "\nNome: " << f.nome << endl;
        cout << "Cargo: " << f.cargo << endl;
        cout << "Salario: R$ " << f.salario << endl;
    }

    return 0;
}