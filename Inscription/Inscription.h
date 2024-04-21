#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Teacher/Teacher.h"
#include "../Student/Student.h"
#include "../Course/Course.h"
#include "../Staff/Staff.h"
#include "../utils.cpp"

class Inscription
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
   
private:
    int id;
    Student* student;
    Course* course;
    bool status;
public:
    static int idd;
    Inscription(Student*, Course* );
    void setStatus(bool );
    bool getStatus();
    Student* getStudent();
    Course* getCourse();
    void display();
    void setStudent();
    void setCourse();

    // ~Inscription();
};
vector<Inscription*> Inscriptions;
