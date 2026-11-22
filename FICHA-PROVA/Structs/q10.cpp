#include <iostream>
#include <string>
using namespace std;

struct ContaBancaria {
    string titular;
    int numero;
    float saldo;
};

void depositar(ContaBancaria& c, float valor) {
    if (valor > 0) c.saldo += valor;
}

void sacar(ContaBancaria& c, float valor) {
    if (valor > 0 && valor <= c.saldo) {
        c.saldo -= valor;
    } else {
        cout << "Saldo insuficiente ou valor invalido.\n";
    }
}

void exibirSaldo(const ContaBancaria& c) {
    cout << "Saldo atual: R$ " << c.saldo << endl;
}

int main() {
    ContaBancaria conta{"Luiza", 12345, 1000.0f};
    int opcao;
    float valor;

    do {
        cout << "\n1 - Depositar\n2 - Sacar\n3 - Exibir saldo\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Valor para deposito: ";
                cin >> valor;
                depositar(conta, valor);
                break;
            case 2:
                cout << "Valor para saque: ";
                cin >> valor;
                sacar(conta, valor);
                break;
            case 3:
                exibirSaldo(conta);
                break;
        }
    } while (opcao != 0);

    return 0;
}