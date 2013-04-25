/*
*  Double Hashing
*
*  by: André Moreira
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define matrixSize 100003
#define matrixSize 17
#define randomNumberRoofTop 100
#define bufferSize 17
//#define hashing2Constant 99991
#define hashing2Constant 13

unsigned int hashMatrix[matrixSize];
unsigned int randomNumbersBuffer[bufferSize];

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

void insertValue(unsigned int value)
{
	unsigned int position = hashing(value);
	unsigned int nextPosition = hashing2(value);
	if (hashMatrix[position] == NULL)
	{
		hashMatrix[position] = value;
	}
	else
	{
		while(hashMatrix[position] != NULL)
		{
			position =  (position + nextPosition);
				if(position >= matrixSize )
				{
					position = (position - matrixSize);
				}
		}
	hashMatrix[position] = value;
	}
}

unsigned int getValue()
{
}

void printHashMatrix()
{
	int i;
	for(i = 0; i<matrixSize; i++)
	{
		printf("[%u] [%u] \n", i, hashMatrix[i]);
	}
} 

void main()
{
	int i;
	setHashMatrixNull();
	generateRandomNumbers();

	for(i = 0; i<bufferSize; i++)
	{
		insertValue(randomNumbersBuffer[i]);
	}
	printHashMatrix();
}

