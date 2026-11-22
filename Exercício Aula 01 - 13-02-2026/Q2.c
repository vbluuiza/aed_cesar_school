// Aluna: Maria Luiza Vieira Belo - 3º Período do curso Análise e Desenvolvimento de Sistemas (Regular)


#include <stdio.h>

typedef struct {
    float matematicaNota;
    float fisicaNota;
} NotasAlunos;

typedef struct {
    char nome[50];
    NotasAlunos notas;
    float media;

} Aluno;

// Obs:  O requisito pedia "três variáveis do tipo struct", porém optei por utilizar um vetor de  structs com loop para evitar repetição de código e tornar a solução mais eficiente e escalável. A lógica e funcionalidade permanecem as mesmas.

int main() {
    Aluno alunos[3];
    int i;

    for(i = 0; i < 3; i++) { 
        printf("Aluno [%d]\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Nota de Matemática: ");
        scanf("%f", &alunos[i].notas.matematicaNota);

        printf("Nota de Física: ");
        scanf("%f", &alunos[i].notas.fisicaNota);

        float media = (alunos[i].notas.matematicaNota + alunos[i].notas.fisicaNota) / 2;
        alunos[i].media = media;

        printf("\n");
    }

    printf("\nDADOS DOS ALUNOS\n\n");
    for(i = 0; i < 3; i++) {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Nota de Matemática e Física: %.2f | %.2f\n", alunos[i].notas.matematicaNota, alunos[i].notas.fisicaNota);
        printf("Média: %.2f\n", alunos[i].media);
        printf("\n");
    }

    return 0;
}