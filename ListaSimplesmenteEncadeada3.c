#include <stdio.h>
#include <stdlib.h>

int main() {

    int cont = 0;

    typedef struct no {
        int RA;
        char nome[20];
    } no;

    struct no *A;
    A = NULL;

    while(cont < 5) {

        A = (no*)malloc(sizeof(no));
        printf("\nInforme o RA\n");
        scanf("%d", &A -> RA);
        printf("\nInforme o nome\n");
        scanf("%s", &A -> nome);

        cont ++;
    }

    printf("\nO RA do aluno %d", A -> RA);
    printf("\nO nome do aluno %d", A -> nome);
    A = NULL;

}
