algoritmo "Media "
// Fun��o :
// Autor :
// Data : 06/05/2013
// Se��o de Declara��es 
var
nota1 : real
nota2 : real
media : real

inicio
// Se��o de Comandos
escreval ( "Entre com a primeira nota:") //Pega a primeira nota
leia (nota1)
escreval ( "Entre com a segunda nota:")  //pega a segunda nota
leia (nota2)

media <- (nota1+nota2)/2                //Faz a media


 se(media >= 7) entao
     escreval( "Aprovado!!")
 senao
     escreval("Reprovado!!")           // Senao reprovado
fimse
   se (media = 10) entao
    escreval( "Aprovado com Distin��o!!")
  fimse
fimalgoritmo
