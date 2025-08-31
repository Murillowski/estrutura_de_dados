#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int codigo;
    struct no *left, *right;
} no;

no *raiz = NULL;
no *corrente = NULL;
no *auxiliar = NULL;

void enterData() {
    printf("\nDigite o valor do novo no: ");
    scanf("%d", &corrente->codigo);
}

void insert() {
    corrente = (no*)malloc(sizeof(no));
    corrente->right = NULL;
    corrente->left = NULL;
    enterData();

    if (raiz == NULL) {
        raiz = corrente;
        printf("\nInserido com sucesso o elemento na raiz. . .\n");
        system("pause");
    } else {
        auxiliar = raiz;

        while (1) {
            if (auxiliar->codigo < corrente->codigo) { // Direita
                if (auxiliar->right == NULL) {
                    auxiliar->right = corrente;
                    printf("\nElemento inserido com sucesso a direita da arvore. . .\n");
                    system("pause");
                    break;
                } else {
                    auxiliar = auxiliar->right;
                }
            } else if (auxiliar->codigo > corrente->codigo) { // Esquerda
                if (auxiliar->left == NULL) {
                    auxiliar->left = corrente;
                    printf("\nElemento inserido com sucesso a esquerda da arvore. . .\n");
                    system("pause");
                    break;
                } else {
                    auxiliar = auxiliar->left;
                }
            } else {
                printf("\nChave duplicada, tente novamente. . .\n");
                system("pause");
                break;
            }
        }
    }
}

void exibir(no *raiz, int eRaiz) {
    if (raiz == NULL) {
        printf("\nArvore vazia. . .\n");
    } else {
        if (eRaiz == 1) printf("\n(Raiz)\n");
        printf("Codigo: %d\n", raiz->codigo);
        if (raiz->left != NULL) printf("\n(Esquerda)\n"), exibir(raiz->left, 0);
        if (raiz->right != NULL) printf("\n(Direita)\n"), exibir(raiz->right, 0);
    }
}

int main() {
    int op;

    do {
        system("cls");
        printf("\n[ 1 ] Inserir elemento na arvore");
        printf("\n[ 2 ] Exibir elementos da arvore");
        printf("\n[ 3 ] Pesquisar elementos da arvore");
        printf("\n[ 4 ] Sair do sistema");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: insert(); break;

            case 2: exibir(raiz, 1); system("pause"); break;

            case 3: system("pause"); break;

            case 4: break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                system("pause");
        }
    } while (op != 4);

    return 0;
}
