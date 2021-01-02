#include "Object.h"
#include <stdlib.h>
#include <iostream>

using namespace std;



Object::Object() {
	this->first_attribute = 0;
	this->second_attribute = 'c';
	this->third_attribute = (char*)malloc(10 * sizeof(char));
	for (size_t i = 0; i < 10; i++)
	{
		this->third_attribute[i] = 'b';
	}
}

Object::Object(int s, char c) {
	this->first_attribute = s;
	this->second_attribute = c;
	this->third_attribute = (char*)malloc(10 * sizeof(char));
	for (size_t i = 0; i < 10; i++)
	{
		this->third_attribute[i] = 'b';
	}
}

int Object::addition(int a, int b) {
	return a + b;

}

int Object::substraction(int a, int b) {
	return a - b;
}

void Object::print() {
	//printf version
	printf("Hello World ! \n");
	// std version
	cout << "Hello World" << endl;

	cout <<
		"My Object :" <<
		this << endl <<
		"first_attribute : " << this->first_attribute << endl <<
		"second_attribute : " << this->second_attribute << endl <<
		"third_attrbute : " << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "Element at " << i << " : " << this->third_attribute[i] << endl;
	}
}

Object::~Object() {
	delete[] this->third_attribute;