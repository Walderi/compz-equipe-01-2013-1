%{
/* Questão 2 utilizando Lex */
%}

EMAIL [a-zA-Z][\.\_ \- a-z0-9]*[@][a-z0-9]+([\.][a-z]+){1,2}[\r|\n|\t]*

%%

{EMAIL} printf ("True   -  %s", yytext);
. printf ("False  -  %s", yytext);

%%

main (int argc, char *argv[])
{
	if(argc < 2)
	{
	printf("Faltando arquivo\n"); exit(-1);
	}
	yyin = fopen(argv[1], "r");
	yylex();
}
