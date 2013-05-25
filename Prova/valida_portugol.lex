%{
/*Validador de Portugol*/
extern int yywrap() { }
%}

ALGORITMO algoritmo
FIMALGORITMO fimalgoritmo
INICIO inicio
ESCREVAL escreval
STRING \".*\"
ESCREVA escreva
VAR var
LOGICO logico
INTEIRO inteiro
VERDADEIRO verdadeiro
FALSO falso
REAL [r]eal
PI [p][\i]
LEIA leia
SE [s][\e]
ENTAO [\e]ntao
SENAO [s][\e]nao
FIMSE fims[\e]
ESCOLHA escolha
FIMESCOLHA fimescolha
CASO caso
INTERROMPA interrompa 
OUTROCASO outrocaso
AND [\e]
OR  [ou]
COMENTARIO [\//]{2}.*
DIVISAO [\//]{1}
DIVISAOINTEIRA [\\]{1}
MOD mod
VARIAVEL [a-zA-Z]+[0-9]*
ATRIBUI \<\-
NUMINTEIRO [0-9]+
REPITA "repita"
ATE "ate"
PROCEDIMENTO "procedimento"
TAB [\t]*
ESPACOVAZIO [ ]*
RAIZQ raizq 

%%

\n (yylineno++);
{ALGORITMO} return T_ALGORITMO;
{FIMALGORITMO} return  T_FIMALGORITMO;
{INICIO} return T_INICIO;
{ESCREVAL} return  T_ESCREVAL;
{STRING} return  T_STRING;
{ESCREVA} return  T_ESCREVA;
{COMENTARIO} return  T_COMENTARIO;
"(" return  T_ABRE_PARENT;
")" return   T_FECHA_PARENT;
"," return  T_VIRGULA;
{AND} return  T_AND;
{OR}  return  T_OR;
{VAR} return  T_VAR;
{INTEIRO} return  T_INTEIRO;
{REAL} return  T_REAL;
{PI} return  T_PI;
{LEIA} return  T_LEIA;
{SE} return  T_SE;
{INTERROMPA} return  T_INTERROMPA;
{SENAO} return  T_SENAO;
{ENTAO} return  T_ENTAO;
{FIMSE} return  T_FIMSE;
{ESCOLHA} return  T_ESCOLHA;
{CASO} return  T_CASO;
{OUTROCASO} return  T_OUTROCASO;
{FIMESCOLHA} return  T_FIMESCOLHA;
{NUMINTEIRO} return  T_NUMINTEIRO;
{ATRIBUI} return  T_ATRIBUI;
":" return  T_DECLARAVAR;
"+" return  T_SOMA;
{DIVISAO} return  T_DIVISAO;
"-" return  T_SUBTRACAO;
"*" return  T_MULT;
"<>" return  T_DIFERENTE;
"^" return  T_POTENCIA;
"<" return  T_MENORQUE;
"<=" return  T_MENORIGUALQUE;
">" return T_MAIORQUE;
">=" return T_MAIORIGUALQUE;
"=" return T_IGUAL;
{REPITA} return T_REPITA;
{ATE} return T_ATE;
{LOGICO} return T_TIPO_LOGICO;
{VERDADEIRO} return T_LOGICO_VERDADEIRO;
{FALSO} return T_LOGICO_FALSO;
{PROCEDIMENTO} return T_PROCEDIMENTO;
{DIVISAOINTEIRA} return T_DIVISAOINTEIRA;
{MOD} return T_RESTO;
{VARIAVEL} return T_VARIAVEL;
{TAB} return {};
{ESPACOVAZIO} return {} ;
{RAIZQ} return T_RAIZQ;

. printf("%s - T_DESCONHECIDO. Localizado na linha: %d \n", yytext,yylineno);
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
