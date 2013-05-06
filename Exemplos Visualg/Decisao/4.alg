algoritmo "Vogal ou consoante "
// Função :
// Autor :
// Data : 06/05/2013
// Seção de Declarações 
var
x : caracter


inicio
// Seção de Comandos
escreval ( "Entre com a letra:")
leia (x)

escolha(x)
 caso "a", "e","i","o","u"                 // Por nao ser Case sensitive nao é
   escreval( "É uma vogal!!")              // necessário maisculo ou minusculo
outrocaso
     escreval("É uma consoante!!")
fimescolha

 
fimalgoritmo
