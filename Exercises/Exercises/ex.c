#include "ex.h"

void ex1() {
	//We declare and initialize our 10 lenght array
	int myArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// for i from 0 to length of array
	for (size_t i = 0; i < 10; i++) {

		// We print Element i : myArray[i]
		printf("Element - %d : %d\n", i, myArray[i]);
	}
}

void ex2() {
	//Declare and initialize the array
	int myArray[3] = { 2, 5, 7 };
	printf("The values store into the array are: \n");
	//we go through the array with for loop
	for (size_t i = 0; i < 3; i++) {
		
		//We print the value at i position on the same line
		printf("%d", myArray[i]);
	}
	printf("\n The values store into the array in reverse are: \n");
	//We go through the array in reverse order
	for (int j = 2; j >= 0; j--) {
		printf("%d", myArray[j]);
	}

}

void ex3() {
	int myArray[5] = { 2, 10, 6, 4, 23 };
	int sum = 0;
	printf("The values store into the array are: \n");

	for (size_t i = 0; i < 5; i++) {
		printf("%d", myArray[i]);
		printf("\n");
	}
	for (size_t i = 0; i < 5; i++) {
		 sum += myArray[i];
	}
	printf("Sum of all elements stored in the array is: %d\n", sum);
}

void ex4() {
	//Declare my Array
	int* myArray;
	//Declare my length and the variable to add new element
	int length, new_element;
	//Print message for user to let him know what to type
	printf("Choose a length for your array : \n");
	//get his input and store it in length
	if (scanf_s("%d", &length) != 1 || length < 0) {
		printf("The length should be an integer >0. Software now shutdown");
		return;
	}
	//I initialize the array
	myArray = malloc(length * sizeof(int));
	//For each element of the array I initialize it with user Input
	for (size_t i = 0; i < length; i++)
	{
		int temp_var;
		printf("Add a value at %d :\n", i);
		if (scanf_s("%d", &temp_var) == 1) {
			myArray[i] = temp_var;
		}
		else {
			clear();
			i -= 1;
		}
	}
	do
	{
		//Print user message to let him know what to input
		printf("Append element to array (-1 if you want to exit) : \n");
		//take the user input and store it in new element
		if (scanf_s("%d", &new_element) != 1) {
			printf("Error in input try again");
			clear();
		}
		else if (new_element != -1) {
			//call append function with myArray, length (as a pointer) and the new element
			myArray = append(myArray, &length, new_element);
			// I print the new array
			printf("Now your array is :\n");
			for (size_t i = 0; i < length; i++)
			{
				printf("%d ", myArray[i]);
			}
			printf("\n");
		}
	} while (new_element != -1);

}

void ex5() {
	int* myArray;
	int length, ctr = 0;
	int i, j, k;

	/*
	Usual initialization of array I ask length
	to user then input each row of the array
	*/
	printf("Type the length of array : \n");
	scanf_s("%d", &length);
	myArray = malloc(length * sizeof(int));
	for (size_t i = 0; i < length; i++)
	{
		int temp_var;
		printf("Input Value at %d : \n", i);
		scanf_s("%d", &temp_var);
		myArray[i] = temp_var;
	}

	printf("The unique elements of the array are : \n");
	// for each element of the array
	for (i = 0; i < length; i++)
	{
		ctr = 0;
		// I go check for each element of the array
		// Here we initialize to variable in the loop instruction
		for (j = 0, k = length; j < k; j++)
		{
			// if the element has the same value and check if it's not the same element
			if ((i != j) && (myArray[i] == myArray[j])) {
				//if it's true I increment my control variable	
				ctr++;
			}
		}
		//if my control variable is equal to 0 it means my element is unique
		if (ctr == 0) {
			printf("%d", myArray[i]);
		}
	}
}



void exercise6() {
	//declare m,n , o but initialize only m=10
	int m = 10, n, o;
	//declare z and initialize it to point m !
	int* z = &m;

	printf("z stores the address of m : %p \n", (void*)z);
	printf("*z stores the value of m : %d \n", *z);
	printf("&m stores the address of m : %p \n", (void*)&m);
	printf("&n stores the address of n : %p \n", (void*)&n);
	printf("&o stores the address of o : %p \n", (void*)&o);
	printf("&z stores the address of z : %p \n", (void*)&z);
}

void exercise7() {
	int userVal;
	printf("Enter a value : \n");
	if (scanf_s("%d", &userVal) != 1) {
		printf("Your input is not an integer");
		return;
	}
	if (userVal % 2 == 0) {
		printf("%d is an even number", userVal);
	}
	else {
		printf("%d is a odd number", userVal);
	}
}

void ex8() {
	//I declare length and max and initialize max to 0;
	int length, max = 0;
	//I declare the array
	int* myArray;

	//I print to the user what he must input
	printf("Choose the length of your array :\n");

	//I take the input for the length of array
	if (scanf_s("%d", &length) != 1) {
		printf("An error occure and software shutdown");
		return;
	}

	//I initialize the array with a length equal to length
	myArray = malloc(length * sizeof(int));


	//I declare the seed for the PRNG
	time_t seed_base = time(&seed_base);
	//I use the current timestamp in second as a seed
	srand(seed_base);

	//I do everything in one loop but could be done in 2 or 3
	//One for initialization, One for display value and One for max
	printf("Your array is composed of : \n");
	for (size_t i = 0; i < length; i++)
	{
		//I generate a new random value between 0 and 100
		int new_value = rand() % 100;

		//Ternary operator to set new_value in max if new value is greater than max or max if it's not
		max = new_value > max ? new_value : max;
		/*
		Ternary is the same as below :
		if (new_value > max) {
			max = new_value;
		}
		else {
			max = max;
		}
		*/
		// I set myArray[i] with the new random value
		myArray[i] = new_value;
		//I print the value of the element at the position i
		printf("Element at %d : %d \n", i, new_value);
	}

	//I print the max
	printf("Max of array is : %d\n", max);



}

int calculateLength(char* ch) {
	int len = 0;

	/*
		c++ is equivlent to do :
		i++
		c= &c[i]
	*/
	while (*ch != '\0')
	{
		len++;
		ch++;
	}
	return len;
}

void ex9() {

	//Array of characters
	char str1[25];
	//Declare int l to be the length of the string
	int l;
	//Print insturction to user
	printf("\n\n Pointer : Calculate the length of the string :\n");
	printf(" Input a string : ");
	//use fgets to get the inpute in my array
	fgets(str1, sizeof str1, stdin);
	//I call my function to calculate len
	l = calculateLength(str1);
	printf(" The length of the given string %s is : %d ", str1, l - 1);

}

void ex10() {

	//initialize pointer and set it to a new int
	int* element1 = malloc(sizeof(int)), * element2 = malloc(sizeof(int)), * element3 = malloc(sizeof(int));
	*element1 = 5;
	*element2 = 6;
	*element3 = 7;
	//create a temporary pointer to prevent one of my pointer to be lost during swaping
	int* temp_pointer;
	//print value element 1 2 3
	printf("Element1 = %d \n Element2=  %d\n Element3 = %d\n", *element1, *element2, *element3);
	//swap my pointers between them
	temp_pointer = element1;
	element1 = element3;
	element3 = element2;
	element2 = temp_pointer;
	//print value element 1,2,3
	printf("Element1 = %d \n Element2=  %d\n Element3 = %d\n", *element1, *element2, *element3);

}