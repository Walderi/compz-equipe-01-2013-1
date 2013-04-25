/*
*  Double Hashing
*
*  by: André Moreira
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

#define matrixSize 100003
#define randomNumberRoofTop 1000000
#define bufferSize 100000
#define hashing2Constant 99991

unsigned int hashMatrix[matrixSize];
int * randomNumbersBuffer = NULL;

void setHashMatrixNull()
{
	int i = matrixSize;
	for(i = 0; i<matrixSize; i++)
	{
		hashMatrix[i] = NULL;
	}
}

void generateRandomNumbers()
{
	unsigned int i;
	srand(time(NULL));
	randomNumbersBuffer = (int *) malloc(bufferSize * sizeof(int));
	for(i=0; i<randomNumberRoofTop; i++)
	{
		randomNumbersBuffer[i] = rand() % randomNumberRoofTop;
	}
}

unsigned int hashing(int Key)
{
	return (Key % matrixSize);
}

unsigned int hashing2(int Key)
{
	return ( hashing2Constant - (Key % hashing2Constant));
} 

void insertValue()
{
}

unsigned int getValue()
{
}

void printValue()
{
} 

int main()
{


	free(randomNumbersBuffer);
	return 0;

}

