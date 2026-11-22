#include <iostream>

struct No {
    int dado;
    No* prox;

    No(int valor, No* p = nullptr) : dado(valor), prox(p) {}
};


void inserirInicio(No** head, int valor) {
    *head = new No(valor);
}


void inserirFim(No** head, int valor) {
    No* novo = new No(valor);

    if (!(*head)) {
        *head = novo;
        return;
    }

    No* atual = *head;
    while (atual->prox)
        atual = atual->prox;

    atual->prox = novo;
}

// Remover valores repetidos
void remover(No *head) {
    No* atual = head;

    while (atual && atual->prox != NULL) {
        if (atual->dado == atual->prox->dado) {
            No *temp = atual->prox;
            atual->prox = temp->prox;
            delete temp;
        }
        else {
            atual = atual->prox;
        }
    }
}

void imprimir(No *head) {
    No* atual = head;
    while (atual) {
        std::cout << atual->dado << " -> ";
        atual = atual->prox;
    }
    std::cout << "NULL\n";
}

int main() {
    No *head = nullptr;
    int x = 0;
    
    std::string soma = "somando";
    inserirInicio(&head, 10);
    inserirFim(&head, 10);
    inserirFim(&head, 20);
    inserirFim(&head, 30);
    inserirFim(&head, 30);
    inserirFim(&head, 30);
    inserirFim(&head, 40);

    std::cout << "Lista antes: " <<std::endl;
    imprimir(head);
    remover(head);

    std::cout << "Lista Depois: " <<std::endl;
    imprimir(head);

    return 0;
}