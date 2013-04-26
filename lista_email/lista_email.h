#ifndef LISTA_EMAIL_H_INCLUDED
#define LISTA_EMAIL_H_INCLUDED

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_TAM_STR 80

/*
 * Função que recebe um sequencia de caracteres e analisa para identificar endereço
 * de email válido.
 */
int verifica_email(char *enderecoEmail);

#endif //LISTA_EMAIL_H_INCLUDED
