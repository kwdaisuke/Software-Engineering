#include <stdio.h>

int mainArray(void) {
	//variable is only declared not initialized
	int myInteger;
	//Initialization inline
	int myArray[3] = { 0, 0, 0 };
	//Initialization with loop
	for (size_t i = 0; i < 3; i++)
	{
		//Initialization of the ith value in the array
		myArray[i] = 0;
	}
	printf("myArray[0] = %d", myArray[0]);

	myInteger = 8;
	int* myIntegerPointer = &myInteger;

	//Access to the first value of the pointer MyIntegerPointer
	printf("myInteger = %d", myIntegerPointer[0]);
	/*
	myIntegerPointer[0] and *myIntegerPointer are exactly same
	*/
}