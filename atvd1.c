#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 3

struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
};

void cabecalho() {
    printf("\n-------------------------------\n");
    printf("\tContatos Cadastrados");
    printf("\n-------------------------------\n");
}

void limpaTela() {
    int caractere;
    int i;

    for (i = 0; i < MAX_CONTATOS; i++) {
        while ((caractere = getchar()) != '\n' && caractere != EOF);
    }
    system("cls || clear");
}

void cadastrarContatos(struct Contato contatos[]) {
    int i;

    for (i = 0; i < MAX_CONTATOS; i++) {
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", contatos[i].nome);

        printf("Digite o numero de telefone do contato %d: ", i + 1);
        scanf("%s", contatos[i].telefone);

        printf("Digite o email do contato %d: ", i + 1);
        scanf("%s", contatos[i].email);

        printf("\n");
    }
}

char* buscarTelefonePorNome(struct Contato contatos[], char nomeBuscado[]) {
    int i;

    for (i = 0; i < MAX_CONTATOS; i++) {
        if (strcmp(contatos[i].nome, nomeBuscado) == 0) {
            return contatos[i].telefone;
        }
    }
    return ("Contato não encontrado");
}

int main() {
    struct Contato contatos[MAX_CONTATOS];

    cabecalho();
    cadastrarContatos(contatos);

    char nomeParaBuscar[50];
    printf("Digite o nome do contato para buscar o numero de telefone: ");
    scanf("%s", nomeParaBuscar);

    char* telefoneEncontrado = buscarTelefonePorNome(contatos, nomeParaBuscar);
    printf("Numero de telefone para %s: %s\n", nomeParaBuscar, telefoneEncontrado);

    limpaTela();

    return 0;
}

