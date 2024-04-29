#pragma once
#include <iostream>
using namespace std;
#include "Staff.cpp"

void searchStaffsByDepartment()
{
    cout << "Enter department id: ";
    int depId;
    cin >> depId;
    auto foundDep = find(departments, depId);
    if (foundDep.has_value())
    {
        for (Staff *i : staffs)
        {
            if (i->getDepartment()->getId() == depId)
            {
                i->display();
            }
        }
    }
    else
    {
        cout << "Department not found!" << endl;
    }
}
