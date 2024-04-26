#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Student/Student.h"
#include "../Course/Course.h"
#include "../Registration/Registration.h"
#include "../utils.cpp"
class Absence
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V> &vector, I id);

private:
    Student *student;
    Course *course;
    int absence;
    time_t date;
    int id;

public:
    static int idd;
    Absence();
    Absence(Student *student, Course *course, int absence);
    Absence(Absence *absence);
    void setStudent(Student *student);
    Student *getStudent();
    void setCourse(Course *course);
    Course *getCourse();
    void setAbsence(int absence);
    int getAbsence();
    void setDate(time_t date);
    time_t getDate();
    void display();

    // ~Absence();
};
vector<Absence *> absences;
