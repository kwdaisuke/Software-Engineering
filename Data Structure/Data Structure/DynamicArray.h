#pragma once
#include <stdlib.h>


// an usigned char length is 1 byte so I can use it as byte and create the type byte
typedef unsigned char byte;

// typedef real_type name_of_type_to_create;

typedef enum Week
{
	Sun = 11,
	Mon = 12,
	Tue = 1,
	Wed = 3,
	Thu = 4,
	Fri = 17,
	Sat = 19
} Day;

//It represent a Dynamic Array of int
//Typedef is to use it as a new type

// I define a new type append_function this type is a pointer to a function
// with parameter void*, int
typedef void (*append_function)(void* arr, int value);
typedef struct DynamicArray {
	//legnth of the array
	size_t length;
	//values of the array
	int* values;

	//methods
	append_function append;

} DynamicArray;


DynamicArray createDynamicArray(size_t length, int* values);
void deleteDynamicArray(DynamicArray* arr);
// We put the name of the new type above