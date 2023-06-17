/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}
*first = NULL;

// Cria uma lista duplamente ligada a partir de um array
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    // Cria o primeiro nó
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    // Cria e conecta os nós restantes
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Exibe os elementos da lista duplamente ligados
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Conta o número de nós na lista duplamente ligados
int count(struct Node *p)
{
    int l = 0;

    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// Insere um elemento na lista duplamente ligada em uma determinada posição
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;

        if(p->next)
            p->next->prev = t;

        p->next = t;
    }
}

// Remove um elemento da lista duplamente ligada com base no índex
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;

    if(index < 1 || index > count(p))
        return -1;

    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;

        x = p->data;
        free(p);
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;

        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;

        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {3, 6, 8, 12, 17};
    create(A, 5);

    Insert(first, 2, 25);
    Delete(first, 4);

    Display(first);

    return 0;
}

