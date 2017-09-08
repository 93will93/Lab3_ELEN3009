// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;           // Thabo goes out of scope after the function printName() is finished
}

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;    // maryanne_ptr goes out of scope here after printName2() is finished. Copied once to person_ptr_in_main
}

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;                 //person_ptr will go out of scope here
}


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15); // sandile_ptr is not copied it is overwritten

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);                         //person_ptr_in_main is copied once to the printName3() function

    sandile_ptr = make_unique<Person>("Sandile2",11);       // memory for sandile_ptr on line 42 is released here
    cout << sandile_ptr->age() << endl;                     // sandile_ptr, thabo_in_main and person_ptr_in_main will go out of scope here

    return 0;
}

//thabo_in_main will go out of scope first due to dependancy
//all memory for all pointees is released at the end of main
