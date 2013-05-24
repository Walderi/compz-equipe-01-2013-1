%option yylineno
%{
#define YYSTYPE double
#include "valida_sql.tab.h"
#include <stdlib.h>
%}

espaco			[ \t\r]+

select			[S|s][E|e][L|l][E|e][C|c][T|t]	
from			[F|f][R|r][O|o][M|m]
where			[W|w][H|h][E|e][R|r][E|e]
as			[A|a][S|s]

and			[A|a][N|n][D|d]
or			[O|o][R|r]
not			[N|n][O|o][T|t]
xor			[X|x][O|o][R|r]

group			[g|G][r|R][o|O][u|U][p|P]
order			[O|o][R|r][D|d][E|e][R|r]	
by			[B|b][Y|y]
asc			[A|a][S|s][C|c]
desc		        [D|d][E|e][S|s][C|c]

palavra			[A-Za-z][A-Za-z0-9_]*
palavra_tabela		{palavra}\.{palavra}

inteiro			[0-9]+
real			{inteiro}[\.{inteiro}]?
string			\'.*\'

%%

{espaco} 		{ }

{select}		return SELECT;
{from}			return FROM;
{where}			return WHERE;
{as}			return AS;

{and}			return AND;
{or}			return OR;
{not}			return NOT;
{xor}			return XOR;

{group}			return GROUP;
{order}			return ORDER;
{by}			return BY;
{asc}			return ASC;
{desc}			return DESC;

{palavra}		return CAMPO;			
{palavra_tabela}	return CAMPO_TABELA;

{inteiro}		return INTEIRO;
{real}			return REAL;
{string}		return STRING;

"+" 			return MAIS;
"-" 			return MENOS;
"/" 			return DIVISOR;
"*"			return ASTERISCO;
","			return VIRGULA;
"["			return ABRE_PARENTESE;
";"			return FIM;
"]"			return FECHA_PARENTESE;
"="			return IGUAL;
"<>"			return DIFERENTE;
"<"			return MENOR;
"<="			return MENOR_IGUAL;
">"			return MAIOR;
">="			return MAIOR_IGUAL;
"\n" 			{}

.			{printf("Invalido: %s\n", yytext);}
