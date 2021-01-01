#include <stdio.h>
#include <stdlib.h>

int* append(int* ptr, size_t* size_array, int val) {
	int* myNewArray = (int*)malloc((*size_array + 1) * sizeof(int));

	for (size_t i = 0; i < size_array; i++)
	{
		//Initialize in new array
		//The values from the previous one
		myNewArray[i] = ptr[i];
	}
	//add the new value at the last place
	myNewArray[*size_array] = val;
	*size_array += 1;
	//free my old array
	free(ptr);
	return myNewArray;
}

int mainDynamicArray(void) {
	int* myArray;
	size_t size_of_Myarray = 10;
	// 10*4 = 40 byte sizeof(int)=4
	myArray = (int*)malloc(size_of_Myarray * sizeof(int));
	for (size_t i = 0; i < 10; i++)
	{
		myArray[i] = i;
	}
	myArray = append(myArray, &size_of_Myarray, 8);
	printf("New value is : %d", myArray[10]);
}