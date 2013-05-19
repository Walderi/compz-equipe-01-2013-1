calc: calculadora.y calculadora.lex
	bison -d calculadora.y
	flex -o calculadora.l.c calculadora.lex
	gcc -o calculadora calculadora.l.c calculadora.tab.c -lfl -lm

clean:
	rm -f *.c *.h calculadora
