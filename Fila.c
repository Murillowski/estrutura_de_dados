#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int date, nr;
    struct no *next;
} no;

no *start = NULL, *end = NULL;
int c = 0;

void enterData(no *node) {
    printf("\nInforme o Dado (date): ");
    scanf("%d", &node->date);

    printf("Informe o numero do trabalho (nr): ");
    scanf("%d", &node->nr);
}

void Enqueue() {
    if (c >= 5) {
        printf("\nFila cheia...\n");
        system("pause");
        return;
    }

    no *newNode = (no*)malloc(sizeof(no));
    newNode->next = NULL;

    enterData(newNode);

    if (start == NULL) {
        start = end = newNode;
    } else {
        end->next = newNode;
        end = newNode;
    }

    c++;
    printf("\nElemento inserido com sucesso!\n");
    system("pause");
}

void Dequeue() {
    if (start == NULL) {
        printf("\nFila vazia...\n");
        system("pause");
        return;
    }

    no *temp = start;
    start = start->next;
    free(temp);
    c--;

    if (start == NULL) {
        end = NULL;
    }

    printf("\nElemento removido com sucesso!\n");
    system("pause");
}

void Seaqueue() {
    if (start == NULL) {
        printf("\nFila vazia...\n");
        system("pause");
        return;
    }

    int job, pos = 1, found = 0;
    printf("\nDigite o numero do trabalho a buscar: ");
    scanf("%d", &job);

    no *aux = start;
    while (aux != NULL) {
        if (aux->nr == job) {
            printf("\nEncontrado na posicao %d\n", pos);
            found = 1;
            break;
        }
        aux = aux->next;
        pos++;
    }

    if (!found) {
        printf("\nTrabalho nao encontrado na fila.\n");
    }

    system("pause");
}

void ListQueue() {
    if (start == NULL) {
        printf("\nFila vazia...\n");
    } else {
        printf("\nElementos na fila:\n");
        no *aux = start;
        int i = 1;
        while (aux != NULL) {
            printf("Posicao %d -> date: %d | nr: %d\n", i++, aux->date, aux->nr);
            aux = aux->next;
        }
    }
    system("pause");
}

int main() {
    int op;

    do {
        system("cls");
        printf("\n[ 1 ] Inserir elemento na fila");
        printf("\n[ 2 ] Listar elementos da fila");
        printf("\n[ 3 ] Remover elemento da fila");
        printf("\n[ 4 ] Buscar por numero do trabalho");
        printf("\n[ 5 ] Sair do sistema");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: Enqueue(); break;
            case 2: ListQueue(); break;
            case 3: Dequeue(); break;
            case 4: Seaqueue(); break;
            case 5: break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                system("pause");
        }
    } while (op != 5);

    return 0;
}
