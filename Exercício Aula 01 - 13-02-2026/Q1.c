// Aluna: Maria Luiza Vieira Belo - 3º Período do curso Análise e Desenvolvimento de Sistemas (Regular)

#include <stdio.h>

typedef struct {
    int dia;
    int ano;
} Data;

typedef struct {
    char nome[50];
    int idade;
    Data dataNascimento;
    char mes[50];
    float salario;
} Funcionario;

int main() {
    Funcionario funcionarios[3];
    int i;
    
    for(i = 0; i < 3; i++) {
        printf("Funcionário [%d]\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);

        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);

        printf("Data de nascimento (ano): ");
        scanf("%d", &funcionarios[i].dataNascimento.ano);

        printf("Data de nascimento (dia): ");
        scanf("%d", &funcionarios[i].dataNascimento.dia);

        printf("Mês: ");
        scanf("%s", funcionarios[i].mes);

        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
        
        printf("\n");
    }

    printf("\nDADOS DOS FUNCIONÁRIOS\n\n");
    for(i = 0; i < 3; i++) {
        printf("Funcionário [%d]\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Data de nascimento: %s dia %d de %d\n", funcionarios[i].mes, funcionarios[i].dataNascimento.dia, funcionarios[i].dataNascimento.ano);
        printf("Salário: %.2f\n", funcionarios[i].salario);
        printf("\n");
    }

    return 0;
}   