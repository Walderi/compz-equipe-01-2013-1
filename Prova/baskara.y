%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token T_ALGORITMO T_FIMALGORIMO
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
%token T_ATRIBUI
%token T_DECLARAVAR
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

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER

%start Input

%%

Input:
	|Input Line
;

Line: 
	END
	| Expression END { printf("Result: %f\n", $1); }
;

Expression:

	NUMBER { $$=$1; }
	| Expression PLUS Expression { $$=$1+$3; }  
	| Expression MINUS Expression { $$=$1-$3; }  
	| Expression TIMES Expression { $$=$1*$3; }  
	| Expression DIVIDE Expression { $$=$1/$3; }  
	| MINUS Expression %prec NEG { $$=-$2; }  
	| Expression POWER Expression { $$=pow($1,$3); }  
	| LEFT Expression RIGHT { $$=$2; } 
;
Conteudo:
	T_VIRGULA Conteudo
;
Escreva:
	T_ABRE_PARENT T_STRING T_FECHA_PARENT 
;

Escreval:
	T_ABRE_PARENT T_STRING T_FECHA_PARENT
	|T_ABRE_PARENT T_STRING T_VIRGULA T_VARIAVEL T_DOISPONTOS T_INTEIRO T_FECHA_PARENT
	|T_ABRE_PARENT T_STRING T_VIRGULA T_VARIAVEL T_DOISPONTOS T_INTEIRO T_DOISPONTOS T_INTEIRO T_FECHA_PARENT 
;

Atribuicao:
	T_VARIAVEL T_ATRIBUICAO Expression
;

Leia:
	T_LEIA  T_ABRE_PARENT T_VARIAVEL T_FECHA_PARENT

%%

int yyerror(char *s) {
	printf("%s\n", s);
}

int main() {
	if(yyparse())
		fprintf(stderr, "Successful parsing.\n");
	else
		fprintf(stderr, "error found.\n");
}

