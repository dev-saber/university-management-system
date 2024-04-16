#pragma once
#include <iostream>
#include "../Staff/Staff.cpp"


class Teacher : public Staff
{
public:
    Teacher();
    Teacher(string, string, Department *d);
    Teacher(Teacher &);
    void display();
    // ~Teacher();
};


