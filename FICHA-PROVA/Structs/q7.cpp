#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contato {
    string nome;
    string telefone;
};

int main() {
    vector<Contato> agenda;
    int opcao;

    do {
        cout << "\n1 - Adicionar contato\n2 - Buscar contato\n0 - Sair\nOpcao: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            Contato c;
            cout << "Nome: ";
            getline(cin, c.nome);
            cout << "Telefone: ";
            getline(cin, c.telefone);
            agenda.push_back(c);
        } 
        else if (opcao == 2) {
            string busca;
            cout << "Nome para buscar: ";
            getline(cin, busca);

            bool encontrou = false;
            for (const auto& c : agenda) {
                if (c.nome == busca) {
                    cout << "\nContato encontrado:\n";
                    cout << "Nome: " << c.nome << endl;
                    cout << "Telefone: " << c.telefone << endl;
                    encontrou = true;
                }
            }

            if (!encontrou) {
                cout << "Contato nao encontrado.\n";
            }
        }
    } while (opcao != 0);

    return 0;
}