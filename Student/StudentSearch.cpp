#pragma once
#include <iostream>
using namespace std;
#include "Student.h"

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