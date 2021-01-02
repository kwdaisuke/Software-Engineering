#include "DynamicArray.h"


void append_to_array(DynamicArray* arr, int value) {
	// I create a temporary array
	int* new_array = malloc((arr->length + 1) * sizeof(int));
	for (size_t i = 0; i < arr->length; i++)
	{
		new_array[i] = arr->values[i];
	}
	new_array[arr->length++] = value;
	free(arr->values);
	arr->values = malloc((arr->length) * sizeof(int));
	for (size_t i = 0; i < arr->length; i++)
	{
		arr->values[i] = new_array[i];
	}
}

DynamicArray createDynamicArray(size_t length, int* values) {
	DynamicArray arr = { length, values,&append_to_array };
	return arr;
}

void deleteDynamicArray(DynamicArray* arr) {
	free(arr->values);
}
