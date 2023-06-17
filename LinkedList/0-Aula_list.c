#include "list.h"
#include <stdlib.h>
#include "fatal.h"

/* Definição da estrutura do nó */
struct Node
{
    ElementType Element;
    Position    Next;
};

/* Cria uma lista vazia */
List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    L = (struct Node *)malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Sem memória disponível!");
    L->Next = NULL;
    return L;
}

/* Verifica se a lista está vazia */
int IsEmpty(List L)
{
    return L->Next == NULL;
}

/* Verifica se P é a última posição na lista L */
bool IsLast(Position P, List L)
{
    if (P == NULL) {
        return 0; // P não existe na lista
    }
    return P->Next == NULL;
}


/* Procura a posição de X na lista L; retorna NULL se não encontrado */
Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

/* Remove o elemento X da lista L */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* Retorna a posição anterior a X na lista L */
Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}

/* Insere o elemento X após a posição P na lista L */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Sem memória disponível!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* Remove todos os elementos da lista L */
void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

/* Retorna o ponteiro para o cabeçalho da lista L */
Position Header(List L)
{
    return L;
}

/* Retorna a primeira posição da lista L */
Position First(List L)
{
    return L->Next;
}

/* Retorna a próxima posição após a posição P */
Position Advance(Position P)
{
    return P->Next;
}

/* Retorna o elemento armazenado na posição P */
ElementType Retrieve(Position P)
{
    return P->Element;
}


/*A variável TmpCell é usada como um nó temporário para auxiliar nas 
operações de inserção e remoção de elementos na lista ligada. 
Ela serve como um ponteiro para o nó que será inserido ou removido da lista.*/
