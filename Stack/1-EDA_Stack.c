/*--------------------------------------------------------------
|                                                              |
|                     Made by: João Santos                     |
|                                                              |
--------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Stack (pilha)
struct Stack
{
    int size;   // tamanho da pilha
    int top;    // topo da pilha
    int *S;     // array para armazenar os elementos da pilha
};

// Função para criar a pilha
void create(struct Stack *st)
{
    printf("Introduza o tamanho da pilha: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

// Função para exibir os elementos da pilha
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

// Função para empilhar (inserir) um elemento
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Overflow da pilha\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// Função para desempilhar (remover) um elemento e retornar o seu valor
int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Underflow da pilha\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

// Função para retornar o valor de um elemento em uma determinada posição
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Índice inválido\n");
    else
        x = st.S[st.top - index + 1];

    return x;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

// Função para verificar se a pilha está cheia
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

// Função para retornar o valor do elemento no topo da pilha
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];

    return -1;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 13);
    push(&st, 17);
    push(&st, 22);

    printf("%d\n", peek(st, 2));

    Display(st);

    puts("");

    printf("Elemento removido do topo da pilha: %d\n", pop(&st));

    Display(st);

    return 0;
}

}
