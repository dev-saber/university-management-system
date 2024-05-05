#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Course/Course.h"
#include "../utils.cpp"


class Session
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);
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
};