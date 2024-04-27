#include "Person.h"

int Person::idd = 0;
Person::Person() : fName(""), lName(""), id(Person::idd++) {}
Person::Person(string f, string l) : fName(f), lName(l), id(Person::idd++) {}
Person::Person(Person &p) : fName(p.fName), lName(p.lName) {}

int Person::getId()
{
    return id;
}
void Person::setfName(string f)
{
    fName = f;
}
void Person::setlName(string l)
{
    lName = l;
}

void Person::display()
{
    cout << "ID: " << id << endl;
    cout << "First Name: " << fName << endl;
    cout << "Last Name: " << lName << endl;
}
void Person::updatePerson()
{
    cout << "Enter the new first name: ";
    cin >> fName;
    cout << "Enter the new last name: ";
    cin >> lName;
}

string Person::getLastName()
{
    return lName;
}

string Person::getFirstName()
{
    return fName;
}