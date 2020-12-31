#include "ex10.h"

void ex10(int s) {
	int h, m, s_r;

	h = s / 3600;
	m = (s % 3600) / 60;
	s_r = s - (h * 3600) - (m * 60);
	printf("H:M:S %d:%d:%d", h, m, s_r);
	

}