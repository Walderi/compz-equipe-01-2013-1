/*
 * particoes.h
 *
 */

#ifndef PARTICOES_H_
#define PARTICOES_H_

//Método para imprimir cada partição p do conjunto de n elementos.
void imprime_particoes( int *p, int n, int cont );
//Método que valida se ainda existe alguma partição válida para imprimir.
int existe_particao_valida( int *p, int n );

#endif /* PARTICOES_H_ */

