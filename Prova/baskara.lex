%{
/*Validador de Portugol*/
extern int yywrap() { }
%}

ALGORITMO /algoritmo/i
FIMALGORITMO /fimalgoritmo/i
INICIO /inicio/i
ESCREVAL /escreval/i
STRING \".*\"
ESCREVA /escreva/i
VAR /var/i
LOGICO /logico/i
INTEIRO /inteiro/i
VERDADEIRO /verdadeiro/i
FALSO /falso/i
REAL /[r]eal/i
PI /[p][\i]/i
LEIA /leia/i
SE /[s][\e]/i
ENTAO /[\e]ntao/i
SENAO /[s][\e]nao/i
FIMSE /fims[\e]/i
ESCOLHA /escolha/i
FIMESCOLHA /fimescolha/i
CASO /caso/i
INTERROMPA /interrompa/i 
OUTROCASO /outrocaso/i
AND /[\e]/i
OR  /[ou]/i
COMENTARIO [\//]{2}.*
DIVISAO [\//]{1}
DIVISAOINTEIRA [\\]{1}
MOD /mod/i
VARIAVEL [a-zA-Z]+[0-9]*
ATRIBUI \<\-
NUMINTEIRO [0-9]+
NUMREAL {NUMINTEIRO}\.{NUMINTEIRO}
REPITA /repita/i
ATE /ate/i
PROCEDIMENTO /procedimento/i
TAB [\t]*
ESPACOVAZIO [ ]*
RAIZQ /raizq/i

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
":" return  T_DOISPONTOS;
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
{NUMREAL} return T_NUMREAL;

. printf("%s - T_DESCONHECIDO. Localizado na linha: %d \n", yytext,yylineno);
%%
