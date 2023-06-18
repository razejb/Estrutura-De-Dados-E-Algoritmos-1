/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Node (nó)
struct Node
{
    int data;           // valor do nó
    struct Node *next;  // ponteiro para o próximo nó
}
*front = NULL, *rear = NULL;

// Função para inserir um elemento no final da fila
void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("A fila está cheia\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

// Função para desenfileirar remover um elemento da frente da fila e retornar o seu valor
int dequeue()
{
    int x = -1;

    struct Node *t;

    if (front == NULL)
        printf("A fila está vazia\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

// Função para exibir os elementos da fila
void Display()
{
    struct Node *p = front;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(12);
    enqueue(23);

    Display();

    printf("%d ", dequeue());

    return 0;
}
