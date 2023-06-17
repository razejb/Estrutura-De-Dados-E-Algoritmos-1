        #include "Stack.h"
        #include "fatal.h"
        #include <stdlib.h>
        #include <stdio.h>


        /*
        Implemente o TAD Stack com arrays. O ficheiro "stackar.h" contém os protótipos das funções a
        implementar. O ficheiro " stackar.c" já contém a definição de constantes, do tipo composto
        StackRecord e a implementação das funções CreateStack e DisposeStack.

        1. teste a sua implementação de Satcks, criando stacks,adicionando e removendo elementos, e
        listando o seu conteúdo.

        2. Elabore um programa em C, que fazendo uso da Stack implementada,verifique se uma expressão dada,
        está equilibrada de parêntesis. Por uma questão de simplicidade use o ficheiro dado "balanco.c" e
        complete-o por forma a realizar a verificação pedida.
        */

        /*
        Ver/Consultar (TOP)
        Retirar(POP)
        Adicionar(PUSH)
        */

        #define EmptyTOS ( -1 )
        #define MinStackSize ( 5 )


        struct StackRecord
        {
            int Capacity;
            int TopOfStack;
            ElementType *Array;
        };



        Stack CreateStack( int MaxElements )
        {

            Stack S;

            if( MaxElements < MinStackSize )
                Error( "Stack size is too small" );

            S = ( Stack )malloc( sizeof( StackRecord ) );

                        if( S == NULL )
                FatalError( "Out of space!!!" );

            S->Array = (int *)malloc( sizeof( ElementType ) * MaxElements );
            if( S->Array == NULL )
                FatalError( "Out of space!!!" );

            S->Capacity = MaxElements;
            MakeEmpty( S );

            return S;
        }



        void DisposeStack( Stack S )
        {
            if( S != NULL )
            {
                free( S->Array );
                free( S );
            }
        }

        //Verifica se a pilha está ou não vazia
        int IsEmpty( Stack S )
        {
            if(S->TopOfStack == EmptyTOS)
                printf("Está vazia") ;

                return 0;

        }

        //Verifica se a pilha está ou não cheia
        int IsFull( Stack S )
        {
            if(S->TopOfStack == MinStackSize)
                printf("Está cheia") ;

            return 0;
        }

        //Ao igualar o Topo da Stack a -1, torna a stack vazia
        void MakeEmpty( Stack S )
        {
            if(S->TopOfStack == EmptyTOS)
            {
                printf("Está vazia");
                exit(EXIT_FAILURE) ;
            }
            S->TopOfStack == EmptyTOS ;

        }

        //Adiciona ao topo da pilha o valor x
        void Push( ElementType X, Stack S )
        {

            S->Array[++S->TopOfStack] = X ;
            printf("%d\n", X) ;
        }

        //Irá consultar o topo da pilha
        ElementType Top( Stack S )
        {

            return S->Array[S->TopOfStack] ;

        }

        //Irá retirar da pilha o último valor adicionado
        ElementType Pop( Stack S )
        {
         return S->Array[S->TopOfStack--];
        }

        int main()
        {
          Stack S = CreateStack(10) ;
          int i;

            Push(20, S) ;
            Push(10, S) ;
            Push(05, S) ;
            Push(15, S) ;

            puts("") ;

            printf("Top: %d\n", Top(S)) ;


            printf("Pop: %d\n", Pop(S)) ;


            printf("Top: %d\n\n", Top(S)) ;


            printf("Pop: %d\n", Pop(S)) ;


            printf("Top: %d\n", Top(S)) ;

        }
