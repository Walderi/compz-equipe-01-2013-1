algoritmo "Media de notas"
// Função :
// Autor :
// Data : 06/05/2013
// Seção de Declarações 
var
  x : real
  y : real
  z : real
  w : real
  soma : real
  media : real
inicio
// Seção de Comandos 
escreval("Entre com a primeira nota:")
leia(x)
escreval("Entre com a segunda nota:")
leia(y)
escreval("Entre com a terceira nota:")
leia(z)
escreval("Entre com a quarta nota:")
leia(w)
soma <- x + y + z + w
media <- soma/4

escreval("A media foi:" ,media)
fimalgoritmo
