#include "Session.h"

int Session::idd = 0;

Session::Session(): id(idd++) {}
Session::Session(Course *c, string s, string e): id(idd++), course(c), start(s), end(e) {}

void Session::display()
{
    cout << "Session ID: " << id << endl;
    cout << "Course: " << endl; 
    course->display();
    cout << "Start Time: " << start << endl;
    cout << "End Time: " << end << endl;
}

int Session::getId()
{
    return id;
}

Course *Session::getCourse()
{
    return course;
}

void Session::setCourse(Course *c)
{
    course = c;
}

void Session::setStart(string s)
{
    start = s;
}

void Session::setEnd(string e)
{
    end = e;
}
