#include <stdio.h>

int mainPointer(void) {
	// I declare a int variable
	int myInteger;
	// I declare a pointer to a int
	int* pointerInteger;

	// I set pointerInteger to point to myInteger address
	pointerInteger = &myInteger;

	// I set the value of the variable pointed by
	// Pointer integer to 8 (in this case, the variable is)
	// myInteger
	*pointerInteger = 8;
	// Do not do this to convert type
	double myDouble = (double)myInteger;
	// Do not do this to convert type
	double* doublePointer = (double*)&myInteger;

	/*printf("Pointer value : %p\n", (void*) &pointerInteger);
	pointerInteger = 7;
	printf("Pointer value : %f\n", *doublePointer);*/

	// Get the size of a varibale size_t type is from C99

#if __STDC_VERSION__ >=  201910L
	printf("We are using C19!\n");
#elif __STDC_VERSION__ >= 201112L
	printf("We are using C11!\n");
#elif __STDC_VERSION__ >= 199901L
	printf("We are using C99!\n");
#else
	printf("We are using C89/C90!\n");
#endif

	return 0;

}