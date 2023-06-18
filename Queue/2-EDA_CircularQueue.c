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
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Função para enfileirar (inserir) um elemento no final da fila
void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("A fila está cheia\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Função para desenfileirar (remover) um elemento da frente da fila e retornar o seu valor
int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("A fila está vazia\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Função para exibir os elementos da fila
void Display(struct Queue q)
{
    int i = q.front + 1;

    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

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
