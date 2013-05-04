/*
*  Double Hashing
*
*  by: André Moreira
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define matrixSize 100003
//#define matrixSize 19
#define randomNumberRoofTop 1000000
//#define randomNumberRoofTop 100
#define bufferSize 100000
//#define bufferSize 17
#define hashing2Constant 99991
//#define hashing2Constant 17

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
	for(i=0; i<bufferSize; i++)
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
				if(position >= matrixSize)
				{
					position = (position - matrixSize);
				}
		}
	hashMatrix[position] = value;
	}
}

int findValue(unsigned int value)
{
	unsigned int position = hashing(value);
	unsigned int nextPosition = hashing2(value);

	if (hashMatrix[position] == NULL)
	{
		printf("value not found on hash table\n");
		return -1;
	}
	else if (hashMatrix[position] == value)
	{
		printf("value found on hash table\n");
		return (position);
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
			if(hashMatrix[position] == value)
			{
				printf("value found on hash table\n");
				return (position);
			}
		}
		printf("value not found on hash table\n");
		return -1;
	}
}

void printHashMatrix()
{
	int i;
	FILE * file;
	file = fopen("matrix.txt","w+");
	for(i = 0; i<matrixSize; i++)
	{
	    if(hashMatrix[i] == NULL)
        {
        	fprintf(file, "[%u] [NULL]\n", i);
        	//printf("[%u] [NULL] \n", i);
        }
        else
        {
        	fprintf(file, "[%u] [%u]\n", i, hashMatrix[i]);
        	//printf("[%u] [%u] \n", i, hashMatrix[i]);
        }
	}
	fclose(file);
} 

void insertAll()
{
	int i;
	for(i = 0; i<bufferSize; i++)
		{
			insertValue(randomNumbersBuffer[i]);
		}
}

void main()
{
	int i;
	int value;
	int position;
	setHashMatrixNull();
	generateRandomNumbers();
    insertAll();
    printHashMatrix();
    printf("Enter the desired value or -1 to exit\n");

    while( value!= -1 )
    {
    	scanf("%d", &value);
        if(value != -1)
        {
        	position = findValue(value);
        	if(position > -1)
        	{
        		printf("value stored on position %d \n", position);
        	}
        }
    }
}

