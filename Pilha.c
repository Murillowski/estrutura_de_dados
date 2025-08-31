#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct pilha {
    char item[10];
    char itemProcruado[10];
    struct pilha *next, *back;
} pilha;

pilha *topo, *auxiliar;

void enterData() {
    printf("\nInforme o item: ");
    scanf("%s", &topo->item);
}

void push() {
    if (topo == NULL) {
        topo = (pilha*)malloc(sizeof(pilha)); // Espaço alocado em um novo endereço de memória
        topo->back = NULL; // Endereço anterior vazio
        topo->next = NULL; // Endereço posterior vazio
        auxiliar = topo; // auxiliar movido para endereço do topo, para garantir a base quando o topo for movido para um novo endereço
        enterData();
    } else {
        topo = (pilha*)malloc(sizeof(pilha)); // Espaço alocado em um novo endereço de memória
        auxiliar->next = topo; // Endereço posterior do auxiliar é o endereço do topo
        topo->next = NULL; // Endereço posterior do topo vazio
        topo->back = auxiliar; // Endereço anterior do topo é o endereço do auxiliar
        auxiliar = topo; // auxiliar movido para endereço do topo, para garantir a base quando o topo for movido para um novo endereço
        enterData();
    }
}

void top() {
    if (topo == NULL) {
        printf("\nA pilha esta vazia\n");
    } else {
        auxiliar = topo;
        printf("\nItem: %s\n", auxiliar->item);
    }
}

void pop() {
    if (topo == NULL) {
        printf("\nA pilha esta vazia\n");
    } else {
        if (topo->back == NULL) {
            printf("\nItem a ser removido: %s\n", topo->item);
            free(auxiliar);
            topo = NULL;
            auxiliar = NULL;
            printf("\nUltimo item removido\n");
        } else {
            auxiliar = topo->back;
            auxiliar->next = NULL;
            topo->back = NULL;
            printf("\nItem a ser removido: %s\n", topo->item);
            free(topo);
            topo = auxiliar;
            printf("\nItem do topo removido\n");
        }
    }
}

int main() {
    topo = NULL;
    auxiliar = NULL;
    int op;

    do {
        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserindo elementos na pilha");
        printf("\n [ 2 ] Exibindo o elemento do topo da pilha");
        printf("\n [ 3 ] Removendo os elementos da pilha");
        printf("\n [ 4 ] Sair do sistema");
        printf("\n\nInforme a opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                push();
                printf("\n");
                break;
            case 2:
                top();
                printf("\n");
                system("pause");
                break;
            case 3:
                pop();
                printf("\n");
                system("pause");
                break;
            case 4:
                break;
            default:
                printf("\nOpcao invalida, tente novamente\n");
                printf("\n");
                system("pause");
        }
    } while (op != 4);

    return 0;
}
