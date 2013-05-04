LEX=flex
CC=gcc
all: valida_email

valida_email: valida_email.lex
	@ echo Compiling...
	$(LEX) -o valida_email.c valida_email.lex
	$(CC) -o valida_email valida_email.c -lfl
	make clean
	clear
	@ echo Done!
	
clean:
	@ echo Cleaning...
	rm -rf ./*.c
	clear
	@ echo Cleaned!

.PHONY: test

test:
	@ echo Testing...
	./valida_email arquivo-emails1.txt
	@ echo TEST OK!
