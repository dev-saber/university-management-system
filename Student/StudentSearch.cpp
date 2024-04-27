#pragma once
#include <iostream>
using namespace std;
#include "Student.h"

void searchStudentById()
{
    int id;
    cout << "Enter student id you want to search: ";
    cin >> id;
    auto foundStudent = find(students, id);
    if (foundStudent.has_value())
    {
        foundStudent.value()->display();
    }
    else
    {
        cout << "Student not found!" << endl;
    }
}

void searchStudentByFullName()
{
    cout << "Enter student first name: ";
    string fName;
    cin >> fName;
    cout << "Enter student last name: ";
    string lName;
    cin >> lName;
    bool found = false;
    for (Student *i : students)
    {
        if (i->getFirstName() == fName && i->getLastName() == lName)
        {
            i->display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Student with this name not found!" << endl;
    }
}
void searchStudentsByField()
{
    cout << "Enter field id: ";
    int fieldId;
    cin >> fieldId;
    auto foundField = find(fields, fieldId);
    if (foundField.has_value())
    {
        for (Student *i : students)
        {
            if (i->getField()->getId() == fieldId)
            {
                i->display();
            }
        }
    }
    else
    {
        cout << "Field not found!" << endl;
    }
}