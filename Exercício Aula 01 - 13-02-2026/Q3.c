// Aluna: Maria Luiza Vieira Belo - 3º Período do curso Análise e Desenvolvimento de Sistemas (Regular)


#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidadeVendida;
    float valorTotalVendas;
} Produto;

int main() {
    Produto produtos[10];
    for (int i = 0; i < 10; i++) {
        printf("Produto [%d]\n", i + 1);

        printf("Nome do produto: ");
        scanf(" %[^\n]", produtos[i].nome);

        printf("Preço do produto: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade vendida: ");
        scanf("%d", &produtos[i].quantidadeVendida);

        float valorTotal = produtos[i].preco * produtos[i].quantidadeVendida;
        produtos[i].valorTotalVendas = valorTotal; 

        printf("\n");
    }

    printf("\nDADOS DOS PRODUTOS\n\n");
    for(int i = 0; i < 10; i++) {
        printf("Produto [%d]\n", i + 1);
        printf("Nome do Produto: %s\n", produtos[i].nome);
        printf("Preço do Produto: R$%.2f\n", produtos[i].preco);
        printf("Quantidade vendida: %d\n", produtos[i].quantidadeVendida);
        printf("Valor total de vendas do Produto %s: R$%.2f\n", produtos[i].nome, produtos[i].valorTotalVendas);

        printf("\n");
    }

    return 0;
}