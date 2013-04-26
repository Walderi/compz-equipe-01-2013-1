#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#include "lista_email.h"

#define MAX_TAM_STR 80

#define true 1
#define false 0

/*
 * Questão 2 - Validador de emails. Lê lista com emails via parâmetros e gera saída em aqrquivo de texto.
 * Utilizar autômatos para executar verificação.
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
