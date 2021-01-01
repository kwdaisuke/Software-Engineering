#include <stdio.h> 
#include <stdlib.h> 

int main(void) {
	int** my2DimArray;
	// I want a 10 x 8 array
	// Initialize the row of my array with pointer to
	// my one dimensional array
	my2DimArray = (int**)malloc(10 * sizeof(int*));
	for (size_t i = 0; i < 10; i++)
	{
		// initialize each one dimensional array
		my2DimArray[i] = (int*)malloc(8 * sizeof(int));
	}

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			my2DimArray[i][j] = i + j;
		}
	}

	printf("Value of my2DimArray[1][1] : %d", my2DimArray[0][2]);

	return 0;
}