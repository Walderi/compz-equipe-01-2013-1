calc: calculadora.y calculadora.l
	bison -d calculadora.y
	flex  -o calculadora.l.c calculadora.l
	gcc  -o calculadora calculadora.l.c calculadora.tab.c -lfl -lm 

clean:
	rm -f *.c *.h calculadora
