#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Person/Person.h"
#include "../Session/Session.cpp"
#include "../Student/Student.h"
#include "../Staff/Staff.h"
#include "../utils.cpp"
#include <iomanip>
class TimeTable
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);

private:
int id;
    Person *person;
    vector<vector<Session *>> timetable;

public:
static int idd;
    TimeTable();
    TimeTable(Person *);
    void display();
    void setTimetable(vector<Session *>);
    vector<Session *> getTimetable(int);
    // overload just to get the reference in order to delete the session when needed
    vector<Session *>& getTimetable(int , int);
};

vector<TimeTable *> timetables;