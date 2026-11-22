#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Paciente {
    string nome;
    int idade;
    string diagnostico;
};

void exibirIdosos(const vector<Paciente>& pacientes) {
    cout << "\nPacientes acima de 60 anos:\n";
    for (const auto& p : pacientes) {
        if (p.idade > 60) {
            cout << "\nNome: " << p.nome << endl;
            cout << "Idade: " << p.idade << endl;
            cout << "Diagnostico: " << p.diagnostico << endl;
        }
    }
}

int main() {
    vector<Paciente> pacientes(3);

    for (int i = 0; i < 3; i++) {
        cout << "\nPaciente " << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nome: ";
        getline(cin, pacientes[i].nome);

        cout << "Idade: ";
        cin >> pacientes[i].idade;
        cin.ignore();

        cout << "Diagnostico: ";
        getline(cin, pacientes[i].diagnostico);
    }

    exibirIdosos(pacientes);
    return 0;
}