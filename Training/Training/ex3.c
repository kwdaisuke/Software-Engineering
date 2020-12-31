#include "ex3.h" //"" is usd for header files of your own program.


void reverse(char one, char two, char three) {
	printf("The reverse of %c%c%c", one, two, three);
	printf(" is %c%c%c", three, two, one);
}


void ex3() {
	reverse('X', 'M', 'L');
}