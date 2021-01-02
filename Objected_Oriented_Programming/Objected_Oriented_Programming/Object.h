#include <string.h>
#include <exception>
#pragma once
class Object
{
	//Attributes
private:
	int first_attribute;
	char second_attribute;
	char* third_attribute;


	//Method
public:
	//Constructors
	Object();
	Object(int f, char s);

	//Destructor
	~Object();

	int get_first_attribute() {
		return this->first_attribute;
	}

	void set_first_attribute(int n) {
		if (n >= 0) {
			this->first_attribute = n;
		}
		else {
			throw "Error No negative Value";
		}

	}

	int addition(int a, int b);

	int substraction(int a, int b);

	void print();

};

};