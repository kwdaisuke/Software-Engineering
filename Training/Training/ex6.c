#include "ex6.h"



int getNumberOfYear(int day) {
	return (day % 365);
}


int getNumberOfMonth(int day) {
	return (day % 365) / 31;

}

int getNumberOfWeek(int day) {
	return ((day % 365) / 31) / 7;
}

void ex6() {
	int years = getNumberOfYear(1329);
	int months = getNumberOfMonth(1329);
	int weeks = getNumberOfWeek(1329);
	printf("Years: %d", years);
	printf("\n");
	printf("Months: %d", months);
	printf("\n");
	printf("Years: %d", weeks);
}