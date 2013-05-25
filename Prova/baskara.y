%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
%}

%token T_ALGORITMO T_FIMALGORITMO
%token T_INICIO T_ESCREVAL T_ESCREVA
%token T_STRING
%token T_COMENTARIO
%token T_ABRE_PARENT T_FECHA_PARENT
%token T_VIRGULA
%token T_AND T_OR
%token T_VAR
%token T_INTEIRO T_REAL
%token T_PI
%token T_LEIA
%token T_INTERROMPA
%token T_SENAO T_ENTAO T_FIMSE T_SE
%token T_ESCOLHA T_CASO T_OUTROCASO T_FIMESCOLHA
%token T_NUMINTEIRO
%token T_NUMREAL
%token T_ATRIBUI
%token T_DECLARAVAR
%token T_ESPACO

%token T_SOMA T_DIVISAO T_SUBTRACAO T_MULT T_POTENCIA
%token T_DIFERENTE T_MENORQUE T_MENORIGUALQUE T_MAIORQUE T_MAIORIGUALQUE T_IGUAL
%token T_REPITA T_ATE
%token T_TIPO_LOGICO T_LOGICO_VERDADEIRO T_LOGICO_FALSO
%token T_PROCEDIMENTO
%token T_DIVISAOINTEIRA
%token T_RESTO
%token T_VARIAVEL
%token T_RAIZQ
%token T_DOISPONTOS

%left T_SOMA T_SUBTRACAO
%left T_MULT T_DIVISAO
%right T_POTENCIA T_RAIZQ

%start Input

%%

Input:
	
	| Input Bloco
;

Bloco: 
	T_ALGORITMO nome codigo T_FIMALGORITMO	
;

nome:
    T_STRING
;

codigo:
	declaravariavel T_INICIO rotinas 
	| comentarios codigo	
;

declaravariavel:
	| T_VAR
	| T_VAR variaveis T_DOISPONTOS tipo
;

variaveis:
	variavel
	| variavel T_VIRGULA variaveis 
;

variavel:
	T_VARIAVEL
;

tipo:
	T_INTEIRO
	| T_REAL
;

rotinas:
	 comentarios
	| rotina
	| comentarios rotinas 
;

rotina:
	| T_STRING rotina
	| Escreval rotina
	| Escreva rotina
	| Leia rotina
	| Atribuicao rotina
;	

comentarios:
	comentario
	| comentario comentarios
;

comentario:
	T_COMENTARIO
;

Atribuicao:
	 variavel T_ATRIBUI T_STRING
	| variavel T_ATRIBUI Expression
;

Expression:
	number 
	| variavel 
	| Expression T_SOMA Expression  
	| Expression T_SUBTRACAO Expression   
	| Expression T_MULT Expression   
	| Expression T_DIVISAO Expression   
	| T_SUBTRACAO Expression   
	| Expression T_POTENCIA Expression   
	| T_ABRE_PARENT Expression T_FECHA_PARENT  
    	| raiz 
;

raiz: 
	T_RAIZQ T_ABRE_PARENT Expression T_FECHA_PARENT
;

number:
	T_NUMINTEIRO
	| T_NUMREAL
;

Conteudo:
	| T_STRING
	| Expression
	| Conteudo T_VIRGULA Expression T_DOISPONTOS T_NUMINTEIRO
	| Conteudo T_VIRGULA Expression T_DOISPONTOS T_NUMINTEIRO T_DOISPONTOS T_NUMINTEIRO
;
ParametroFUNC:
	T_ABRE_PARENT Conteudo T_FECHA_PARENT
	
;

Escreva:
	T_ESCREVA ParametroFUNC
;
Escreval:
	T_ESCREVAL ParametroFUNC	
;

Leia:
	T_LEIA T_ABRE_PARENT T_VARIAVEL T_FECHA_PARENT
;

%%

extern int 	yylineno;
extern char 	*yytext;

int yyerror(char *s) {
	printf("Erro %s na Linha %d com o Token nao esperado %s\n", s, yylineno, yytext);
}

int main(int ac, char **av) {
	extern FILE *yyin;

	if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
		perror(av[1]);
		exit(1);
	}

	if(!yyparse())
		printf("Tudo foi OK!!\n");
	else
		printf("Algoritmo com erro.\n");
}
