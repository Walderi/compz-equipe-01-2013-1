/*
 =========================================================================================
 Regras:
 	 Regra 1: Precisa haver '@' && '.' no email.
 	 Regra 2: Tamanho do email >= que 7 caracteres (ex.: a@b.com
 	 Regra 3: Email não pode ter '.' ou '@' ou '_' na primeira posição
 	 Regra 4: Email não pode ter '.' ou '@' ou '_' na última posição
 	 Regra 5: Email não pode ter síbolos diferentes de letras, números, '.' , '@' e '_'.
 	 Regra 6: No email não pode haver sequencia imediata dos símbolos '.' ou '@' ou '_'.
 	 Regra 7: Email só pode ter um símbolo do tipo '@'.
 	 Regra 8: Após '@' só pode haver no máximo 2 pontos.
 	 Regra 9: Após '@' só pode haver letras ou pontos.
 	 Regra 10: Após o '.' que sucede a ocorrência de '@', finalizando o domínio,
 	  	  	   a sequencia tem que ser obrigatoriamente 'c' 'o' 'm'. Caso haja um segundo
 	  	  	   '.', tem que ser seguide de obrigatoriamente apenas 2 letras.
 =========================================================================================
 */

#include "lista_email.h"

#define true 1
#define false 0

int verifica_email(char *enderecoEmail) {
	int index=0;

	//início Regra 1
	int posArrobaIndex=0;
	int hasArroba=0;
	int hasDot=0;
	while(enderecoEmail[index] != '\0') { //não é fim
		if (enderecoEmail[index] == '@') { //achou arroba
			hasArroba=true; //flag hasArroba sobe
			posArrobaIndex=index+1; //pega próxima posição
			while(enderecoEmail[posArrobaIndex] !='\0') { //não é fim
				if(enderecoEmail[posArrobaIndex] == '.') { //se for ponto
					hasDot=true; //flag hasDot sobe
					break; //sai com as flags
				}//fecha if .
				posArrobaIndex++;
			}//fecha while
		}//fecha if @
		index++;
	}//fecha while

	if (hasArroba == false || hasDot == false) { //não tem '.' ou '@'
		return(false);
	}
	//fim Regra 1

	//início Regra 2
	if(strlen(enderecoEmail) < 7) {
		return(false);
	}
	//fim Regra 2

	//início Regra 3
	if (enderecoEmail[0] == '.' //caso ponto
		|| enderecoEmail[0] == '_' //ou sublinhado
				|| enderecoEmail[0] == '@') { //ou arroba
		return(false);
	}
	//fim Regra 3

	//início Regra 4
	if (enderecoEmail[strlen(enderecoEmail)-1] == '.' //caso ponto
		|| enderecoEmail[strlen(enderecoEmail)-1] == '_' //ou sublinhado
			|| enderecoEmail[strlen(enderecoEmail)-1] == '@') { //ou arroba
		return(false);
	}
	//fim Regra 4

	//início Regra 5
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
	//fim Regra 5

	//início Regra 6
	index=0; //limpa index
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
	//fim Regra 6

	//início Regra 7
	index=0; //limpa index
	int arrobaIndex=0;
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
	//fim Regra 7



	//início Regra 8
	index=0; //limpa index
	arrobaIndex=0; //limpa arrobaIndex
	int primeiroPontoIndex=0;
	int segundoPontoIndex=0;
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
	//fim Regra 8

	//início Regra 9
	index=0;
	arrobaIndex=0;
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
	//fim Regra 9

	//início Regra 10
	index=0;
	int domainIndex=0;
	int comIndex=0;
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
	//fim Regra 10

	//se chegar nesse ponto, o email é válido.
	return (true);
}




