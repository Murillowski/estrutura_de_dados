#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int ra;
    char nome[20];
    struct no *next;
} no;

no *corrente, *auxiliar, *auxiliar2, *inicio;

void enterData() {
    printf("\nInforme o Ra: ");
    scanf("%d", &corrente->ra);
    printf("\nInforme o nome: ");
    scanf("%s", &corrente->nome);
}

void exibir() {
    if (inicio == NULL) {
        printf("\nLista vazia\n");
    } else {
        auxiliar = inicio;
        while (auxiliar != NULL) {
            printf("\nRa.....: %d", auxiliar->ra);
            printf("\nNome...: %s", auxiliar->nome);
            printf("\n");
            auxiliar = auxiliar->next;
        }
    }
}

void insert() {
    if (inicio == NULL) {
        corrente = (no*)malloc(sizeof(no));
        auxiliar = corrente;
        inicio = corrente;
        corrente->next = NULL;
        enterData();
    } else {
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
        auxiliar = corrente;
        enterData();
    }
}

void insert_alfabeta() {
    int achou = 0;
    corrente = (no*)malloc(sizeof(no));
    corrente->next = NULL;
    enterData();

    if (inicio == NULL) {
        auxiliar = corrente;
        inicio = corrente;
        corrente -> next = NULL;
        printf("\nImplementando o primeiro no na lista\n");
        system("pause");
        achou = 1;
    } else {
        auxiliar = inicio;

        if (strcmp(corrente->nome, auxiliar->nome) < 0) {
            corrente -> next = auxiliar;
            inicio = corrente;
            printf("\nElemento foi inserido no incio da lista\n");
            system("pause");
            achou=1;
        } else {
            auxiliar2 = inicio -> next;

            while (auxiliar2 != NULL) {
                if (strcmp(corrente->nome, auxiliar->nome) > 0 && strcmp(corrente->nome, auxiliar2->nome) < 0) {
                    auxiliar->next = corrente;
                    corrente->next = auxiliar2;
                    //auxiliar2 = NULL;
                    printf("\nElemento foi inserido no meio lista\n");
                    system("pause");
                    achou = 1;
                    break;
                } else {
                    auxiliar=auxiliar->next;
                    auxiliar2 = auxiliar2->next;
                }
            }

            if (achou == 0) {
                auxiliar->next = corrente;
                //corrente->next = NULL;
            }
        }
    }
}

void consultar() {
    char nome[20];
    int achou = 0, k = 0;

    if (inicio == NULL) {
        printf("\nLista vazia\n");
    } else {
        printf("\nInforme o nome do aluno: ");
        scanf("%s", nome);
        corrente = inicio;
        while (corrente != NULL) {
            k++;
            if (strcmp(corrente->nome, nome) == 0) {
                printf("\nO registro foi encontrado na posicao %d da lista\n", k);
                achou = 1;
                break;
            } else {
                corrente = corrente->next;
            }
        }
        if (achou == 0) {
            printf("\nRegistro nao consta na lista\n\n");
        }
    }
}

void remover() {
    char nome[20];
    int achou = 0, k = 0;

    if (inicio == NULL) {
        printf("\nLista vazia\n");
    } else {
        printf("\nInforme o nome do aluno: ");
        scanf("%s", nome);

        // Caso especial: remover o primeiro nó (cabeça da lista)
        if (strcmp(inicio->nome, nome) == 0) {
            auxiliar = inicio;
            inicio = inicio->next;  // Atualiza o ponteiro 'inicio'
            free(auxiliar);  // Libera a memória do nó removido
            printf("\nO registro da posicao %d foi excluido\n", k + 1);
            achou = 1;
        } else {
            corrente = inicio;
            while (corrente->next != NULL) {
                k++;
                if (strcmp(corrente->next->nome, nome) == 0) {
                    auxiliar = corrente->next;  // Nó a ser removido
                    corrente->next = auxiliar->next;  // Remove o nó da lista
                    free(auxiliar);  // Libera a memória do nó removido
                    printf("\nO registro da posicao %d foi excluido\n", k + 1);
                    achou = 1;
                    break;
                } else {
                    corrente = corrente->next;
                }
            }
        }

        if (achou == 0) {
            printf("\nRegistro nao consta na lista\n\n");
        }
    }
}

int main() {
    corrente = NULL;
    auxiliar = NULL;
    inicio = NULL;
    int op;

    do {
        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserindo elementos na lista");
        printf("\n [ 2 ] Exibindo os elementos da lista");
        printf("\n [ 3 ] Removendo os elementos da lista");
        printf("\n [ 4 ] Consulta dos elementos da lista");
        printf("\n [ 5 ] Sair do sistema");
        printf("\n\nInforme a opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insert_alfabeta();
                break;
            case 2:
                exibir();
                system("pause");
                break;
            case 3:
                remover();
                system("pause");
                break;
            case 4:
                consultar();
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("\nOpcao invalida, tente novamente");
                system("pause");
        }
    } while (op != 5);

    return 0;
}
