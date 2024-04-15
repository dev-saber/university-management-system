#include "Person.h"

int Person::idd=0;
Person::Person():fName(""),lName(""),id(Person::idd){}
Person::Person(string f,string l):fName(f),lName(l),id(Person::idd){}
Person::Person(Person& p):fName(p.fName),lName(p.lName),id(Person::idd){}

