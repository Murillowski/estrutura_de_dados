#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int codigo;
    char nome[20];
    struct no *next;
} no;

int i;

int main() {

    struct no *A, *B, *C;
    A = NULL;
    B = NULL;
    C = NULL;

    for(i = 0; i < 5; i ++) {

        if(C == NULL){
            A = (no*)malloc(sizeof(no));

            printf("\nInforme o codigo\n");
            scanf("%d", &A -> codigo);

            printf("\nInforme o nome\n");
            scanf("%s", &A -> nome);

            B = A;
            C = A;
            A -> next = NULL;
        } else {
            A = (no*)malloc(sizeof(no));

            printf("\nInforme o codigo\n");
            scanf("%d", &A -> codigo);

            printf("\nInforme o nome\n");
            scanf("%s", &A -> nome);

            B -> next = A;
            A -> next = NULL;
            B = A;
        }
    }

    B = C;
    while(B != NULL) {
        printf("\nCodigo: %d", B -> codigo);
        printf("\nNome: %s\n", B -> nome);
        // system(pause);
        B = B -> next;
    }

}
