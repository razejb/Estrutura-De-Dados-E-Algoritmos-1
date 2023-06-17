/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;  
} *first = NULL;

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
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i] ;
        t->next=NULL ;
        last->next = t;
        last = t;
    }
}

// Pesquisa linear na lista ligada (iterativa)
struct Node * LinearSearch(struct Node *p, int key)
{
    struct Node *q;

    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next=first;
            first=p;

            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Pesquisa linear na lista ligada (recursiva)
struct Node * RLinearSearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    
    return RLinearSearch(p->next, key);
}

int main() 
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    
    temp = LinearSearch(first, 25);
    if(temp)
        printf("Chave encontrada %d", temp->data);
    else
        printf("Erro");

    return 0;
}
