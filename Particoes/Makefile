OBJS=main.o particoes.o
all: mypart
mypart: $(OBJS)
	gcc $(OBJS) -o $@
	make clean
main.o: main.c
	@echo "Compilando main.."
	gcc -c main.c -o main.o
particoes.o: particoes.c
	@echo "Compilando source.."
	gcc -c $< -o $@
clean:
	@echo "Limpando objetos.."
	rm -f $(OBJS)
