#pragma once
#include <iostream>
using namespace std;

template <class T>
void PersonSearch(vector<T> v)
{
   int id;
    cout << "Enter the ID of the person you want to search: ";
    cin >> id;
    auto foundPerson = find(v, id);
    if (foundPerson.has_value())
    {
        foundPerson.value()->display();
    }
    else
    {
        cout << "Person not found!" << endl;
    }
   
};
