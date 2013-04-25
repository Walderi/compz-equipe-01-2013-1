#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "lista_email.h"

//just changing

#define MAX_TAMNHO_STRING 80

/*
Esta função verifica uma cadeia de caracteres para a existência de um
endereço de email válido.
*/
int verifica_email(char *enderecoEmail[]) {
	//Verifica se há caracteres inválidos. Caso haja, retorna inválido automáticamente.
	int index=0;

	/*Verificar se tamanho do email é menor que 'char'@'char'.'char''char''char'
	 * Ex.: a@b.com = tamanho
	 */
	if(strlen(enderecoEmail) < 7) {
		return(1);
	}

	/*verifica se primeira posição contêm ponto, sublinhado ou arroba e retorna inválido
	 *caso verdadeiro.
	 */
	if (enderecoEmail[0] == '.' || enderecoEmail[0] == '_' || enderecoEmail[0] == '@') {
		return(1);
	}//fecha if

	/*verifica se ultima posição contêm ponto, sublinhado ou arroba e retorna inválido
	 *caso verdadeiro.
	 */
	if (enderecoEmail[strlen(enderecoEmail)-1] == '.' || enderecoEmail[strlen(enderecoEmail)-1] == '_' || enderecoEmail[strlen(enderecoEmail)-1] == '@') {
		return(1);
	}//fecha if


	while(enderecoEmail[index] != NULL) { //enquanto não for o fim do vetor de caracteres
		if(!isalpha(enderecoEmail[index]) //se não for alphanumérico
			&& !isnumber(enderecoEmail[index]) //se não for numeral
				&& enderecoEmail[index]!= '@' //se não for arroba
					&& enderecoEmail[index] != '.' //se não for ponto
						&& enderecoEmail[index] != '_') { //se não for sublinhado
			return (1);
		}//fecha if
		index++;
	}//fecha while

	index=0;
	/*
	 *Verifica a ocorrência de sequência imediata de caracteres válidos, resultando em combinação inválida
	 *de caracteres e invalidando o email.
	 *
	 */
	while(enderecoEmail[index] != NULL) {
		if(enderecoEmail[index] > 0 && enderecoEmail[index] < strlen(enderecoEmail)) {
			if(enderecoEmail[index] == '.' && enderecoEmail[index+1] == '.') { //ponto ponto
				return(1);
			}

			if(enderecoEmail[index] == '_' && enderecoEmail[index+1] == '_') {//sublinhado sublinhado
				return(1);
			}

			if(enderecoEmail[index] == '.' && enderecoEmail[index+1] == '_') {//ponto sublinhado
				return(1);
			}

			if(enderecoEmail[index] == '_' && enderecoEmail[index+1] == '.') {//sublinhado ponto
				return(1);
			}

			if(enderecoEmail[index] == '@' && enderecoEmail[index+1] == '@') {//arroba arroba
				return(1);
			}

			if(enderecoEmail[index] == '@' && enderecoEmail[index+1] == '.') {//arroba ponto
				return(1);
			}

			if(enderecoEmail[index] == '@' && enderecoEmail[index+1] == '_') {//arroba sublinhado
				return(1);
			}

			if(enderecoEmail[index] == '_' && enderecoEmail[index+1] == '@') {//sublinhado arroba
				return(1);
			}

			if(enderecoEmail[index] == '.' && enderecoEmail[index+1] == '@') {//ponto arroba
				return(1);
			}
		}//fecha if
		index++;
	}//fecha while



	//verificar única arroba
	index=0;
	int arrobaIndex=0;

	while(enderecoEmail[index] != NULL) {
		if (enderecoEmail[index] == '@') {
			arrobaIndex=index;
			while (enderecoEmail[arrobaIndex] != NULL) {
				if(enderecoEmail[arrobaIndex] == '@') {
					return(1);
				}//fecha if
				arrobaIndex++;
			}//fecha while
		}//fecha if
		index++;
	} //fecha while

//----------------------------------------------

	index=0;
	int domainIndex=0;
	int comIndex=0;
	int countryIndex=0;

	while(enderecoEmail[index] != NULL) {
		if (enderecoEmail[index] == '@') { //se achou arroba
			domainIndex=index; //recebe o valor do índice atual
		}

		if (enderecoEmail[index] == '.')
			while(enderecoEmail[domainIndex] != '.') { //enquanto nÃo entrar no espaço ".com"

				if(enderecoEmail[domainIndex] == '_') { //se o sublinhado estiver contido no espaço do domínio
					return(1);//falha
				}//fecha if

				domainIndex++;
			}//fecha while

			int comIndex=domainIndex;

				if(enderecoEmail[comIndex])


			}


		}

		index++;
	}

	return (0);

}




