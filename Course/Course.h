#pragma once
#include <iostream>
using namespace std;
#include "../Teacher/Teacher.h"
#include <vector>
#include "../utils.cpp"
#include "../Staff/Staff.cpp"
class Course
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);
private:
    Teacher *teacher;
    string label;
    int id;

public:
    static int idd;
    Course(Teacher *, string);
    Teacher *getCourseTeacher();
    string getCourseLabel();
    void setCourseTeacher(Teacher *);
    void setCourseLabel(string);
    int getId();
    void display();
};
vector<Course *> courses;