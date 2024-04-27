#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Course/Course.h"

class Session
{
private:
    int id;
    Course *course;
    string start, end;

public:
    static int idd;
    Session();
    Session(Course *, string, string);
    void display();
    int getId();
    Course *getCourse();
    void setCourse(Course *);
    void setStart(string);
    void setEnd(string);
    // ~Session();
};