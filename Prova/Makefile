compile: baskara.y baskara.lex
	@echo "compiling..." 
	bison -d baskara.y
	flex  -o baskara.lex.c baskara.lex
	gcc -o baskara baskara.lex.c baskara.tab.c -lfl -lm
	@echo "success!"
clean:	
	@echo "cleaning..."
	rm -f *.c *.h baskara
	@echo "cleaned!"

test: 	
	./baskara ./baskara.alg
	
