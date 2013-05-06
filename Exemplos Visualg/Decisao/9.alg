algoritmo "Media "
// Função :
// Autor :
// Data : 06/05/2013
// Seção de Declarações 
var
numero1 : real
numero2 : real
numero3 : real
menornumero : real
maiornumero : real
meionumero : real
inicio
// Seção de Comandos
escreval ( "Entre com 3 numeros distintos")
escreval ( "Entre com a primeira numero:") //Pega o primeiro numero
leia (numero1)
escreval ( "Entre com a segundo numero:")  //pega o segundo numero
leia (numero2)

escreval ( "Entre com o terceiro numero:")  //pega o terceiro numero
leia (numero3)

se ((numero1 > numero2) e (numero2 > numero3)) entao // Se o numero 1 for maior que o numero 2
   maiornumero <- numero1                            // e o numero 2 maior que o numero 3e
   menornumero <- numero3                           // entao o numero 1 é o maior e o numero 3 o menor
   meionumero <- numero2
   senao
fimse

se ((numero1 > numero2) e (numero3 > numero2)) entao // Se o numero 1 for maior que o numero 3
   maiornumero <- numero1                            // E o numero 3 maior que o numero 2
   menornumero <- numero2                            //entao o numero 1 é o maior e o numero 2 o menor
   meionumero <- numero3
   senao
fimse

se( (numero2 > numero1) e (numero1 > numero3)) entao //Se o numero 2 for maior que o numero 1
    maiornumero <- numero2                           //E o numero 1 maior que o numero 3
    menornumero <- numero3                           //entao o numero 2 é o maior e o numero 3 menor
    meionumero <- numero1
    senao
fimse
se( (numero2 > numero1) e (numero3 > numero1)) entao //Se o numero 2 for maior que o numero 1
   maiornumero <- numero2                           //E o numero 3 maior que o numero 1
    menornumero <- numero1                           //Entao o numero 2 é o maior e o numero 1 o menor
    meionumero <- numero3
    senao
fimse

se( (numero3 > numero2) e (numero2 > numero1)) entao //Se o numero 3 for maior que o numero 2
    maiornumero <- numero3                           //E o numero 2 maior que o numero 1
    menornumero <- numero1                           //Entao o numero 3 é o maior e o numero 1 o menor
    meionumero <- numero2
    senao
fimse

se( (numero3 > numero1) e (numero1 > numero2)) entao //Se o numero 3 for maior que o numero1
    maiornumero <- numero3                           //E o numero 1 maior que o numero 2
    menornumero <- numero2                           //entao o numero 3 é maior e o numero 2 o menor
    meionumero <- numero1
    senao
fimse
escreval("Na ordem descresente fica:", maiornumero, meionumero, menornumero)

fimalgoritmo
