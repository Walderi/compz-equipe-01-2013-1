#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAXvalue 1000000
#define MAXtab 100000

int numrandom;
int numentrada;
int hash[MAXtab];
int i;
int somaparcial, somaparcial1, soma;
int localizador, divisor;

int somar_numeros(int num, int divisor) { //Função que vai retornar a soma dos indices do numero passado!!

	if (num < divisor) {

		divisor = divisor / 10;
		somar_numeros(num, divisor);

	} else {

		if ((num > divisor) && (divisor != 10)) {

			somaparcial = num / divisor;
			soma = soma + somaparcial;
			num = num % divisor;

			divisor = divisor / 10;
			somar_numeros(num, divisor);

		} else {

			if (num > 10) {

				somaparcial1 = num / divisor;
				somaparcial = num % divisor;
				soma = soma + somaparcial + somaparcial1;

			} else {
				soma = soma + num;

			}

			//	return soma;

		}

	}
	return soma;
}

int hashing(int value) { // Função onde irá ser feito o hasing(distribuição dos valores) na tabela
	int indice;
	divisor = 1000000;

	indice = somar_numeros(value, divisor); // Retornará para a variavel indice a soma dos indices do numero passado como parametro

	if (hash[indice] != 0) {//Se na posição do indice já estiver ocupado, fará um tratamento para achar alguma posição disponivel
		int boolean = 1;
		while (boolean) {// enquanto a variavel boolean for verdadeira, ele irá acresentar 5 unidades
			indice = indice + 5;// em cada unidade do indice até encontrar um local vazio para salvar o valor
			if (hash[indice] != 0) {
				boolean = 1;
			} else {

				hash[indice] = value;
				boolean = 0;
			}
			if (indice >= MAXtab) {				// Se forem varridos todos os indices e não achar lugar disponiveis....
			
			printf("O Numero nao achou indice seguindo o padrão de hashing");  // ... ELe exibe a mensagem de erro
																				// e faz Alguma coisa pra solucionar o problema :x
			boolean = 0;		
			
			}
			
		}

	} else {

		hash[indice] = value; // se não houver nada nesse indice na tabela, o valor será setado nesse local na tabela

	}

	return 0;
}

void busca_localizacao(int value) {	// Função que vai buscar onde está localizado o valor passado como parametro

	int indice;
	indice = somar_numeros(value, divisor);
	if (hash[indice] != value) {//Se na posição do indice já estiver ocupado, fará um tratamento para achar alguma posição disponivel
		int boolean = 1;
		while (boolean) {// enquanto a variavel boolean for verdadeira, ele irá acresentar 5 unidades
			indice = indice + 5;// em cada unidade do indice até encontrar um local vazio para salvar o valor

			boolean = 1;
			if (indice >= MAXtab) {

				printf("O valor de %d, não está localizado na tabela  \n",
						value);			//Imprime onde está localizado o valor

			}

			if (hash[indice] == value) {

				printf("O valor de %d, está localizado em: %d;  \n", value,
						indice);	//Imprime onde está localizado o valor
				boolean = 0;
			}

		}

	} else {

		printf("O valor de %d, está localizado em: %d;  \n", value, indice);//Imprime onde está localizado o valor

	}

}

int random_number() {

	srand(time(NULL ));

	//numrandom = aleatorio(time null) % MAXvalue;
	numrandom = rand() % MAXvalue;

	return numrandom;
}

/*usa essa função aqui para os numeros aleatorios, pois a função rand do C não cria numeros tão altos */
__int64 aleatorio(__int64 a) {
	__int64  x;
         x = a;
         x = (3202034522624059733LL*x + 4354685564936845319LL) / 4294967291LL;
         return x;
}

void mostrar_value(int localizador2) {

	if (localizador2 < MAXtab)
		printf("o numero presente nesse local é: %d \n", hash[localizador2]);
	else
		printf("Valor excedido ao tamanho da tabela!! \n");
}

void deletar_valor( localizador) {
	if (localizador < MAXtab) {
		char leitura;
		printf("Deseja apagar o valor de %d, que é : %d ?[s/n]  \n",
				localizador, hash[localizador]);
		scanf("%c", &leitura);
		switch (leitura) {
		case 's':
			hash[localizador] = 0;
			printf("Valor setado como NULL com sucesso!!!");
			break;

		case 'n':
			break;
		}

	} else {
		printf("Valor excedido ao tamanho da tabela!! \n");
	}

}

int main() {

	printf("Bem Vindo!!!\n");
	int numentrada = 1;

	while (numentrada != 0) {
		printf(
				"Para executar a tabela digite 1, para localizar um numero pelo localizador digite 2, para deletar um numero digite 3, para buscar a localização de um numero digite 4 e para sair do programa digite 0:\n");

		scanf("%d", &numentrada);

		switch (numentrada) {

		case 1: {
			int i;
			for (i = 0; i < MAXtab; i++) {

				int numero = random_number();
				hashing(numero);
			}
			break;
		}

		case 2:

			printf("Digite o numero do localizador:\n");

			scanf("%d", &localizador);
			mostrar_value(localizador);

			break;

		case 3:
			printf("insira o localizador:\n");
			int localizador1;
			scanf("%d", &localizador1);
			deletar_valor(localizador1);
			break;

		case 4:
			printf("insira o numero a ser localizado:\n");
			int numero;
			scanf("%d", &numero);
			busca_localizacao(numero);
			break;

		case 0:
			numentrada = 0;
			break;

		}

	}
	return 0;
}
