#pragma once
#include "Course.h"

int Course::idd = 0;
Course::Course(Teacher *t, string l) : teacher(t), label(l), id(idd++) {}

int Course::getId()
{
    return id;
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
    cout << "Course ID: " << id << endl;
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
    if (courses.size() == 0)
    {
        cout << "No courses found!" << endl;
    }
    else
    {
        cout << "Courses: " << endl;
        for (Course *c : courses)
        {
            c->display();
        }
    }
}

void updateCourse()
{
    int id;
    cout << "Enter course id you want to update: ";
    cin >> id;
    auto course = find(courses, id);
    if (course.has_value())
    {

        cout << "Enter the new teacher id: ";
        int id;
        cin >> id;
        auto foundStaff = find(staffs, id);
        // checking if the found object is a teacher
        if (foundStaff.has_value())
        {
            Staff *staff = *foundStaff;
            auto foundTeacher = dynamic_cast<Teacher *>(staff);
            if (foundTeacher)
            {

                string l;
                cout << "Enter the course label: ";
                cin >> l;
                course.value()->setCourseLabel(l);
                course.value()->setCourseTeacher(foundTeacher);
                cout << "Course updated successfully" << endl;
            }
            else
            {
                cout << "The given id is not for a teacher!" << endl;
                cout << "Course not updated!" << endl;
            }
        }
        else
        {
            cout << "The given id is not found!" << endl;
            cout << "Course not updated!" << endl;
        }
    }
    else
    {
        cout << "Course not found" << endl;
    }
}
// add cehcking for the course id if it exist in other classes no need to delete it from the vector
void deleteCourse()
{
    int id;
    cout << "Enter course id you want to delete: ";
    cin >> id;
    bool deleted = deleteByID(courses, id);
    if (deleted)
    {
        cout << "Course deleted successfully" << endl;
    }
    else
    {
        cout << "Course not found" << endl;
    }
}