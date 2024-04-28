#pragma once
#include <iostream>
using namespace std;
#include "Staff.cpp"

void searchStaffById()
{
    int id;
    cout << "Enter staff id you want to search: ";
    cin >> id;
    auto foundStaff = find(staffs, id);
    if (foundStaff.has_value())
    {
        foundStaff.value()->display();
    }
    else
    {
        cout << "Staff not found!" << endl;
    }
}

void searchStaffByFullName()
{
    cout << "Enter staff first name: ";
    string fName;
    cin >> fName;
    cout << "Enter staff last name: ";
    string lName;
    cin >> lName;
    bool found = false;
    for (Staff *i : staffs)
    {
        if (i->getFirstName() == fName && i->getLastName() == lName)
        {
            i->display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Staff with this name not found!" << endl;
    }
}

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