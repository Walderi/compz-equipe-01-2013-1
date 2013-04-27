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

int main(int argc, char *argv[]) {
	if (argc != 2) { //argumentos incorretos
		printf("Uso: %s nomedoarquivo\n", argv[0]); //mensagem de erro/ajuda
	}
	else {

		FILE *file;

		file = fopen(argv[1],"r"); //tenta abrir arquivo

		if (file == NULL) //se falha
		{
			printf( "Não conseguiu abrir arquivo\n" );
			return(false);
		}
		else //caso consiga
		{
			//Variáveis de instância
			char email[MAX_TAM_STR];

			while(fscanf(file,"%s",email) != EOF) { //enquanto não for o fim do arquivo
				if(verifica_email(email)) {
					printf("%s %s\n", email, "Válido");
				}
				else {
					printf("%s %s\n", email, "Inválido");
				}
			}

			fclose(file); //fecha arquivo
		}

	}

	return(true);
}
