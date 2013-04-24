#include <stdio.h>
#include <string.h>

#include "lista_email.c"

#define MAX_TAM_STR 80

/*
Questão 2 - Validador de emails. Lê lista com emails via parâmetros e gera saída em aqrquivo de texto.
Utilizar autômatos para executar verificação.
*/

void main() {
	//Variáveis de instância
	char email[MAX_TAM_STR];

	FILE *emailList, *validationList;
	char *mode = 'r';
	char outputFilename[]="validation.list";

	emailList = fopen("email.list", mode);

	if (emailList == NULL) {
		fprintf(stderr, "Não pode abrir arquivo de entrada email.list!\n");
		return(1);
	}

	validationList = fopen(outputFilename, "w");

	if (validationList == NULL) {
		fprintf(stderr, "Não pode abrir/criar arquivo de saída %s!\n", outputFilename);
		return(1);
	}

	while(fscanf(emailList,"%s",email) != EOF) {
		if(verifica_email(email)) {
			fprintf(validationList, "%s %s\n", email, "Válido");
		}
		else {
			fprintf(validationList, "%s %s\n", email, "Inválido");
		}
	}

 	fclose(emailList);
	fclose(validationList);

	return(0);
}
