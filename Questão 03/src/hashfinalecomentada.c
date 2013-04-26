/*
	Questão 03 da lista de compiladores

*/

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

/*
Essa função tem como objetivo pegar todos os indices de um numero e soma-lo
por exemplo, 1024, somar 1+0+2+4 totalizando 7.

A função somar_numeros passará como parametro um numero inteiro e um divisor
caso o divisor seja maior que o numero ele dividirá o divisor por 10 e passará
o mesmo numero e o divisor, agora dividido como parametro na função. Caso o 
numero seja maior que o divisor e o divisor for diferente de 10, entao ele
pegará o quociente da divisão e o acresentará uma variável acumuladora,ai então
atualizará o valor do numero com o resto da divisão e dividirá o divisor por 10.
Ai então passará como parametro o numero e o divisor atualizado. Caso divisor 
seja menor que o numero e o divisor igual a 10 entao, se o numero for menor que
10 o numero será atuliazado no valor da variavel acumuladora, caso o contrario
será guardado em 2 variaveis, uma com a divisao e o outro com o resto, ambas
será atualizada na variavel que guadara a soma, ai então retornará a soma.
*/

int somar_numeros(int num, int divisor) { //Função que vai retornar a soma dos indices do numero passado!!


	if (num < divisor) {

		divisor = divisor / 10;
		somar_numeros(num, divisor);

	} else {

		if ((num > divisor) && (divisor != 10)) {

			somaparcial = num / divisor;		//Variavel que irá guardar o quoeciente inteiro da divisão
			soma = soma + somaparcial;			//Variavel acumuladora que irá guardar as somas dos quoecientes
			num = num % divisor;				//Atualização do numero com o resto da divisão

			divisor = divisor / 10;				//Atualização do divisor
			somar_numeros(num, divisor);		//Chama a função denovo

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
	soma=0;
	indice = somar_numeros(value, divisor) - 1; // Retornará para a variavel indice a soma dos indices do numero passado como parametro

	if (hash[indice] != 0) {//Se na posição do indice já estiver ocupado, fará um tratamento para achar alguma posição disponivel
		int boolean = 1;
		while (boolean) {// enquanto a variavel boolean for verdadeira, ele irá acresentar 5 unidades
			indice = indice + 1;// em cada unidade do indice até encontrar um local vazio para salvar o valor
			if (hash[indice] != 0) {
				boolean = 1;
			} else {

				hash[indice] = value;
				printf("gerou %d\n", indice);
				boolean = 0;
			}
			if (indice >= MAXtab) {				// Se forem varridos todos os indices e não achar lugar disponiveis....

			printf("O Numero nao achou indice seguindo o padrão de hashing\n");  // ... ELe exibe a mensagem de erro
			indice = 0;
			while (boolean) {// enquanto a variavel boolean for verdadeira, ele irá acresentar 1 unidade
						//indice = indice + 1;// em cada unidade do indice até encontrar um local vazio para salvar o valor
						if (hash[indice] != 0) {
							indice = indice + 1;// em cada unidade do indice até encontrar um local vazio para salvar o valor	
							boolean = 1;
						} else {
							hash[indice] = value;
											//printf("Achou %d\n", indice);
											boolean = 0;
										}
						}
			return 1;

			}

		}

	} else {

		hash[indice] = value; // se não houver nada nesse indice na tabela, o valor será setado nesse local na tabela
		printf("gerou %d\n", indice);
	}

	return 1;
}

void busca_localizacao(int value) {	// Função que vai buscar onde está localizado o valor passado como parametro

	int indice;
	indice = somar_numeros(value, divisor);
	if (hash[indice] != value) {//Se na posição do indice já estiver ocupado, fará um tratamento para achar alguma posição disponivel
		int boolean = 1;
		while (boolean) {// enquanto a variavel boolean for verdadeira, ele irá acresentar 5 unidades
			indice = indice + 1;// em cada unidade do indice até encontrar um local vazio para salvar o valor

			boolean = 1;
			if (indice >= MAXtab) {
				int	indicenovo;

				for( indicenovo = 0; indicenovo < indice; indicenovo++){ 				// Fará a busca de zero até o indice inicial para ve se encontra esse valor
					if(hash[indicenovo] == value){
						break;
					}
				}
				if(indicenovo == indice){
			printf("O valor de %d, não está localizado na tabela  \n",
						value);
			boolean = 0;
				} else{
					printf("O valor de %d, está localizado em: %d;  \n", value,
					indicenovo);	//Imprime onde está localizado o valor
				boolean = 0;

				}
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

	numrandom = rand() % MAXvalue;

	return numrandom;
}

void mostrar_value(int localizador2) {

	if (localizador2 < MAXtab)
		printf("o numero presente nesse local é: %d \n", hash[localizador2]);
	else
		printf("Valor excedido ao tamanho da tabela!! \n");
}

void deletar_valor( localizador) {
	if (localizador < MAXtab) {

		hash[localizador] = 0;

		printf("Valor setado como 0 com SUCESSO!!!\n");


	} else {
		printf("Valor excedido ao tamanho da tabela!! \n");
	}

}

int main() {		// Inicia a função Main
	int numero;
	printf("!!!!!Bem Vindo!!!!!\n");
	int numentrada = 1;

	while (numentrada != 0) {
		printf("Para executar a tabela digite 1:\n");
		printf("Para localizar um numero pelo localizador digite 2:\n");
		printf("Para deletar um numero usando o localizador digite 3 :\n");
		printf("Para buscar a localização de um numero digite 4:\n");
		printf("Para sair do programa digite 0:\n");
		scanf("%d", &numentrada);

		switch (numentrada) {

		case 1: {
			/*
			Inicia a geração de numero aleatorio e em cada ele faz o hashing
			passando o numero gerado como parametro!
			*/
			int i = 0;
			while ( i < MAXtab) {
				int numeroleitor = random_number();
				 hashing(numeroleitor);
				 ++i;
			}
			printf("FIM DA CONSTRUÇÃO DA TABELA \n");
			break;
		}

		case 2:
		// Faz a leitura do localizador digitado e passa
		// como parametro na função mostrar_value que vai ler onde está
		// o numero dentro da tabela

			printf("Digite o numero do localizador:\n");

			scanf("%d", &localizador);
	    	mostrar_value(localizador);

			break;

		case 3:
		//Faz a leitura do localizador digitado e passa
		// como parametro para função deletar_value que através
		// do localizador irá apagar o numero que consta na tabela

			printf("insira o localizador:\n");
			int localizador1;
			scanf("%d", &localizador1);
			deletar_valor(localizador1);
			break;

		case 4:
		// Faz a leitura do numero a ser localizado e passa
		// como parametro para a função busca_localizacao que vai
		// localizar o numero dentro da tabela

			printf("insira o numero a ser localizado:\n");
			scanf("%d", &numero);
			busca_localizacao(numero);
			break;



		case 0:
		// Caso seja zero irá sair do programa
			numentrada = 0;
			break;

		}

	}
	return 0;
}
