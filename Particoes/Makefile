OBJS=main.o particoes.o
all: mypart
mypart: $(OBJS)
	gcc $(OBJS) -o $@
main.o: main.c
	gcc -c main.c -o main.o
particoes.o: particoes.c
	gcc -c $< -o $@
