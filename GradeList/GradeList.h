#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Student/Student.h"
#include "../Course/Course.h"
#include "../utils.cpp"

class GradeList
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);

private:
    Student *student;
    Course *course;
    vector<double> marks;
    int id;

public:
    static int idd;
    GradeList();
    GradeList(Student *, Course *);
    Student *getStudent();
    Course *getCourse();
    vector<double> getMarks();
    void setMarks(double);
    void setMarks(double, int);
    void display();
    int getId();
    // ~GradeList();
};
vector<GradeList *> grades;