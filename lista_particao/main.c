#include "particoes.h"
#define MAXTAM 11

int main(int argc, char *argv[]) {
	int p[MAXTAM];
	int n = 6;
	int cont = 1;

	//Seta todos os elementos do vetor como 1 para imprimir a partição de um só subconjunto
	int i;
	for (i = 0; i <= n; ++i) {
		p[i] = 1;
	}

	imprimeParticoes( p, n, cont );
	++cont;

	//Procura nova partição válida e, caso tenha, imprime.
	while ( existeParticaoValida( p, n ) ) {
		imprimeParticoes( p, n, cont );
		++cont;
	}

	//Fim do programa
	return 0;
}

