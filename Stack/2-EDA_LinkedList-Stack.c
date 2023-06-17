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
    int data;           // valor armazenado no nó
    struct Node *next;  // ponteiro para o próximo nó
} *top = NULL;

// Função para empilhar (inserir) um elemento no topo da pilha
void push(int x)
{
    struct Node *t;

    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("A pilha está cheia\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Função para desempilhar (remover) um elemento do topo da pilha e retornar o seu valor
int pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("A pilha está vazia\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Função para exibir os elementos da pilha
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(13);
    push(17);
    push(22);

    printf("%d\n", pop());

    Display();

    return 0;
}

