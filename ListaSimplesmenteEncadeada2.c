#include <stdio.h>
#include <stdlib.h>

int main() {

    typedef struct no {
        int RA;
        char nome[20];
    } no;

    struct no *A, *B;
    A = NULL;
    B = NULL;

    A = (no*)malloc(sizeof(no));

    printf("Informe o RA\n");
    scanf("%d", &A -> RA);

    printf("\nInforme o nome\n");
    scanf("%s", &A -> nome);

    B = (no*)malloc(sizeof(no));

    printf("\nInforme o RA\n");
    scanf("%d", &B -> RA);

    printf("\nInforme o nome\n");
    scanf("%s", &B -> nome);

    A = B;
    B = NULL;

    printf("\nO RA do aluno %d", A -> RA);
    A = B;

}
