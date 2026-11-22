#include <iostream>
// using namespace std;

struct No {
    int dado;
    No* prox;
};

No* inserirInicio(No* head, int valor) {
    No* novoNo = new No;
    novoNo->dado = valor;
    novoNo->prox = head;  // novo aponta para o antigo início
    return novoNo;        // novo vira o início — main faz head = retorno
}

No* inserirFim(No* head, int valor) {
    No* novoNo = new No;
    novoNo->dado = valor;
    novoNo->prox = NULL;

    if (!head)          // lista vazia: novo é o único nó // O mesmo que if(head == NULL) [Vira o Head]
        return novoNo;

    No* atual = head;
    while (atual->prox != NULL)   // caminha até o último nó     // O mesmo que while(atual->prox != NULL)
        atual = atual->prox;

    atual->prox = novoNo;   // último nó aponta para o novo
    return head;        // head não mudou
}

No* inserirMeio(No* head, int valorNovo, int valorBusca) {
    No* novoNo = new No;
    novoNo->dado = valorNovo;
    novoNo->prox = NULL;

    No* atual = head;
    // para no nó ANTES do que tem valorBusca
    while (atual->prox && atual->prox->dado != valorBusca)  
    // e.g: atual →  você está no nó [30]  | atual->prox →  você foi pro nó [20] | atual->prox->dado  →  você pegou o dado do nó [20]  (leu o campo)
        atual = atual->prox;

    novoNo->prox = atual->prox;  // novo aponta para o nó com valorBusca
    atual->prox = novoNo;        // nó anterior aponta para o novo
    return head;
}

No* remover(No* head, int valor) { // forma ruim com um milhão de condições
    No* atual = head;
    No* anterior = NULL;

    while (atual && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) // (!atual) 
        return head;  // atual percorre tudo e vira NULL → não achou → retorna head

    if (anterior == NULL) // (!anterior)   // Se anterior ainda é NULL, significa que o while nunca entrou — o primeiro nó já era o valor buscado. Ou seja, você quer remover o head.
        head = atual->prox;  
    else    // Caso normal — achou o valor no meio ou no final. anterior está no nó antes do que vai ser removido, então você pula o atual:
        anterior->prox = atual->prox;  // pula o nó

    delete atual;  // Nos três casos, quando chega aqui o atual já foi desconectado da lista. Aí sim o delete faz sentido — libera a memória do nó que saiu.
    return head;
}

No* remover2(No*& head, int valor) { // forma elegante usando ponteiro para ponteiro
    No** atual = &head;

    while (*atual && (*atual)->dado != valor) {
        atual = &(*atual)->prox;
    }

    if (*atual) {
        No* temp = *atual;
        *atual = temp->prox;
        delete temp;
    }

    return head;
}

void imprimirLista(No* head) {
    No* atual = head;
    while (atual) {
        std::cout << atual->dado << " -> ";
        atual = atual->prox;
    }
    std::cout << "NULL\n";
}

int buscar(No *head, int valor) {
    while (head) {
        if (head->dado ==  valor) {
            std::cout << "Valor existe\n";
            return 1;
        }
        head = head->prox;
    }

    std::cout << "Valor não existe\n";
    return 0;
}

void liberarLista(No*& head) {
    while (head) {
        No* atual = head;
        head = head->prox;
        delete atual;
    }
    std::cout << "Lista liberada!" << std::endl;
}

int main() {
    No* head = nullptr;
    head = inserirInicio(head, 10);  // [10→NULL]
    head = inserirInicio(head, 20);  // [20→10→NULL]
    head = inserirInicio(head, 30);  // [30→20→10→NULL]
    int existe = buscar(head, 10);
    std::cout << existe;
    head = inserirMeio(head, 99, 20); // [30→99→20→10→NULL]
    head = remover(head, 20); // [30→99→10→NULL]x
    imprimirLista(head); // 99 → 10 → NULL

    liberarLista(head);
}