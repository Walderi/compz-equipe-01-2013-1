#include <stdio.h>
#include <stdlib.h>
#define MAXvalue 1000000;
#define MAXtab 100000;

int numrandom;
int numentrada;
int hash[MAXtab];

int hasing(int value){ // Função onde irá ser feito o hasing(distribuição dos valores) na tabela


return 0;
}

int random(){

	srand(time(NULL));

	numrandom = rand() % MAXvalue;

	return numrandom;
	}

	
void mostrar_value(int localizador){

	if ( localizador < MAXtab)
	printf("o numero presente nesse local é: %d \n", hash[localizador]);
	else 
	printf("Valor excedido ao tamanho da tabela!! \n");
	}


void deletar_valor(int localizador){
	if ( localizador < MAXtab){
	char leitura;
	printf("Deseja apagar o valor de %d, que é : %d ?[s/n]  \n", localizador, hash[localizador])
	scanf(% ,&leitura)
		switch(leitura)
		case s
		hash[localizador] = NULL;
		printf("Valor setado como NULL com sucesso!!!");
		
		case n
		break;
		
		
	}else{ 
	printf("Valor excedido ao tamanho da tabela!! \n");
	}

}

int main() {

printf("Bem Vindo!!!\n");

		while( numentrada != 0){
		printf("Para executar a tabela digite 1, para localizar um numero pelo localizador digite 2, para deletar um numero digite 3 e para sair do programa digite 0:\n");

		scanf("%d",&numentrada);

		switch(numentrada)

			case 1
				for( int i=0; i < MAXtab ; i++){
 
				int numero = random();
				hashing(numero);
				}
			break;
	
			case 2
	
			printf("Digite o numero do localizador:\n");
			int localizador;
			scanf("%d",&localizador);
			mostrar_value(localizador);
			break;
			
			case 3 
			printf("insira o localizador:\n");
			int localizador;
			scanf("%d",&localizador);
			deletar_valor(localizador);
			break;
	
			case 0
			numentrada = 0;
			break;
			
		

	}
return 0;
}