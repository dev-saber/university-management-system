#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Field/Field.h"
#include "../Person/Person.cpp"
#include "../utils.cpp"

class Student: public Person
{
private:
    string scrolarLevel;
    Field* field;
public:
    Student();
    Student(string, string, string, Field*);
    Student(Student&);
    void setField(Field*);
    void setScrolarLevel(string);
    void display();
    
    // ~Student();
};

vector<Student*> students;