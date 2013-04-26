/*
	Quest�o 03 da lista de compiladores

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
Essa fun��o tem como objetivo pegar todos os indices de um numero e soma-lo
por exemplo, 1024, somar 1+0+2+4 totalizando 7.

A fun��o somar_numeros passar� como parametro um numero inteiro e um divisor
caso o divisor seja maior que o numero ele dividir� o divisor por 10 e passar�
o mesmo numero e o divisor, agora dividido como parametro na fun��o. Caso o 
numero seja maior que o divisor e o divisor for diferente de 10, entao ele
pegar� o quociente da divis�o e o acresentar� uma vari�vel acumuladora,ai ent�o
atualizar� o valor do numero com o resto da divis�o e dividir� o divisor por 10.
Ai ent�o passar� como parametro o numero e o divisor atualizado. Caso divisor 
seja menor que o numero e o divisor igual a 10 entao, se o numero for menor que
10 o numero ser� atuliazado no valor da variavel acumuladora, caso o contrario
ser� guardado em 2 variaveis, uma com a divisao e o outro com o resto, ambas
ser� atualizada na variavel que guadara a soma, ai ent�o retornar� a soma.
*/

int somar_numeros(int num, int divisor) { //Fun��o que vai retornar a soma dos indices do numero passado!!


	if (num < divisor) {

		divisor = divisor / 10;
		somar_numeros(num, divisor);

	} else {

		if ((num > divisor) && (divisor != 10)) {

			somaparcial = num / divisor;		//Variavel que ir� guardar o quoeciente inteiro da divis�o
			soma = soma + somaparcial;			//Variavel acumuladora que ir� guardar as somas dos quoecientes
			num = num % divisor;				//Atualiza��o do numero com o resto da divis�o

			divisor = divisor / 10;				//Atualiza��o do divisor
			somar_numeros(num, divisor);		//Chama a fun��o denovo

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
/*
	A fun��o hasing() tem como objetivo encaixar o valor passado em algum lugar da tabela
Ela recebe como parametro um valor, que ser� o valor desejado para se encaixar na tabela
cada vez que a fun��o � chamada ela iniciliaza o indice, o divisor com 10^6 e essa variavel 
indice recebe o resultado da fun��o somar_numeros, j� discutida anteriormente. O tratamento
dado foi trabalhando o erro, se na posi��o de indice da tabela ja estiver sido ocupada por outro
valor, entao ele entra em um loop, acresentando sempre +1 ao indice, at� encontrar um local para 
guardar a variavel. Caso chegue ao fim da tabela nesse loop sem encontrar um valor final, ele volta
para o inicio da tabela at� encontrar, do inicio, um local para armazenar esse valor.
*/
int hashing(int value) { 									// Fun��o onde ir� ser feito o hasing(distribui��o dos valores) na tabela
	int indice;
	divisor = 1000000;
	soma=0;
	indice = somar_numeros(value, divisor) - 1; 			// Retornar� para a variavel indice a soma dos indices do numero passado como parametro

	if (hash[indice] != 0) {								//Se na posi��o do indice j� estiver ocupado, far� um tratamento para achar alguma posi��o disponivel
		int boolean = 1;
		while (boolean) {									// enquanto a variavel boolean for verdadeira, ele ir� acresentar 5 unidades
			indice = indice + 1;							// em cada unidade do indice at� encontrar um local vazio para salvar o valor
			if (hash[indice] != 0) {
				boolean = 1;
			} else {

				hash[indice] = value;
				printf("ocupou %d\n", indice); 				//emiti o valor do indice ocupado pelo valor
				boolean = 0;
			}
			if (indice >= MAXtab) {							// Se forem varridos todos os indices e n�o achar lugar disponiveis....

			
			indice = 0;
			while (boolean) {								// enquanto a variavel boolean for verdadeira, ele ir� acresentar 1 unidade
					
						if (hash[indice] != 0) {
							indice = indice + 1;			// em cada unidade do indice at� encontrar um local vazio para salvar o valor	
							boolean = 1;
						} else {
							hash[indice] = value;
							printf("ocupou %d\n", indice); //emiti o valor do indice ocupado pelo valor
											
											boolean = 0;
										}
						}
			return 1;

			}

		}

	} else {

		hash[indice] = value; 							// se n�o houver nada nesse indice na tabela, o valor ser� setado nesse local na tabela
		printf("ocupou %d\n", indice);					//emiti o valor do indice ocupado pelo valor
	}

	return 1;
}

void busca_localizacao(int value) {						// Fun��o que vai buscar onde est� localizado o valor passado como parametro

	int indice;
	indice = somar_numeros(value, divisor);
	if (hash[indice] != value) {						//Se na posi��o do indice j� estiver ocupado, far� um tratamento para achar a posi��o do valor
		int boolean = 1;
		while (boolean) {								// enquanto a variavel boolean for verdadeira, ele ir� acresentar 1 unidade
			indice = indice + 1;						// em cada unidade do indice at� encontrar o local do valor

			boolean = 1;
			if (indice >= MAXtab) {						// Se o indice estourar o valor max da tabela, ele come�ar� do zero na tabela
				int	indicenovo;

				for( indicenovo = 0; indicenovo < indice; indicenovo++){ // Far� a busca de zero at� o indice inicial para ve se encontra esse valor
					if(hash[indicenovo] == value){
							break;						// Faz um break no momento em que ele achar o valor de procura na tabela								
					}									// Salvando o indicenovo como posi��o do valor
				}
				if(indicenovo == indice){				// Se ele chegar na mesma posi��o do indice antigo � sinal que ele percorreu
			printf("O valor de %d, n�o est� localizado na tabela  \n",value);// percorreu toda a tabela e n�o achou o valor
			boolean = 0;
				} else{
					printf("O valor de %d, est� localizado em: %d;  \n", value, 
					indicenovo);						//Imprime onde est� localizado o valor onde est� localizado o indice do valor encontrado  
				boolean = 0;

				}
			}

			if (hash[indice] == value) {

				printf("O valor de %d, est� localizado em: %d;  \n", value,
						indice);						//Imprime onde est� localizado o valor caso ele o encontre sem precisar zerar o indice
				boolean = 0;
			}

		}

	} else {

		printf("O valor de %d, est� localizado em: %d;  \n", value, indice);
													//Imprime onde est� localizado o valor caso ele seja encontrado na primeira tentativa, sem incrementar o indice

	}


}
/*
	A fun��o random_number � responsavel pela randomiza��o dos numero que 
ser�o acresentados na tabela

*/
int random_number() {

	srand(time(NULL ));

	numrandom = rand() % MAXvalue;

	return numrandom;
}

/*
	A fun��o mostrar_value ir� mostrar o valor que est� localizado
na tabela utilizando o localizador do numero passado como parametro

*/
void mostrar_value(int localizador2) {

	if (localizador2 < MAXtab)
		printf("o numero presente nesse local �: %d \n", hash[localizador2]); // Imprime o valor, caso o localizador passado perten�a a tabela
	else
		printf("Valor excedido ao tamanho da tabela!! \n");
}
/*
	A fun��o deletar_valor() tem como objetivo deletar o valor 
presente dentro da tabela utilizando o localizador passado como
parametro da fun��o

*/
void deletar_valor( localizador) {
	if (localizador < MAXtab) {

		hash[localizador] = 0;

		printf("Valor setado como 0 com SUCESSO!!!\n");			//S� apaga o valor se o localizador existir na tabela


	} else {
		printf("Valor excedido ao tamanho da tabela!! \n");
	}

}
/*
	A fun��o main() � a responsavel por chamar todas as outras
atrav�s de um menu de op��es que � utilizado pelo usu�rio
do programa
*/
int main() {		// Inicia a fun��o Main
	int numero;
	printf("!!!!!Bem Vindo!!!!!\n");
	int numentrada = 1;

	while (numentrada != 0) {
		printf("Para executar a tabela digite 1:\n");
		printf("Para localizar um numero pelo localizador digite 2:\n");
		printf("Para deletar um numero usando o localizador digite 3 :\n");
		printf("Para buscar a localiza��o de um numero digite 4:\n");
		printf("Para sair do programa digite 0:\n");
		scanf("%d", &numentrada);

		switch (numentrada) {

		case 1: {
			/*
			Inicia a gera��o de numero aleatorio e em cada ele faz o hashing
			passando o numero gerado como parametro!
			*/
			int i = 0;
			while ( i < MAXtab) {
				int numeroleitor = random_number();
				 hashing(numeroleitor);
				 ++i;
			}
			printf("FIM DA CONSTRU��O DA TABELA \n");
			break;
		}

		case 2:
		// Faz a leitura do localizador digitado e passa
		// como parametro na fun��o mostrar_value que vai ler onde est�
		// o numero dentro da tabela

			printf("Digite o numero do localizador:\n");

			scanf("%d", &localizador);
	    	mostrar_value(localizador);

			break;

		case 3:
		//Faz a leitura do localizador digitado e passa
		// como parametro para fun��o deletar_value que atrav�s
		// do localizador ir� apagar o numero que consta na tabela

			printf("insira o localizador:\n");
			int localizador1;
			scanf("%d", &localizador1);
			deletar_valor(localizador1);
			break;

		case 4:
		// Faz a leitura do numero a ser localizado e passa
		// como parametro para a fun��o busca_localizacao que vai
		// localizar o numero dentro da tabela

			printf("insira o numero a ser localizado:\n");
			scanf("%d", &numero);
			busca_localizacao(numero);
			break;



		case 0:
		// Caso seja zero ir� sair do programa
			numentrada = 0;
			break;

		}

	}
	return 0;
}
