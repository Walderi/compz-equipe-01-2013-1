%{
#define YYSTYPE double
#include "validador_sql.tab.h"
#include <stdlib.h>
%}

digit [0-9]
integer {digit}+
real {integer}("."{integer})?
white [ \t \n]+
select [sS][eE][lL][eE][cC][tT]
from [fF][rR][oO][mM]
where [wW][hH][eE][rR][eE]
and [aA][nN][dD]
order [oO][rR][dD][eE][rR]
by [bB][yY]
orderby {order}{white}{by}
like [lL][iI][kK][eE]
palavra [a-zA-Z]+
as [aA][sS]
origem {palavra}+{integer}?
group [gG][rR][oO][uU][pP]
groupby {group}{white}{by} 
limit [lL][iI][mM][iI][tT]

%%

{white} { }
{real} { yylval=atof(yytext); 
 return NUMBER;
}

{select} 	return SELECT;
{from} 		return FROM;
{where}		return WHERE;
{and} 		return AND;
{like}		return LIKE;
{orderby} 	return ORDERBY;
{groupby}   	return GROUPBY;
{as}		return AS;
{origem}	return ORIGEM;
{limit} 	return LIMIT;
"+"		return MAIS;
"-"		return MENOS;
"*" 		return ASTERISCO;
"/" 		return DIVIDE;
"(" 		return ABRE;
")" 		return FECHA;
";" 		return END;
"="		return EQUALS;
"\'"		return ASPAS;

