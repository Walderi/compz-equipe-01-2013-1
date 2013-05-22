compile: validador_sql.y validador_sql.lex
	bison -d validador_sql.y
	flex -o validador_sql.lex.c validador_sql.lex
	gcc -o validador_sql validador_sql.lex.c validador_sql.tab.c -lfl -lm

clean:
	rm -f *.c *.h validador_sql
