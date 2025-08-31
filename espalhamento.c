#include <stdio.h>
#include <stdlib.h>

char nome[20];
int soma = 0;
int i, tam, hash;

void main() {
    printf("Informe o nome a ser calculado para a classe: ");
    scanf("%s", &nome);
    tam = strlen(nome);

    for (i = 0; i < tam; i++) {
        soma += nome[i];
    }

    hash = (soma % 5) + 1;

    printf("\nA classe pertence %d referente ao nome %s.\n", hash, nome);
    system("pause");
}
