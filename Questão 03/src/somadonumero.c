#include <stdio.h>
#include <stdlib.h>

int num, soma, somaparcial, somaparcial1;
int divisor = 1000000;

int i = 0;



/*
int somar_numeros(num, divisor){
	
	if(num < divisor){
	
		divisor = divisor/10;
		somar_numeros(num, divisor);
	
	

	

	
	}else {


		if ( (num > divisor) && (divisor != 10)){
		
			somaparcial = num/divisor;
			soma = soma + somaparcial;
			num = num%divisor;
			printf("O valor da primeira divisao foi foi: %d \n", somaparcial);		
	
			divisor = divisor/10;
			somar_numeros(num, divisor);

	
		
			} else {
	
		somaparcial1 = num/divisor;
		somaparcial = num%divisor;
		soma = soma + somaparcial + somaparcial1;
		
		printf("O valor da ultima divisao foi foi: %d \n", somaparcial1);
		printf("O valor do resto divisao foi foi: %d \n", somaparcial);

			
		
	//	return soma;
	
		  }


			

	}
	return soma;
}


int main() {

	int leitura; 
	int resultado;
	
	printf("entre com um numero:\n");
	scanf( "%d" , &leitura);
	
	resultado = somar_numeros(leitura, divisor);
	
	printf("O valor da soma foi: %d \n", resultado);
	printf("O valor do numero foi: %d \n", leitura);

	printf("\n");
return 0;
}
*/

int somar_numeros(num, divisor){
	
	if(num < divisor){
	
		divisor = divisor/10;
		somar_numeros(num, divisor);
	
	

	

	
	}else {


		if ( (num > divisor) && (divisor != 10)){
		
			somaparcial = num/divisor;
			soma = soma + somaparcial;
			num = num%divisor;
			printf("O valor da primeira divisao foi foi: %d \n", somaparcial);		
	
			divisor = divisor/10;
			somar_numeros(num, divisor);

	
		
			} else {
			
				if(num > 10){
	
				somaparcial1 = num/divisor;
				somaparcial = num%divisor;
				soma = soma + somaparcial + somaparcial1;
		
				printf("O valor da ultima divisao foi foi: %d \n", somaparcial1);
				printf("O valor do resto divisao foi foi: %d \n", somaparcial);
	
				} else {
				
				
				soma = soma + num;
		
				printf("O valor da ultima divisao foi foi: %d \n", somaparcial1);
				printf("O valor do resto divisao foi foi: %d \n", somaparcial);
				
				
				
				}
		
	//	return soma;
	
		  }


			

	}
	return soma;
}


int main() {

	int leitura; 
	int resultado;
	
	printf("entre com um numero:\n");
	scanf( "%d" , &leitura);
	
	resultado = somar_numeros(leitura, divisor);
	
	printf("O valor da soma foi: %d \n", resultado);
	printf("O valor do numero foi: %d \n", leitura);

	printf("\n");
return 0;
}
