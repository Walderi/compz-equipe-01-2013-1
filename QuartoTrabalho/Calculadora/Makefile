calc: calculadora.y calculadora.lex
	bison -d calculadora.y
	flex -o calculadora.lex.c calculadora.lex
	gcc -o calculadora calculadora.lex.c calculadora.tab.c -lfl -lm

clean:
	rm -f *.c *.h calculadora
