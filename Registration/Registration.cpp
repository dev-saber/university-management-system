#include "Registration.h"

int Registration::idd = 0;
Registration::Registration(Student *s, Course *c) : student(s), course(c), status(false), id(idd++) {}

void Registration::setStatus(bool s)
{
    status = s;
}

bool Registration::getStatus()
{
    return status;
}

Student *Registration::getStudent()
{
    return student;
}

Course *Registration::getCourse()
{
    return course;
}

void Registration::display()
{
    cout << "Registration: " << id << endl;
    cout << "Student Information: " << endl;
    student->display();
    cout << "Course Information: " << endl;
    course->display();
    cout << "Insription Status: " << (status ? "Confirmed" : "Not Confirmed") << endl;
}

void addRegistration()
{
    int studentId;
    cout << "Enter the student's id: ";
    cin >> studentId;

    // finding the id on the students vector
    auto foundStudent = find(students, studentId);
    if (foundStudent.has_value())
    {
        // Student *student = *foundStudent;
        int courseId;
        cout << "Enter the course's id: ";
        cin >> courseId;

        // finding the id on the courses vector
        auto foundCourse = find(courses, courseId);
        if (foundCourse.has_value())
        {
            // Course *course = *foundCourse;
            Registrations.push_back(new Registration(foundStudent.value(), foundCourse.value()));
            cout << "Registration added successfully!" << endl;
        }
        else
        {
            cout << "Course not found!" << endl;
            cout << "Registration not added!" << endl;
        }
    }
    else
    {
        cout << "Student not found!" << endl;
        cout << "Registration not added!" << endl;
    }
}

void displayRegistrations()
{
    if (Registrations.size() == 0)
    {
        cout << "No Registrations to display!" << endl;
    }
    else
    {
        for (Registration *Registration : Registrations)
        {
            Registration->display();
        }
    }
}

void validateRegistration()
{
    int id;
    cout << "Enter the Registration's id: ";
    cin >> id;

    auto foundRegistration = find(Registrations, id);
    if (foundRegistration.has_value())
    {
        cout << "Enter the id of the teacher responsible for the validation: ";
        int teacherId;
        cin >> teacherId;
        auto foundStaff = find(staffs, teacherId);
        if (foundStaff.has_value())
        {
            Staff *staff = *foundStaff;
            auto foundTeacher = dynamic_cast<Teacher *>(staff);
            if (foundTeacher)
            {
                if (foundRegistration.value()->getCourse()->getCourseTeacher()->getId() == foundTeacher->getId())
                {

                    foundRegistration.value()->setStatus(true);
                    // add new instance of gradelist to the vector of gradelist
                    
                    grades.push_back(new GradeList(foundRegistration.value()->getStudent(), foundRegistration.value()->getCourse()));
                    cout << "Course updated successfully, the Registration is now confirmed!" << endl;
                    cout << "we added a new instance of gradelist to the vector of gradelist!" << endl;
                    cout << "you can now insert/update/delete the grades of the students in the course directly!" << endl;
                }
                else
                {
                    cout << "The given teacher is not responsible for the course!" << endl;
                    cout << "Registration not updated!" << endl;
                }
            }
            else
            {
                cout << "The given id is not for a teacher!" << endl;
                cout << "Registration not updated!" << endl;
            }
        }
        else
        {
            cout << "The given id is not found!" << endl;
            cout << "Registration not updated!" << endl;
        }
    }
    else
    {
        cout << "Registration not found!" << endl;
        cout << "Registration not validated!" << endl;
    }
}