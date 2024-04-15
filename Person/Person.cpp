#include "Person.h"

int Person::idd=0;
Person::Person():fName(""),lName(""),id(Person::idd){}
Person::Person(string f,string l):fName(f),lName(l),id(Person::idd){}
Person::Person(Person& p):fName(p.fName),lName(p.lName),id(Person::idd){}

int Person::getId(){
    return id;
}
void Person::setfName(string f){
    fName=f;
}
void Person::setlName(string l){
    lName=l;
}

void Person::display(){
    cout << "ID: " << id << endl;
    cout << "First Name: " << fName << endl;
    cout << "Last Name: " << lName << endl;
}