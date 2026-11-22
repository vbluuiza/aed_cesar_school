#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

int main() {
    vector<Aluno> alunos(5);
    float soma = 0;

    for (int i = 0; i < 5; i++) {
        cout << "\nAluno " << i + 1 << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nome: ";
        getline(cin, alunos[i].nome);

        cout << "Matricula: ";
        cin >> alunos[i].matricula;

        cout << "Nota: ";
        cin >> alunos[i].nota;

        soma += alunos[i].nota;
    }

    cout << "\nMedia das notas: " << soma / 5 << endl;
    return 0;
}