#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ra 5

void cabecalho()
{
    printf("\n-------------------------------\n");
    printf("\tMedia do Aluno");
    printf("\n-------------------------------\n");
}

void limpa()
{
    fflush(stdin);
    system("cls || clear");
}

void media(float notas[])
{
    int i;
    float medias;
    float soma = 0;
    for (i = 0; i < ra; i++)
    {
        soma += notas[i];
    }
    
    medias = soma / 3;

    if (medias >= 7)
    {
        printf("Aluno Aprovado!\n");
        printf("Media Final do Aluno: %.1f\n", medias);
    }
    else
    {
        printf("Aluno Reprovado!\n");
        printf("Media Final do Aluno: %.1f\n", medias);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float notas[ra];
    int i;

    cabecalho();
    for (i = 0; i < ra; i++)
    {
        printf("Digite a %d nota do aluno: ", i + 1);
        scanf("%f", &notas[i]);
    }
    limpa();

    cabecalho();
    media(notas);

    return 0;
}