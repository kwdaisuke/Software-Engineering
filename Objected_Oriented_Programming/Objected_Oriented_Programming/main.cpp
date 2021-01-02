#include "Object.h"
int main(void) {

	//Crete the object by calling the constructor
	Object obj = Object();

	// Construction by reference
	Object* obj2 = new Object();
	obj.set_first_attribute(-20);
	obj.print();
	obj2->print();

	//delete obj2 (it's already a pointer)
	delete obj2;
}