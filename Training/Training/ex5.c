#define _USE_MATH_DEFINES
#include "ex5.h"
#include <math.h>
double perimeter(double radius) {
	return 2 * M_PI * radius;
}

double area(double radius) {
	return M_PI * (radius*radius);
}

void ex5() {
	printf("Perimeter of the Circle = %f cm", perimeter(6));
	printf("\n");
	printf("Area of the Circle = %f square cm", area(6));

}