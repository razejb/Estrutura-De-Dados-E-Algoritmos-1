#include "tree.h"  // Inclui os cabeçalhos necessários
#include <stdlib.h>
#include "fatal.h"

struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};

/* Esta função esvazia a árvore */
SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);  // Esvazia a subárvore esquerda
        MakeEmpty(T->Right);  // Esvazia a subárvore direita
        free(T);  // Libera a memória do nó atual
    }
    return NULL;
}

/* Esta função procura um elemento na árvore */
Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);  // Procura na subárvore esquerda
    else if (X > T->Element)
        return Find(X, T->Right);  // Procura na subárvore direita
    else
        return T;  // O elemento foi encontrado
}

/* Esta função encontra o menor elemento na árvore */
Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;  // O nó atual é o menor
    else
        return FindMin(T->Left);  // Procura na subárvore esquerda
}

/* Esta função encontra o maior elemento na árvore */
Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;  // Percorre pela subárvore direita até encontrar o maior elemento

    return T;
}

/* Esta função insere um elemento na árvore */
SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        /* Cria e retorna uma árvore com um único nó */
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);  // Insere na subárvore esquerda
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);  // Insere na subárvore direita
    /* Caso contrário, o elemento já está na árvore; não faz nada */

    return T;
}

/* Esta função exclui um elemento da árvore */
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;

    if (T == NULL)
        Error("Element not found");
    else if (X < T->Element)  /* Vá para a esquerda */
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)  /* Vá para a direita */
        T->Right = Delete(X, T->Right);
    else  /* Elemento encontrado para ser excluído */
    {
        if (T->Left && T->Right)  /* Dois filhos */
        {
            /* Substitui pelo menor elemento na subárvore direita */
            TmpCell = FindMin(T->Right);
            T->Element = TmpCell->Element;
            T->Right = Delete(T->Element, T->Right);
        }
        else  /* Um ou nenhum filho */
        {
            TmpCell = T;
            if (T->Left == NULL)  /* Também lida com 0 filhos */
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            free(TmpCell);
        }
    }

    return T;
}

/* Esta função recupera o valor de um nó */
ElementType Retrieve(Position P)
{
    return P->Element;
}
