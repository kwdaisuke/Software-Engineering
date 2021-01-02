#include "Recursion.h"

/*
	Recursion is like mathematical suite
	U0 = n0
	Un = n
	Un+1 = n+1
*/
int printNumber(int n) {
	if (n <= 50) {
		printf("%d\n", n);
		printNumber(n + 1);
	}
	return n;
}

/*
	U0=1
	Un = n*(Un-1);
	Un+1=n+1*Un
*/
int factorial(int n) {
	//Un
	if (n > 1) {
		return (n * factorial(n - 1));
	}
	//U0
	return 1;
	//Ternary operator version
	return n > 1 ? (n * factorial(n - 1)) : 1;
}

int maxBetweenTwoNumber(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}

	return a > b ? a : b;

}