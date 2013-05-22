%{
#define YYSTYPE double
#include "validador_sql.tab.h"
#include <stdlib.h>
%}

digito	[0-9]
inteiro	{digito}+
real 	{inteiro}[\.{inteiro}]?
string  [\".*\"]
white	[ \t\n]+

select	[sS][eE][lL][eE][cC][tT]
from	[fF][rR][oO][mM]
where	[wW][hH][eE][rR][eE]
as 	[aA][sS]
all	[aA][lL][lL]

and	[aA][nN][dD]
or	[oO][rR]
xor	[xX][oO][rR]
not	[nN][oO][tT]

group 	[gG][rR][oO][uU][pP]
order	[oO][rR][dD][eE][rR]
asc	[aA][sS][cC]
desc	[dD][eE][sS][cC]
by 	[bB][yY]
like	[lL][iI][kK][eE]
limit 	[lL][iI][mM][iI][tT]

palavra	[a-zA-Z0-9_]+
tabela	{palavra}[\.]{palavra}

%%

{white} 	{ }
{digito}	return DIGITO;
{inteiro}	return INTEIRO;
{real}		return REAL;
{string}  	return STRING;

{select} 	return SELECT;
{from} 		return FROM;
{where}		return WHERE;
{as}		return AS;
{all} 		return ALL;

{and} 		return AND;
{or}		return OR;
{xor}		return XOR;
{not}		return NOT;
 
{group}   	return GROUP;
{order} 	return ORDER;
{by} 		return BY;
{like}		return LIKE;
{limit}		return LIMIT;

{palavra}	return PALAVRA;
{tabela} 	return TABELA;
{asc}		return ASC;
{desc}		return DESC;

"+"		return MAIS;
"-"		return MENOS;
"'*'" 		return ASTERISCO;
"/" 		return DIVIDE;
"(" 		return ABRE_PAREN;
")" 		return FECHA_PAREN;
";" 		return FIM;
"="		return IGUAL;
">"		return MAIOR_QUE;
"<"		return MENOR_QUE;
">="		return MAIOR_IGUAL_QUE;
"<="		return MENOR_IGUAL_QUE;
"\'"		return ASPAS;
","		return VIRGULA;

.		{printf("T_DESCONHECIDO %s\n", yytext);}

%%
