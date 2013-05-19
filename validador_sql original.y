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
	|	select_statement
;

select_statement:	
		SELECT opt_all_distinct FROM table_exp
	|	SELECT ALL FROM table
;

opt_all_distinct:
		ALL
	| 	'*'
;

opt_where_clause:
		where_clause
;


operation_commalist:
		operation
	|	operation_commalist VIRGULA operation
	;

operation:
		SELECT	
	;

opt_order_by_clause:
		ORDER BY ordering_spec_commalist
	;

ordering_spec_commalist:
		ordering_spec
	|	ordering_spec_commalist VIRGULA ordering_spec
	;

ordering_spec:
		INTEIRO opt_asc_desc
	|	column_ref opt_asc_desc
	;

opt_asc_desc:
		ASC
	|	DESC
	;


query_exp:
		query_term
	;

query_term:
		query_spec
	|	ABRE_PAREN query_exp FECHA_PAREN
	;

query_spec:
		SELECT opt_all_distinct table_exp
	;

table_exp:
		from_clause opt_where_clause opt_group_by_clause
	;

from_clause:
		FROM table_ref_commalist
	;

table_ref_commalist:
		table_ref
	|	table_ref_commalist VIRGULA table_ref
	;

table_ref:
		table	
	;

where_clause:
		WHERE search_condition
	;

opt_group_by_clause:
		GROUP BY column_ref_commalist
	;

column_ref_commalist:	
		column_ref
	|	column_ref_commalist VIRGULA column_ref
;

column_ref:
		PALAVRA
	|	TABELA
	|	PALAVRA '.' PALAVRA '.' PALAVRA 
	;

	
column:
		PALAVRA
;

search_condition:
		search_condition OR search_condition
	|	search_condition AND search_condition
	|	NOT search_condition
	|	ABRE_PAREN search_condition FECHA_PAREN
	|	predicate
	;

predicate:
		comparison_predicate
	|	like_predicate
	;

comparison_predicate:
		scalar_exp MAIOR_QUE scalar_exp
	|	scalar_exp MENOR_QUE scalar_exp
	|	scalar_exp MAIOR_IGUAL_QUE scalar_exp
	|	scalar_exp MENOR_IGUAL_QUE scalar_exp
	|	scalar_exp IGUAL scalar_exp
	|	scalar_exp MAIOR_QUE subquery
	|	scalar_exp MENOR_QUE subquery
	|	scalar_exp MAIOR_IGUAL_QUE subquery
	|	scalar_exp MENOR_IGUAL_QUE subquery
	|	scalar_exp IGUAL subquery	
	;

like_predicate:
		scalar_exp NOT LIKE atom
	|	scalar_exp LIKE atom
	;

subquery:
		ABRE_PAREN SELECT opt_all_distinct FROM table_exp FECHA_PAREN
	;

scalar_exp:
		scalar_exp MAIS scalar_exp
	|	scalar_exp MENOS scalar_exp
	|	scalar_exp ASTERISCO scalar_exp
	|	scalar_exp DIVIDE scalar_exp
	|	MAIS scalar_exp %prec MENOS
	|	MENOS scalar_exp %prec MENOS
	|	atom
	|	ABRE_PAREN scalar_exp FECHA_PAREN
	;

scalar_exp_commalist:
		scalar_exp
	|	scalar_exp_commalist VIRGULA scalar_exp
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

