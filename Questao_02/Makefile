CC=gcc
CFLAGS=-I.

verficar-emails: main.o lista_email.o
	$(CC) -o verificar-emails main.o lista_email.o -I.

.PHONY: clean


clean:
	@ echo Cleaning...
	rm -rf ./*.o
	rm -rf ./verificar-emails
	@ echo
