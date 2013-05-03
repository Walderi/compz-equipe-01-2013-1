
LEX=flex
CC=gcc

valida_email: valida_email.lex
	@ echo Compiling...
	$(LEX) -o valida_email.c valida_email.lex
	$(CC) -o valida_email valida_email.c
	clear
	@ echo Done!
	
.PHONY: clean

clean:
	@ echo Cleaning...
	rm -rf ./*.c
	rm -rf ./valida_email
	clear
	@ echo Clean!

.PHONY: test

test:
	@ echo Testing...
	./valida_email arquivo-emails1.txt
	@ echo OK!
