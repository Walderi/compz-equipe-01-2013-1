algoritmo "Media "
// Função :
// Autor :
// Data : 06/05/2013
// Seção de Declarações 
var
produto1 : real
produto2 : real
produto3 : real
produtocompra: inteiro

inicio
// Seção de Comandos
escreval ( "Entre com o valor de 3 produtos!")
escreval ( "Entre com o valor do primeiro:") //Pega o primeiro numero
leia (produto1)
escreval ( "Entre com o valor do segundo:")  //pega o segundo numero
leia (produto2)
escreval ( "Entre com o valor do terceiro:")  //pega o terceiro numero
leia (produto3)

se ((produto1 < produto2) e (produto2 < produto3)) entao // Se o numero 1 for maior que os 2 então ele é o maior
   produtocompra <- 1
   senao
fimse

se( (produto1 < produto2) e (produto3 < produto1)) entao //Se o numero 2 for maior que os outros 2 entao ele é o maior
   produtocompra <- 3
    senao
fimse
se ( (produto1 > produto2) e (produto2 < produto3)) entao //Se o numero 3 for maior que os outros 2 entao ele é o maior
   produtocompra <- 2
   senao
fimse

escreval("O produto que voce deve comprar é o : ", produtocompra)

fimalgoritmo
