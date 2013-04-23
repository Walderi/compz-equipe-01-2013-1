/*
 * Particoes.h
 *
 */

#ifndef PARTICOES_H_
#define PARTICOES_H_

//Método para imprimir cada partição p do conjunto de n elementos.
void imprimeParticoes( int *p, int n );
//Método que valida se ainda existe alguma partição válida para imprimir.
int existeParticaoValida( int *p, int *m, int n );

#endif /* PARTICOES_H_ */

