#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
    int id;
    string fName,lName;

public:
    static int idd;
    Person();
    Person(string,string);
    Person(Person&);
};



