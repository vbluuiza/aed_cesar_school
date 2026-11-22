#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int ano;
};

void exibirAposAno(const vector<Livro>& livros, int anoFiltro) {
    cout << "\nLivros publicados apos " << anoFiltro << ":\n";
    for (const auto& l : livros) {
        if (l.ano > anoFiltro) {
            cout << "\nTitulo: " << l.titulo << endl;
            cout << "Autor: " << l.autor << endl;
            cout << "Ano: " << l.ano << endl;
        }
    }
}

int main() {
    vector<Livro> livros(3);
    int anoFiltro;

    for (int i = 0; i < 3; i++) {
        cout << "\nLivro " << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Titulo: ";
        getline(cin, livros[i].titulo);

        cout << "Autor: ";
        getline(cin, livros[i].autor);

        cout << "Ano: ";
        cin >> livros[i].ano;
    }

    cout << "\nAno de filtro: ";
    cin >> anoFiltro;

    exibirAposAno(livros, anoFiltro);
    return 0;
}