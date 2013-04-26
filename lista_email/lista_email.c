
#include "lista_email.h"


//-------------------------------------------------------------------------------------------------
// Verificar lógica, VERIFICAR todos os índices para evitar estouro do tamanho dos vetores e
// verificar se os limites estão corretos.
// Verificar se os tokens de finalização de string estão corretos e testar com emails falsos e
// verdadeiros.
//-------------------------------------------------------------------------------------------------

//se for vazio outra regra

/*
 * Esta função verifica uma cadeia de caracteres para a existência de um
 * endereço de email válido.
 */
int verifica_email(char *enderecoEmail) {
	int index=0;

	/*
	 * Se não tiver arroba e ponto é inválido
	 *
	 */
	int posArrobaIndex=0;
	int hasArroba=0;
	int hasDot=0;
	while(enderecoEmail[index] != '\0') {
		if (enderecoEmail[index] == '@') {
			hasArroba=1;
			posArrobaIndex=index+1;
			while(enderecoEmail[posArrobaIndex] !='\0') {
				if(enderecoEmail[posArrobaIndex] == '.') {
					hasDot=1;
					break;
				}//fecha if .
				posArrobaIndex++;
			}//fecha while
		}//fecha if @
		index++;
	}//fecha while

	if (hasArroba == 0 || hasDot == 0) {
		return(false);
	}

	/*
	 * Verificar se tamanho do email é menor que 'char'@'char'.'char''char''char'
	 * Ex.: a@b.com (Tamanho mínimo de 7 caracteres).
	 */
	if(strlen(enderecoEmail) < 7) {
		return(false);
	}
	//configurar para aceitar dominio.'char''char'

	/*
	 * Verifica se a primeira posição contém ponto, sublinhado ou arroba; e retorna erro
	 * caso verdadeiro.
	 */
	if (enderecoEmail[0] == '.' //caso ponto
		|| enderecoEmail[0] == '_' //ou sublinhado
				|| enderecoEmail[0] == '@') { //ou arroba
		return(false);
	}

	/*
	 * Verifica se a última posição contém ponto, sublinhado ou arroba e retorna erro
	 * caso verdadeiro.
	 */
	if (enderecoEmail[strlen(enderecoEmail)-1] == '.' //caso ponto
		|| enderecoEmail[strlen(enderecoEmail)-1] == '_' //ou sublinhado
			|| enderecoEmail[strlen(enderecoEmail)-1] == '@') { //ou arroba
		return(false);
	}

	/*
	 * Verifica se há intens no email, diferentes daqueles do alfabeto.
	 * Os caracteres aceitos são: Letras, Números, '@', '_' e '.'.
	 */
	while(enderecoEmail[index] != '\0') { //enquanto não for o fim do vetor de caracteres
		if(!isalpha(enderecoEmail[index]) //se não for alphanumérico
			&& !isdigit(enderecoEmail[index]) //se não for numeral
				&& enderecoEmail[index]!= '@' //se não for arroba
					&& enderecoEmail[index] != '.' //se não for ponto
						&& enderecoEmail[index] != '_') { //se não for sublinhado
			return (false);
		}//fecha if
		index++;
	}//fecha while

	index=0; //limpa index

	/*
	 * Verifica a ocorrência de sequência imediata de caracteres válidos, resultando em combinação inválida
	 * de caracteres que invalida o email.
	 */
	while(enderecoEmail[index] != '\0') {
		if(enderecoEmail[index] > 0
			&& enderecoEmail[index] < strlen(enderecoEmail)) {
			if(enderecoEmail[index] == '.'
				&& enderecoEmail[index+1] == '.') { //ponto ponto
				return(false);
			}

			if(enderecoEmail[index] == '_'
				&& enderecoEmail[index+1] == '_') {//sublinhado sublinhado
				return(false);
			}

			if(enderecoEmail[index] == '.'
				&& enderecoEmail[index+1] == '_') {//ponto sublinhado
				return(false);
			}

			if(enderecoEmail[index] == '_'
				&& enderecoEmail[index+1] == '.') {//sublinhado ponto
				return(false);
			}

			if(enderecoEmail[index] == '@'
				&& enderecoEmail[index+1] == '@') {//arroba arroba
				return(false);
			}

			if(enderecoEmail[index] == '@'
				&& enderecoEmail[index+1] == '.') {//arroba ponto
				return(false);
			}

			if(enderecoEmail[index] == '@'
				&& enderecoEmail[index+1] == '_') {//arroba sublinhado
				return(false);
			}

			if(enderecoEmail[index] == '_'
				&& enderecoEmail[index+1] == '@') {//sublinhado arroba
				return(false);
			}

			if(enderecoEmail[index] == '.'
				&& enderecoEmail[index+1] == '@') {//ponto arroba
				return(false);
			}
		}//fecha if
		index++;
	}//fecha while

	index=0; //limpa index
	int arrobaIndex=0;

	/*
	 * Verifica sé há apenas uma única arroba no email, caso contrário,
	 * o email é inválido.
	 */
	while(enderecoEmail[index] != '\0') {
		if (enderecoEmail[index] == '@') { //achou arroba
			arrobaIndex=index+1;
			while (enderecoEmail[arrobaIndex] != '\0') {
				if(enderecoEmail[arrobaIndex] == '@') { //achou segunda
					return(false);
				}//fecha if
				arrobaIndex++;
			}//fecha while
		}//fecha if
		index++;
	} //fecha while

	index=0; //limpa index
	arrobaIndex=0; //limpa arrobaIndex
	int primeiroPontoIndex=0;
	int segundoPontoIndex=0;

//tailan.cardoso.eng@gmail.com

	/*
	 * Verifica se após o arroba há apenas um ou dois pontos, caso contrário retorna erro.
	 */
	while (enderecoEmail[index] != '\0') {
		if (enderecoEmail[index] == '@') { //achou arroba
			arrobaIndex=index+1;
			while(enderecoEmail[arrobaIndex] != '\0') {
				if (enderecoEmail[arrobaIndex] == '.'){ //achou ponto seguindo arroba
					primeiroPontoIndex=arrobaIndex+1;
					while(enderecoEmail[primeiroPontoIndex] != '\0') {
						if(enderecoEmail[primeiroPontoIndex] == '.') { //achou segundo ponto seguindo arroba
							segundoPontoIndex = primeiroPontoIndex+1;
							while(enderecoEmail[segundoPontoIndex] != '\0') {
								if(enderecoEmail[segundoPontoIndex] == '.') { //achou terceiro ponto, inválido
									return(false);
								}//fecha if
								segundoPontoIndex++;
							}//fecha while
						}//fecha if
						primeiroPontoIndex++;
					}//fecha while
				}//fecha if
				arrobaIndex++;
			}//fecha while
		}//fecha if
		index++;
	}//fecha while

	index=0;
	arrobaIndex=0;
	/*
	 *	Verifica se após o arroba há apenas letras e pontos.
	 *	Caso contrário, retorna erro.
	 */
	while(enderecoEmail[index] != '\0') {
		if(enderecoEmail[index] == '@') { //achou arroba
			arrobaIndex=index+1;
			while(enderecoEmail[arrobaIndex] != '\0') {
				if(!isalpha(enderecoEmail[arrobaIndex])  //não é letra
					&& enderecoEmail[arrobaIndex] != '.' ) { //e não é ponto
					return(false); //falso
				}//fecha if
				arrobaIndex++;
			}//fecha while
		}//fecha if
		index++;
	}//fecha while

	index=0;
	int domainIndex=0;
	int comIndex=0;

	/* Verifica se após o ponto que finaliza o domínio, está contido a palavra "com" e, seguindo essa, se e somente se,
	 * existir um ponto, verifica se é seguido de 2 caracteres alfabéticos.
	 * Se após as duas últimas letras não for encontrado o fim, retorna inválido.
	 */
	while(enderecoEmail[index] != '\0') {
		if (enderecoEmail[index] == '@') { //se achou arroba
			domainIndex=index+1; //recebe o valor do índice seguinte
			while(enderecoEmail[domainIndex] != '\0') {
				if(enderecoEmail[domainIndex] == '.') { //achou ponto que finaliza domínio
					if(comIndex > 0) {
						break;
					}
					else {
						comIndex = domainIndex+1;
						if((enderecoEmail[comIndex] != '\0' //não é o fim
								&& enderecoEmail[comIndex] != 'c') //não é c
								|| enderecoEmail[comIndex] == '\0' ) { //ou é o fim
							return(false); //erro
						}//fecha if

						if((enderecoEmail[comIndex+1] != '\0' //não é o fim
								&& enderecoEmail[comIndex+1] != 'o') //não é o
								|| enderecoEmail[comIndex+1] == '\0') { //ou é o fim
							return(false); //erro
						}//fecha if

						if((enderecoEmail[comIndex+2] != '\0' //não é o fim
								&& enderecoEmail[comIndex+2] != 'm')//não é m
								|| enderecoEmail[comIndex+2] == '\0') { //ou é o fim
							return(false);//erro
						}//fecha if

						if (enderecoEmail[comIndex+3] != '\0'
								&& enderecoEmail[comIndex+3] == '.') { //se existir ponto dps de com

							if (enderecoEmail[comIndex+4] != '\0'
									&& !isalpha(enderecoEmail[comIndex+4])) { //se não for fim e não for letra
								return(false);//erro
							}//fecha if

							if (enderecoEmail[comIndex+5] != '\0'
									&& !isalpha(enderecoEmail[comIndex+5])) { //se não for fim e não for letra
								return(false);
							}//fecha if

							if (enderecoEmail[comIndex+6] != '\0') { //se não for fim após segunda letra de país
								return(false);
							}
						}//fecha if
					}//fecha else
				}//fecha if
				domainIndex++;
			}//fecha while
		}//fecha if
		index++;
	}//fecha while


	/*
	 * Se a procura de erros falhar, a função retorna 0 (verdadeiro).
	 * Isso caracteriza o email como válido.
	 */
	return (true);

}




