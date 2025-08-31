#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int ra;
    char nome[20];
    struct no *next, *back;
} no;

no *corrente, *auxiliar, *auxiliar2, *inicio, *fim;

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
        corrente = (no*)malloc(sizeof(no)); // Aloca um novo n�, apontado pelo corrente
        corrente->next = NULL; // O pr�ximo n� � NULL, pois ser� o �ltimo
        corrente->back = NULL; // O n� enterior � NULL, pois ser� o primeiro
        auxiliar = corrente; // O ponteiro auxiliar aponta para o novo n�
        inicio = corrente; // In�cio aponta para o novo n�
        enterData(); // Chama fun��o para inser��o
    } else {
        corrente = (no*)malloc(sizeof(no)); // Aloca um novo n�, apontado pelo corrente
        auxiliar->next = corrente; // O pr�ximo n� de auxiliar � o novo n�
        corrente->back = auxiliar; // O n� anterior do novo n� � o auxiliar
        corrente->next = NULL; // O pr�ximo n� do novo n� � NULL, pois ser� o �ltimo
        auxiliar = corrente; // O ponteiro auxiliar aponta para o novo n�
        fim = corrente; // O ponteiro n� aponta para o �ltimo da lista (�ltimo n�)
        enterData(); // Chama fun��o para inser��o
    }
}

void insert_class() {
    corrente = (no*)malloc(sizeof(no));
    enterData();
    auxiliar = inicio;
    int achou = 0;

    if (inicio == NULL) {
        achou = 1;
        corrente->back = NULL;
        corrente->next = NULL;
        inicio = corrente;
        fim = corrente;
        printf("\nPrimeiro elemento da lista inserido com sucesso\n");
        system("pause");
    } else {
        if (strcmp(corrente->nome, auxiliar->nome) < 0) {
            achou = 1;
            auxiliar->back = corrente;
            corrente->next = auxiliar;
            corrente->back = NULL;
            inicio = corrente;
            printf("\nO elemento precedeu o primeiro elemento da lista\n");
            system("pause");
        } else {
            auxiliar = auxiliar->next;

            while (auxiliar2 != NULL) {
                if (strcmp(corrente->nome, auxiliar->nome) > 0 && strcmp(corrente->nome, auxiliar2->nome) < 0) {
                    achou = 1;
                    auxiliar->next = corrente;
                    corrente->back = auxiliar;
                    corrente->next = auxiliar2;
                    auxiliar2->back = corrente;
                    printf("\nElemento foi inserido com sucesso no meio lista\n");
                    system("pause");
                    break;
                } else {
                    auxiliar = auxiliar->next;
                    auxiliar2 = auxiliar->next;
                }
            }

            if (achou == 0 && strcmp(corrente->nome, auxiliar2->nome) > 0) {
                auxiliar2->next = corrente;
                corrente->back = auxiliar2;
                corrente->next = NULL;
                printf("\nO elemento foi inserido com sucesso no fim da lista\n");
                system("pause");
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
        auxiliar = fim;

        while (auxiliar != NULL) {
            k++;
            if (strcmp(auxiliar->nome, nome) == 0) {
                printf("\nO registro foi encontrado na posicao %d da lista\n\n", k);
                achou = 1;
                break;
            } else {
                auxiliar = auxiliar->back;
            }
        }
        if (achou == 0) {
            printf("\nRegistro nao consta na lista\n\n");
        }
    }
}

// 'remover' por ChatGPT
void remover() {
    char nome[20];
    int achou = 0;

    printf("\nInforme o nome a ser excluido: ");
    scanf("%s", nome);

    if (inicio == NULL) {
        printf("\nLista vazia\n");
        return;
    }

    auxiliar = inicio;

    // Caso o n� a ser removido seja o primeiro
    if (strcmp(auxiliar->nome, nome) == 0) {
        inicio = auxiliar->next; // Atualiza o ponteiro inicio

        if (inicio != NULL) {
            inicio->back = NULL; // Se a lista n�o ficar vazia, o pr�ximo n� n�o tem anterior
        }

        free(auxiliar); // Libera a mem�ria do n� removido
        printf("\nPrimeiro elemento da lista removido com sucesso\n");
        achou = 1;
    } else {
        // Caso o n� a ser removido esteja no meio ou no final
        while (auxiliar != NULL) {
            if (strcmp(auxiliar->nome, nome) == 0) {
                if (auxiliar->next != NULL) {
                    auxiliar->next->back = auxiliar->back; // Atualiza o ponteiro back do pr�ximo n�
                }

                if (auxiliar->back != NULL) {
                    auxiliar->back->next = auxiliar->next; // Atualiza o ponteiro next do n� anterior
                }

                // Caso o n� seja o �ltimo, atualiza o ponteiro fim
                if (auxiliar->next == NULL) {
                    fim = auxiliar->back;
                }

                free(auxiliar); // Libera a mem�ria do n� removido
                printf("\nElemento removido com sucesso\n");
                achou = 1;
                break;
            }
            auxiliar = auxiliar->next;
        }
    }

    if (!achou) {
        printf("\nO elemento nao foi encontrado na lista\n");
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
                insert_class();
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
                printf("\nOpcao invalida, tente novamente\n");
                system("pause");
                break;
        }
    } while (op != 5);

    return 0;
}
