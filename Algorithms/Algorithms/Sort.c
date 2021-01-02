#include "Sort.h"
void swap(int* xp, int* yp)
{
	//temp int to get one of the value I swap to not lose it
	int temp = *xp;
	//the I swap my values
	*xp = *yp;
	*yp = temp;
}

/*
Explanation bubble sort
First pass (i loop):

( [5 1] 4 2 8 ) -> ( 1 5 4 2 8 )
( 1 [5 4] 2 8 ) -> ( 1 4 5 2 8)
( 1 4 [5 2] 8 ) -> (1 4 2 5 8)

Second pass :

([1 4] 2 5 8) -> ( 1 4 2 5 8 )
( 1 [4 2] 5 8 ) -> ( 1 2 4 5 8)
( 1 2 [4 5] 8)  -> ( 1 2 4 5 8)
( 1 2 4 [5 8]) ->  ( 1 2 4 5 8)

Third pass
( [1 2] 4 5 8) -> ( 1 2 4 5 8)
( 1 [2 4] 5 8) -> ( 1 2 4 5 8)
( 1 2 [4 5] 8)  -> ( 1 2 4 5 8)
( 1 2 4 [5 8]) ->  ( 1 2 4 5 8)


Here we can cosidere the array is sorted

*/

void bubbleSort(int* myArray, int length) {
	//For each row of my Array
	for (int i = 0; i < (length - 1); i++)
	{
		printf("Pass %d :\n", i);
		//I declare a variable to check at the end of the pass if a swap occured
		int is_swaped = 0;
		//I Compare each aside value between them
		// i=0  and length=6 for( j=0; j< 6-0-1; j++)
		//i=5  and length=6 for( j=0; j< 6-5-1; j I do not do the last value because it already sorted
		for (int j = 0; j < length - i - 1; j++) {
			printf("  Check %d with %d\n", myArray[j], myArray[j + 1]);
			//I check if value at j is greater than value at j+1
			if (myArray[j] > myArray[j + 1]) {
				printf("    swap %d and %d\n", myArray[j], myArray[j + 1]);
				//if yes I swap them and flag the swap
				swap(&myArray[j], &myArray[j + 1]);
				is_swaped = 1;
			}

		}
		// If no swap occure during the last pass it mean my array is sorted
		if (is_swaped == 0) {
			break;
		}
	}
}

//merge take the array, left index , split point and right index;
void merge(int* myArray, int l, int m, int r) {
	//I initialize my index and I calculate the length of Right and Left Array
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Declare left and right array
	int* L = malloc(n1 * sizeof(int));
	int* R = malloc(n2 * sizeof(int));

	//Initialize the value of Left Array
	for (i = 0; i < n1; i++)
	{
		L[i] = myArray[l + i];
	}
	//Initialize the value of Right Array
	for (j = 0; j < n2; j++)
	{
		R[j] = myArray[m + 1 + j];
	}

	//i will be the index for Left Array
	//j will be the index for Right Array
	//k will be the index for the global array
	i = 0;
	j = 0;
	k = l;

	//I loop until I reach the end of an array
	while (i < n1 && j < n2) {
		//I check if the value of Left Array at i is lower or equal to value of Right array at j
		if (L[i] <= R[j]) {
			//if it's lower I put at the position k the value of Left array at i
			myArray[k] = L[i];
			i++;
		}
		else {
			//else I put the value of Right array at j in global array at k
			myArray[k] = R[j];
			j++;
		}
		//Global array at k is set so I increment k
		k++;
	}
	//Set the value at k for remaining values in left array
	while (i < n1) {
		myArray[k] = L[i];
		i++;
		k++;
	}
	//Set the value at k for remaining values in right array
	while (j < n2) {
		myArray[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
	//And now my merge is complete and myArray is sorted between l and r)
}

void printArrayF(int* myArray, int i0, int length) {
	printf("Array values are : \n");
	for (size_t i = i0; i < length; i++)
	{
		printf("Element at %d : %d \n", i - i0, myArray[i]);
	}
}
//l is the first left element and r is last right element
// so l should be equal to 0 and r to length-1
//my Array is the array to sort
// All example will be with a 7 length array in comment
void MergeSort(int* myArray, int l, int r) {
	//I check left index is greater than right index
	// Because if it's not it's mean my array is one element so it's sorted
	printf("Global Array : \n");
	printArrayF(myArray, l, r);
	if (l < r) {
		// m = 0 +(7-0)/2 = 3
		int m = l + (r - l) / 2;
		printf("Left Array : \n");
		printArrayF(myArray, l, m);
		//Sort the array from 0 to 3
		MergeSort(myArray, l, m);
		printf("Right Array : \n");
		printArrayF(myArray, m + 1, r);
		// Sort the array from 4 to 7
		MergeSort(myArray, m + 1, r);
		//Merge the two array
		merge(myArray, l, m, r);
	}
}