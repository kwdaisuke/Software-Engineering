#pragma once
#include "ex7.h"
#include <math.h>
int find_max(int num1, int num2, int num3) {
	int result, max;
	result = (num1 + num2 + abs(num1 - num2)) / 2;
	max = (result + num3 + (abs(result - num3))) / 2;
	return max;
}

void ex7() {
	int max = find_max(13, 29, 33);
	printf("The maximum of %d %d %d is %d", 13, 29, 33, max);
}