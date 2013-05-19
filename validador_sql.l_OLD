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

%%

{white} { }
{real} { yylval=atof(yytext); 
 return NUMBER;
}

{select} 	return SELECT
{from} 		return FROM
{where}		return WHERE
{and} 		return AND
{orderby} 	return ORDERBY
"+"		return MAIS
"-"		return MENOS
"*" 		return ASTERISCO;
"/" 		return DIVIDE;
"(" 		return ABRE;
")" 		return FECHA;
";" 		return END
