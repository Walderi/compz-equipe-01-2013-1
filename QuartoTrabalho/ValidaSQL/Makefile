compile: valida_sql.y valida_sql.lex
	@echo "compiling..." 
	bison -d valida_sql.y
	flex  -o valida_sql.lex.c valida_sql.lex
	gcc  -o valida_sql valida_sql.lex.c valida_sql.tab.c -lfl -lm
	@echo "success!"
clean:	
	@echo "cleaning..."
	rm -f *.c *.h valida_sql
	@echo "cleaned!"

test: 	
	./valida_sql sql
	
