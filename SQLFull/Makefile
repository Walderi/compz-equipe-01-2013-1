calc: sql2.y sql2.l
	bison -d sql2.y
	flex -o sql2.l.c sql2.l
	gcc -o sql2 sql2.l.c sql2.tab.c -lfl -lm

clean:
	rm -f *.c *.h sql2
