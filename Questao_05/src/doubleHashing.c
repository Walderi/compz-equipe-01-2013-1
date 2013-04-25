/*
*  Double Hashing
*
*  by: André Moreira
*
*/

#include <stdio.h>

#define matrixSize 13

unsigned int hashMatrix[matrixSize];

void setHashMatrixNull()
{
	int i = matrixSize;
	for(i = 0; i<matrixSize; i++)
	{
		hashMatrix[i] = NULL;
	}
}

unsigned int hashing(int Key)
{
}

unsigned int hashing2(int Key)
{
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

void main() 
{
    printf("Hello World");

//    int i = 0;
//    for(i = 0; i<13; i++)
//    {
//        hashMatrix[i] = NULL;
//    }

    if (hashMatrix[1] == NULL)
    {
    printf(" NULL ");
    }else{ printf(" Bug ");}

}

