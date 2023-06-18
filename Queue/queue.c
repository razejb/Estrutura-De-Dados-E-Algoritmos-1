#include <stdlib.h>
#include "queue.h"
#include "fatal_EDA.h"

#define MinQueueSize (5)

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};

/* FUNCOES AUXILIARES */
/* numero de elementos na fila */
int size(Queue Q)
{
    return (Q->Capacity - Q->Front + Q->Rear) % Q->Capacity;
}

/* indice do proximo elemento  */
/*
O cálculo do próximo índice é feito utilizando a operação de módulo %,
que retorna o resto da divisão entre i+1 e a capacidade da fila Q.
Dessa forma, o próximo índice é sempre um número entre 0 e Q->Capacity - 1, incluindo ambos.
*/
int successor(int i, Queue Q)
{
    return (i + 1) % Q->Capacity;
}

/* FUNCOES DE MANIPULACAO DE QUEUES */
Queue CreateQueue(int MaxElements)
{
    Queue Q;

    if (MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of space!!!");

    Q->Capacity = MaxElements + 1;
    MakeEmptyQueue(Q);

    return Q;
}

// Liberta a memória
void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

/*
A verificação da função 'IsEmptyQueue' é feita comparando os índices Front e Rear da fila.
Quando a fila está vazia, ambos os índices apontam para o mesmo local (inicialmente, o
índice Front é definido como 0 e o Rear é definido como 0 também).

Se houver elementos na fila, Front e Rear apontarão para diferentes posições na fila.
*/
int IsEmptyQueue(Queue Q)
{
    return Q->Front == Q->Rear;
}

int IsFullQueue(Queue Q)
{
    return successor(Q->Rear, Q) == Q->Front;
}

/*
A função 'MakeEmptyQueue' define o índice do início da fila (Front) para 1 e
o índice do final da fila (Rear) para 0, indicando que a
fila está vazia.
*/
void MakeEmptyQueue(Queue Q)
{
    Q->Front = 1;
    Q->Rear = 0;
}

/*
Essa função insere um elemento na fila (queue). Ela verifica se a fila está cheia (usando a função IsFullQueue),
e se não estiver, adiciona o elemento X ao final da fila, atualizando o valor do índice Rear para indicar o
novo último elemento. Essa atualização é feita usando a função successor para encontrar o
próximo índice disponível na fila circular.
*/
void Enqueue(ElementType X, Queue Q)
{
    if (IsFullQueue(Q))
        Error("Queue is full");
    else
    {
        //0  1  2  3
		//if       X
		//         X

		//0  1  2  3
		//i  f     X
		//o        X

		//0  1  2  3
		//i     f  X
		//o  a     X

		//0  1  2  3
		//i        f
		//o  a  c  X

		/*4 + 3 - 0 = 7
		7%4 = 3 

		3 == tamanho-1
		FULL

		d*/

		//0  1  2  3
		//   i     f
		//T  a  c  X

		/*4 + 3 - 1 = 6
		6%4 = 2

		2 != tamanho-1

		//0  1  2  3
		//f  i     X
		//T  a  c  z

		4 + 0 - 1 = 3
		3%4 = 3

		3 == tamanho-1

		d

		//0  1  2  3
		//f     i  X
		//T  T  c  z

		4 + 1 - 0 = 4
		4%4 = 0


		//0  1  2  3
		//   f  i  X
		//y  T  c  z

		4 + 1 - 2 = 3
		3%4 = 3

		3==3

		d
		//0  1  2  3
		//   f     i
		//y  T  T  z

		d
		//0  1  2  3
		//i  f     
		//y  T  T  T
	*/
        Q->Rear = successor(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

// A função Front retorna o elemento que está no início da fila (ou seja, o elemento que foi enfileirado há mais tempo).
ElementType Front(Queue Q)
{
    if (IsEmptyQueue(Q))
        Error("Queue is empty");
    else
        return Q->Array[Q->Front];
}

// O Dequeue é uma operação que retira o elemento mais antigo adicionado à fila (o primeiro elemento a ter sido adicionado).
ElementType Dequeue(Queue Q)
{
    ElementType Temp;

    if (IsEmptyQueue(Q))
        Error("Queue is empty");
    else
    {
        Temp = Q->Array[Q->Front];
        Q->Front = successor(Q->Front, Q);
    }

    return Temp;
}
