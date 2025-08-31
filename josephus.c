#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return value;
}

int josephusQueue(int n, int k) {
    Queue* q = createQueue();

    for (int i = 1; i <= n; i++)
        enqueue(q, i);

    while (q->front != q->rear) {
        for (int i = 1; i < k; i++) {
            int val = dequeue(q);
            enqueue(q, val);
        }
        int eliminado = dequeue(q);
        printf("\nEliminiado: %d\n", eliminado);
    }

    int sobrevivente = dequeue(q);
    free(q);
    return sobrevivente;
}

int main() {
    int n, k;
    printf("Digite o número de pessoas (n): ");
    scanf("%d", &n);
    printf("\nDigite o valor de saldo (k): ");
    scanf("%d", &k);

    int sobrevivente = josephusQueue(n, k);
    printf("\n\nO sobrevivente é: %d\n", sobrevivente);

    return 0;
}