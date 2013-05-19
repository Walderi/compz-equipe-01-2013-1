%{
/*Validador de Relou Uourdi */
extern int yywrap() { }
%}

ALGORITMO algoritmo
FIMALGORITMO fimalgoritmo
INICIO inicio
ESCREVAL escreval
STRING \".*\"
ESCREVA escreva
COMENTARIO [\/\/].*

%%

{ALGORITMO} printf("%s T_ALGORITMO\n", yytext);
{FIMALGORITMO} printf("%s T_FIMALGORITMO\n", yytext);
{INICIO} printf("%s T_INICIO\n", yytext);
{ESCREVAL} printf("%s T_ESCREVAL\n", yytext);
{STRING}  printf("%s T_STRING\n", yytext);
{ESCREVA} printf("%s T_ESCREVA\n", yytext);
{COMENTARIO} printf("%s T_COMENTARIO\n", yytext);
"(" printf("%s ABRE PARENT\n", yytext);
")" printf("%s FECHA PARENT\n", yytext);

%%

main (int argc, char *argv[])
{
	yyin = fopen (argv[1], "r");

	if(yylex())
		fprintf(stderr, "\nCorrija e tente de novo!\n\n");
	else
		fprintf(stderr, "\nAew! Escreveu ok o código...\n\n");
	
	fclose(yyin);
	
	return 0;	
}
