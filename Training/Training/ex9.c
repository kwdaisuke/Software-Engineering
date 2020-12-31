#include "ex9.h"


int ex9(int num){
	int h_bill, ft_bill, tw_bill, t_bill, f_bill, o_bill;

	h_bill = num / 100;
	ft_bill = (num % 100) / 50;
	tw_bill = ((num % 100) % 50) / 20;
	t_bill = (((num% 100) % 50) % 20) / 10;
	f_bill = ((((num % 100) % 50) % 20) % 10) / 5;
	o_bill = (((((num % 100) % 50) % 20) % 10) % 5);

	printf("%d Note(s) of 100.00", h_bill);
	printf("\n");
	printf("%d Note(s) of 50.00", ft_bill);
	printf("\n");
	printf("%d Note(s) of 20.00", tw_bill);
	printf("\n");
	printf("%d Note(s) of 10.00", t_bill);
	printf("\n");
	printf("%d Note(s) of 5.00", f_bill);
	printf("\n");
	//printf("%d Note(s) of 2.00", num % 2);
	printf("%d Note(s) of 1.00", o_bill);
	printf("\n");
}

