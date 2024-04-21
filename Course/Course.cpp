#include "Course.h"

int Course::idd = 0;
Course::Course(Teacher *t, string l)
{
    teacher = t;
    label = l;
}

Teacher *Course::getCourseTeacher()
{
    return teacher;
}

string Course::getCourseLabel()
{
    return label;
}

void Course::setCourseTeacher(Teacher *t)
{
    teacher = t;
}

void Course::setCourseLabel(string l)
{
    label = l;
}

void Course::display()
{
    cout << "Course: " << label << endl;
    teacher->display();
}

void addCourse()
{
    int id;
    cout << "Enter the teacher's id: ";
    cin >> id;

    // finding the id on the staffs vector
    auto foundStaff = find(staffs, id);
    // checking if the found object is a teacher

    if (foundStaff.has_value())
    {
        Staff *staff = *foundStaff;
        auto foundTeacher = dynamic_cast<Teacher *>(staff);
        if (foundTeacher)
        {
            // cout << "Found teacher!" << endl;
            // foundTeacher->display();
            string l;
            cout << "Enter the course label: ";
            cin >> l;

            courses.push_back(new Course(foundTeacher, l));
            cout << "Course added successfully!" << endl;
        }
        else
        {
            cout << "The given id is not for a teacher!" << endl;
            cout << "Course not added!" << endl;
        }
    }
    else
    {
        cout << "The given id is not found!" << endl;
        cout << "Course not added!" << endl;
    }
}

void displayCourses()
{
    for (Course *c : courses)
    {
        c->display();
    }
}