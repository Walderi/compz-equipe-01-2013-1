/*
 * Particoes.h
 *
 */

#include "Particoes.h"
#include <stdio.h>

//Método para imprimir cada partição p do conjunto de n elementos.
void imprimeParticoes( int *p, int n ) {
	//Verifica o número de conjuntos na partição
    int numConjuntos = 1;
    int i;
    for (i = 0; i < n; ++i)
        if ( p[i] > numConjuntos )
        	numConjuntos = p[i];

    //Looping que imprime os conjuntos da partição
    int c;
    for ( c = numConjuntos; c >= 1; --c ) {
        printf("{");
        for ( i = 0; i < n; ++i ) {
        	//Verifica caso o p[i] for igual a c, então i+1 entrará nesse conjunto da particao
            if ( p[i] == c ) {
                printf( "%d, ", i + 1 );
            }
        }
        printf("} ");
    }
    printf( "\n" );
}

//Método que valida se ainda existe alguma partição válida para imprimir.
int existeParticaoValida( int *p, int *m, int n ) {
//Ainda sem implementação.
	return 0;
}

