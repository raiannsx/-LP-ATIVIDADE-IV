#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUMERO_ALUNOS 5

struct Aluno {
    char nome[50];
    char dataNascimento[20];
    float primeiraNota;
    float segundaNota;
    float media;
};

void cabecalho() {
    printf("\n-------------------------------\n");
    printf("\tMedia do Aluno");
    printf("\n-------------------------------\n");
}

void limpaTela() {
    int characte;
    while ((characte = getchar()) != '\n' && characte != EOF);
    system("cls || clear");
}

float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

void situacaoAluno(float media) {
    if (media >= 7) {
        printf("Aluno Aprovado!\n");
        printf("MEdia Final do Aluno: %.1f\n", media);
    } else {
        printf("Aluno Reprovado!\n");
        printf("Média Final do Aluno: %.1f\n", media);
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int i;
    struct Aluno alunos[NUMERO_ALUNOS];

    for (i = 0; i < NUMERO_ALUNOS; i++) {
        cabecalho();

        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a data de nascimento do aluno %d: ", i + 1);
        scanf("%s", alunos[i].dataNascimento);

        printf("Digite a primeira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].primeiraNota);

        printf("Digite a segunda nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].segundaNota);

        alunos[i].media = calcularMedia(alunos[i].primeiraNota, alunos[i].segundaNota);

        limpaTela();
        cabecalho();
        situacaoAluno(alunos[i].media);
    }

    return 0;
}
