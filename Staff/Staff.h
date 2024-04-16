#pragma once
#include <iostream>
#include "../Department/Department.h"
#include "../Person/Person.h"
#include <vector>
class Staff : public Person
{
private:
    Department *department;

public:
    Staff();
    Staff(string, string, Department *d);
    Staff(Staff &);
    void setDepartment(Department *d);
    void display();

    // ~Staff();
};

vector<Staff *> staffs;
