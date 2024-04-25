#include "Teacher.h"


Teacher::Teacher() : Staff() {}
Teacher::Teacher(string fn, string ln, Department *d) : Staff(fn,ln,d) {}
Teacher::Teacher(Teacher &t) : Staff(t) {}

void Teacher::display()
{
    std::cout << "Teacher:" << endl;
    Staff::display();
}