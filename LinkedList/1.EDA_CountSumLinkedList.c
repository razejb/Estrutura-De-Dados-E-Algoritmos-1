/*--------------------------------------------------------------
|                                                              |
|                     Criado por: João Santos                  |
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

// Função para contar o número de nós na lista ligada (iterativa)
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// Função para contar o número de nós na lista ligada (recursiva)
int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}

// Função para calcular a soma dos elementos na lista ligada (iterativa)
int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

// Função para calcular a soma dos elementos na lista ligada (recursiva)
int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    
    printf("Count %d\n", count(first));
    printf("Sum %d\n", sum(first));

    return 0;
}

