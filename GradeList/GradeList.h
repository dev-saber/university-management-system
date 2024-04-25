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
    vector<double> grades;
    int id;

public:
    static int idd;
    GradeList();
    GradeList(Student *, Course *);
    Student *getStudent();
    Course *getCourse();
    vector<double> getGrades();
    void setGrades(double);
    void setGrades(double, int);
    void display();
    int getId();
    // ~GradeList();
};
vector<GradeList *> grades;