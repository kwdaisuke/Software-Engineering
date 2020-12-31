#include "ex4.h"

void calculator(int height, int width) {
	int perimeter = height * 2 + width * 2;
	int area = height * width;
	printf("Perimeter of the rectangle = %d cm", perimeter);
	printf("\n");
	printf("Area of the rectangle = %d square cm", area);
}

void ex4() {
	calculator(7, 5);
}