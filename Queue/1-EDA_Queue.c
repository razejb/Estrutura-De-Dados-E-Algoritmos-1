/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Queue (fila)
struct Queue
{
    int size;   // tamanho da fila
    int front;  // posição do elemento dianteiro
    int rear;   // posição do elemento traseiro
    int *Q;     // array para armazenar os elementos da fila
};

// Função para criar a fila
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Função para inserir um elemento no final da fila
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("A fila está cheia\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Função para remover um elemento da frente da fila e retornar o seu valor
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("A fila está vazia\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Função para exibir os elementos da fila
void Display(struct Queue q)
{
    int i;

    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);

    printf("\n");
}

int main()
{
    struct Queue q;

    create(&q, 5);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 12);
    enqueue(&q, 23);

    Display(q);

    printf("%d ", dequeue(&q));

    return 0;
}
