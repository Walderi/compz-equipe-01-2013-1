/*
 ============================================================================
 Name        : main.c
 Author      : Equipe 01 - Compiladores - S1 - 2013
 Version     : 0.5b
 Copyright   : Código pode ser utilizado e compartilhado abertamente.
 Description : Lê cadeia de caracteres e tenta identificar email válido, de
  	  	  	   acordo com regras pré-estabelecidas.
 ============================================================================
 */

#include "lista_email.h"

#define true 1
#define false 0

/*
 * Questão 2 -
 */

int main(void) {
	//Variáveis de instância
	char email[MAX_TAM_STR];

	while(scanf("%s",email) != EOF) {
			if(verifica_email(email)) {
				printf("%s %s\n", email, "Válido");
			}
			else {
				printf("%s %s\n", email, "Inválido");
			}
		}

	return(true);
}
