#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *next, *back, *down;
} no;

no *raiz = NULL;
no *corrente = NULL;
no *auxiliar = NULL;

void enterData() {
    printf("\nDigite o valor do novo no: ");
    scanf("%d", &corrente->dado);
}

void insert_tree() {
    int op;
    corrente = (no*)malloc(sizeof(no));
    corrente->next = NULL;
    corrente->back = NULL;
    corrente->down = NULL;
    enterData();

    if (raiz == NULL) {
        raiz = corrente;
        printf("\nInstalada a raiz da arvore. . .\n\n");
        system("pause");
    } else {
        printf("\nInforme o caminho a ser alocado o dado:\n");
        printf("\n[1] - Esquerda\n\n[2] - Direita\n\n[3] - Abaixo\n\n");
        scanf("%d", &op);

        if (op == 1) {
            aloca_esquerda();
        } else if(op == 2) {
            aloca_direita();
        } else {
            aloca_abaixo();
        }
    }
}

void aloca_esquerda() {
    auxiliar = raiz;

    while (auxiliar->back != NULL) {
        auxiliar = auxiliar->back;
    }

    auxiliar->back = corrente;

    printf("\nAlocado com sucesso o dado a ESQUERDA da arvore. . .\n\n");
    system("pause");
}

void aloca_direita() {
    auxiliar = raiz;

    while (auxiliar->next != NULL) {
        auxiliar = auxiliar->next;
    }

    auxiliar->next = corrente;

    printf("\nAlocado com sucesso o dado a DIREITA da arvore. . .\n\n");
    system("pause");
}

void aloca_abaixo() {
    auxiliar = raiz;

    while (auxiliar->down != NULL) {
        auxiliar = auxiliar->down;
    }

    auxiliar->down = corrente;

    printf("\nAlocado com sucesso o dado ABAIXO da arvore. . .\n\n");
    system("pause");
}

void exibir(no* raiz, int isRoot) {
    if (raiz == NULL) {
        printf("\nArvore vazia. . .\n\n");
    } else {
        if (isRoot == 1) printf("\n RAIZ \n");
        printf("\n - %d - \n\n", raiz->dado);

        if (raiz->back != NULL) printf("\n ESQUERDA \n"), exibir(raiz->back, 0);
        if (raiz->next != NULL) printf("\n DIREITA \n"), exibir(raiz->next, 0);
        if (raiz->down != NULL) printf("\n ABAIXO \n"), exibir(raiz->down, 0);
    }
}

int search_tree(no *raiz) {
    int codigo, achou;

    printf("\nInforme o dado a ser procurado: ");
    scanf("%d", &codigo);

    achou = achou_valor(raiz, codigo, NULL);
    printf("\n");

    if (achou == 0) {
        printf("\nDado nao consta na arvore. . .\n \n");
    }

    return achou;
}

int achou_valor(no *raiz, int key, const char *pos) {
    if (raiz == NULL) return 0;

    if (key == raiz->dado) {
        if (pos != NULL) {
            printf("\nDado encontrado na %s!\n", pos, raiz->dado);
        } else {
            printf("\nDado encontrado na RAIZ!\n", raiz->dado);
        }
        return 1;
    }

    if (achou_valor(raiz->back, key, "ESQUERDA")) return 1;
    if (achou_valor(raiz->next, key, "DIREITA")) return 1;
    if (achou_valor(raiz->down, key, "ABAIXO")) return 1;

    return 0;
}




int main() {
    int op;

    do {
        system("cls");
        printf("\n[ 1 ] Inserir elemento na arvore\n");
        printf("\n[ 2 ] Exibir elementos da arvore\n");
        printf("\n[ 3 ] Pesquisar elementos da arvore\n");
        printf("\n[ 4 ] Sair do sistema\n");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: insert_tree(); break;

            case 2: exibir(raiz, 1); system("pause"); break;

            case 3: search_tree(raiz); system("pause"); break;

            case 4: break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                system("pause");
        }
    } while (op != 4);

    return 0;
}
