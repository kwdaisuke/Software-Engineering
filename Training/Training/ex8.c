#pragma once
#include "ex8.h"
#include <math.h>
int euclidean(int x1, int x2, int y1,  int y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void ex8() {
	printf("Distance between X:%d, %d Y: %d, %d is %d", 1, 2, 2, 2, euclidean(1, 2, 2, 2));
	printf("\n");
}