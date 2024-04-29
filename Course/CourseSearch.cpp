#pragma once
#include <iostream>
using namespace std;
#include "Course.cpp"

void searchCourseByDepartment()
{
    int department;
    cout << "Enter the department ID: ";
    cin >> department;

    auto foundDepartment = find(departments, department);
    bool empty = true;
    if (foundDepartment.has_value())
    {

        for (Course *i : courses)
        {
            if (i->getCourseTeacher()->getDepartment()->getId() == department)
            {
                empty = false;
                i->display();
            }
        }
        if (empty)
        {
            cout << "No courses found for this department!" << endl;
        }
    }
    else
    {
        cout << "Department not found!" << endl;
    }
}