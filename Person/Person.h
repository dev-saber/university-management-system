#pragma once
#include <iostream>
using namespace std;
#include "../utils.cpp"

class Person
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);

protected:
    int id;
    string fName, lName;

public:
    static int idd;
    Person();
    Person(string, string);
    Person(Person &);
    int getId();
    void setfName(string);
    void setlName(string);
    void display();
    void updatePerson();
};
