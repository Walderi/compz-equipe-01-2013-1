/*
 * particoes.c
 *
 */

#include "particoes.h"
#include <stdio.h>

//Método para imprimir cada partição p do conjunto de n elementos.
void imprime_particoes( int *p, int n, int cont ) {
	//Verifica o número de conjuntos na partição
    int numConjuntos = 1;
    int i;
    for (i = 0; i < n; ++i)
        if ( p[i] > numConjuntos )
        	numConjuntos = p[i];

    //Looping que imprime os conjuntos da partição
    int c;
    printf( "%d - ", cont );
    for ( c = numConjuntos; c >= 1; --c ) {
        printf("{ ");
        for ( i = 0; i < n; ++i ) {
        	//Verifica caso o p[i] for igual a c, então i+1 entrará nesse conjunto da particao
            if ( p[i] == c ) {
                printf( "%d ", i + 1 );
            }
        }
        printf( "} ");
    }
    printf( "\n" );
}

//Método que valida se ainda existe alguma partição válida para imprimir.
int existe_particao_valida(int *p, int n) {
	//Volta para o primeiro elemento para fazer as comparações
	int i = 0;
	++p[i];
	//Seta o valor máximo pra 1;
	p[n] = 1;

	//Percorre o vetor a partir do segundo elemento para ver se tem algum valor maior que 1 para valor máximo
	int j;
	for (j = i + 1; j < n - 1; ++j) {
		if ( p[j] > p[n] )
			p[n] = p[j];
	}

	//Verifica se o 1o elemento é maior do que o valor de n, caso seja, significa que as partições acabaram e retorna false.
	if ( p[0] == n + 1 )
		return 0;

	//Verifica se o p[i] é maior do que qualquer número após ele mais 1. Compara sempre com o valor máximo p[n].
	while ((p[i] > p[n] + 1)) {
		//Se for, seta o valor pra 1 e passa pro próximo elemento da lista e incrementa 1.
		p[i] = 1;
		++i;
		++p[i];
		p[n] = 1;
		//Procura o valor máximo nos elementos após esse novo elemento para fazer uma nova comparação.
		int j;
		for (j = i + 1; j < n - 1; ++j) {
			if ( p[j] > p[n] )
				p[n] = p[j];
		}
	}

	//Retorna um true dizendo que há mais partições.
	return 1;
}

