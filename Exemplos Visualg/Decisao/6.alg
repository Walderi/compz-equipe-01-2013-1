algoritmo "Media "
// Fun��o :
// Autor :
// Data : 06/05/2013
// Se��o de Declara��es 
var
numero1 : real
numero2 : real
numero3 : real

inicio
// Se��o de Comandos
escreval ( "Entre com 3 numeros distintos")
escreval ( "Entre com a primeira numero:") //Pega o primeiro numero
leia (numero1)
escreval ( "Entre com a segundo numero:")  //pega o segundo numero
leia (numero2)

escreval ( "Entre com o terceiro numero:")  //pega o terceiro numero
leia (numero3)

se ((numero1 > numero2) e (numero2 > numero3)) entao // Se o numero 1 for maior que os 2 ent�o ele � o maior
   escreval("Maior numero �:" , numero1)
   senao
fimse

se( (numero1 < numero2) e (numero2 > numero3)) entao //Se o numero 2 for maior que os outros 2 entao ele � o maior
    escreval("Maior numero �:" , numero2)
    senao
fimse
se ( (numero1 < numero2) e (numero2 < numero3)) entao //Se o numero 3 for maior que os outros 2 entao ele � o maior
   escreval("Maior numero �:" , numero3)
   senao
fimse


fimalgoritmo
