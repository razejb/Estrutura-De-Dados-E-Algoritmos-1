/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Define a estrutura para um nó da lista ligada
struct Node
{
    int data;
    struct Node *next;
};

// Variável global para o primeiro nó da lista ligada
struct Node *first = NULL;

// Função para criar uma lista ligada a partir de um array de inteiros
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    // Cria o primeiro nó
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Cria e conecta os nós restantes
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Função para encontrar o valor máximo na lista ligada (iterativa)
int Max(struct Node *p)
{
    int max = 0;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// Função para encontrar o valor máximo na lista ligada (recursiva)
int RMax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return 0;
    x = RMax(p->next);

    if (x > p->data)
        return x;
    else
        return p->data;
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    
    printf("Max %d\n", Max(first));

    return 0;
}

