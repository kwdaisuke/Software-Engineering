#include "Recursion.h"
#include <stdio.h>
#include "Sort.h"

void printArray(int* mArray, int length) {
	printf("Array values are : \n");
	for (size_t i = 0; i < length; i++)
	{
		printf("Element at %d : %d \n", i, mArray[i]);
	}
}

int main(void) {
	/*int fact_int=factorial(1);
	printf("Factorial for U0 wit n0=1 1 is : %d \n", fact_int);
	 fact_int = factorial(5);
	printf("Factorial for Un with n=5 is : %d \n", fact_int);

	fact_int = factorial(6);
	printf("Factorial for Un+1 with n+1=6 is : %d \n", fact_int);*/

	int myArray[8] = { 4,2,8,1,6,5,7,3 };
	printArray(myArray, 8);
	MergeSort(myArray, 0, 7);
	printArray(myArray, 8);
}

switch (a) {
case 0:
	printf("a is false");
	break;
case 1:
	printf("a is true");
	break;
default:
	printf("a is true but not equal to 1")
}
