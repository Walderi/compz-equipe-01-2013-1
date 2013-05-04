%{
/*Validador de email em flex */
extern int yywrap() { }
%}

EMAIL [a-zA-Z]+([\.\_\-]{0,1}[a-zA-Z0-9]+)*[@][a-z]+([\.][a-z]+){1,2}[\r|\n|\t]*

%%

{EMAIL} printf ("True   - %s", yytext);
.* printf ("False  - %s", yytext);

%%

main (int argc, char *argv[])
{
	if(argc < 2) {	
		printf("File not found!\n usage: %s filename\n",argv[0]);
	 	exit(-1);
	}
	
	yyin = fopen(argv[1], "r");
	
	yylex();
	
}
