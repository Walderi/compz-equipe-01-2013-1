algoritmo "Media "
// Função :
// Autor :
// Data : 06/05/2013
// Seção de Declarações 
var
numero1 : real
numero2 : real
numero3 : real

inicio
// Seção de Comandos
escreval ( "Entre com 3 numeros distintos")
escreval ( "Entre com a primeira numero:") //Pega o primeiro numero
leia (numero1)
escreval ( "Entre com a segundo numero:")  //pega o segundo numero
leia (numero2)

escreval ( "Entre com o terceiro numero:")  //pega o terceiro numero
leia (numero3)

se ((numero1 > numero2) e (numero2 > numero3)) entao // Se o numero 1 for maior que os 2 então ele é o maior
   escreval("Maior numero é:" , numero1)
   senao
fimse

se( (numero1 < numero2) e (numero2 > numero3)) entao //Se o numero 2 for maior que os outros 2 entao ele é o maior
    escreval("Maior numero é:" , numero2)
    senao
fimse
se ( (numero1 < numero2) e (numero2 < numero3)) entao //Se o numero 3 for maior que os outros 2 entao ele é o maior
   escreval("Maior numero é:" , numero3)
   senao
fimse


fimalgoritmo
