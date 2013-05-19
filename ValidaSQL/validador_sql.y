%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token SELECT
%token FROM
%token WHERE
%token AS
%token ALL

%token AND
%token OR
%token XOR
%token NOT

%token GROUP
%token ORDER
%token BY
%token LIKE
%token LIMIT

%token PALAVRA
%token TABELA

%token DIGITO
%token INTEIRO
%token REAL
%token STRING

%token MAIS
%token MENOS
%token DIVIDE
%token ASTERISCO

%token ABRE_PAREN
%token FECHA_PAREN

%token IGUAL
%token MAIOR_QUE
%token MENOR_QUE
%token MAIOR_IGUAL_QUE
%token MENOR_IGUAL_QUE
%token ASPAS;
%token VIRGULA;
%token FIM;
%token ASC;
%token DESC;

/*precedence*/

%left AND OR XOR NOT
%left MAIS MENOS
%left IGUAL MAIOR_QUE MENOR_QUE MAIOR_IGUAL_QUE MENOR_IGUAL_QUE
%left DIVIDE ASTERISCO

%start input

%%

input:
		sql FIM	
	|	input sql FIM
;

sql:	
	manipulacao
;

manipulacao:	
	|	expressao_select
;

expressao_select:	
		SELECT ALL FROM expressao_tabela
;

where:
		comando_where
;



expressao_tabela:
		from where group_by
	;

from:
		FROM expressao_tabela_composta
	;

expressao_tabela_composta:
		referencia_tabela
	|	expressao_tabela_composta VIRGULA referencia_tabela
	;

referencia_tabela:
		table	
	;

comando_where:
		WHERE procura_condicional
	;

group_by:
		GROUP BY referencia_coluna_composta
	;

referencia_coluna_composta:	
		referencia_coluna
	|	referencia_coluna_composta VIRGULA referencia_coluna
;

referencia_coluna:
		PALAVRA
	|	TABELA
	|	PALAVRA '.' PALAVRA '.' PALAVRA 
	;

procura_condicional:
		procura_condicional OR procura_condicional
	|	procura_condicional AND procura_condicional
	|	NOT procura_condicional
	|	ABRE_PAREN procura_condicional FECHA_PAREN
	|	predicado
	;

predicado:
		comparador_predicado
	|	like_predicado
	;

comparador_predicado:
		elemento_escalar MAIOR_QUE elemento_escalar
	|	elemento_escalar MENOR_QUE elemento_escalar
	|	elemento_escalar MAIOR_IGUAL_QUE elemento_escalar
	|	elemento_escalar MENOR_IGUAL_QUE elemento_escalar
	|	elemento_escalar IGUAL elemento_escalar
	|	elemento_escalar MAIOR_QUE subquery
	|	elemento_escalar MENOR_QUE subquery
	|	elemento_escalar MAIOR_IGUAL_QUE subquery
	|	elemento_escalar MENOR_IGUAL_QUE subquery
	|	elemento_escalar IGUAL subquery	
	;

like_predicado:
		elemento_escalar NOT LIKE atom
	|	elemento_escalar LIKE atom
	;

subquery:
		ABRE_PAREN SELECT ALL FROM expressao_tabela FECHA_PAREN
	;

elemento_escalar:
		elemento_escalar MAIS elemento_escalar
	|	elemento_escalar MENOS elemento_escalar
	|	elemento_escalar ASTERISCO elemento_escalar
	|	elemento_escalar DIVIDE elemento_escalar
	|	MAIS elemento_escalar %prec MENOS
	|	MENOS elemento_escalar %prec MENOS
	|	atom
	|	ABRE_PAREN elemento_escalar FECHA_PAREN
	;

atom:
		literal	
	;


literal:
		STRING
	|	DIGITO
	|	INTEIRO
	| 	REAL
;

table:
		PALAVRA
	|	TABELA
;

%%

int yyerror(char *s) {
	printf("%s\n", s);
}

int main() {
	if(yyparse())
		fprintf(stderr, "Analisado com sucesso.\n");
	else
		fprintf(stderr, "Erro de analise.\n");
}

