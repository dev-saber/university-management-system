#pragma once
#include <iostream>
using namespace std;

template <class T>
void searchByFullName(vector<T> v)
{
    string fName, lName;
    cout << "Enter the first name of the person you want to search: ";
    cin >> fName;
    cout << "Enter the last name of the person you want to search: ";
    cin >> lName;
    bool found = false;
    for (T i : v)
    {
        if (i->getFirstName() == fName && i->getLastName() == lName)
        {
            found = true;
            i->display();
        }
    }
    if (!found)
    {
        cout << "Person with this name not found!" << endl;
    }
};