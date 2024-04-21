#include "Inscription.h"

int Inscription::idd = 0;
Inscription::Inscription(Student *s, Course *c) : student(s), course(c), status(false), id(idd++) {}

void Inscription::setStatus(bool s)
{
    status = s;
}

bool Inscription::getStatus()
{
    return status;
}

Student *Inscription::getStudent()
{
    return student;
}

Course *Inscription::getCourse()
{
    return course;
}

void Inscription::display()
{
    cout << "Inscription: " << id << endl;
    cout << "Student Information: " << endl;
    student->display();
    cout << "Course Information: " << endl;
    course->display();
    cout << "Insription Status: " << (status ? "Confirmed" : "Not Confirmed") << endl;
}

void addInscription()
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
            Inscriptions.push_back(new Inscription(foundStudent.value(), foundCourse.value()));
            cout << "Inscription added successfully!" << endl;
        }
        else
        {
            cout << "Course not found!" << endl;
            cout << "Inscription not added!" << endl;
        }
    }
    else
    {
        cout << "Student not found!" << endl;
        cout << "Inscription not added!" << endl;
    }
}

void displayInscriptions()
{
    if (Inscriptions.size() == 0)
    {
        cout << "No Inscriptions to display!" << endl;
    }
    else
    {
        for (Inscription *inscription : Inscriptions)
        {
            inscription->display();
        }
    }
}

void validateInscription()
{
    int id;
    cout << "Enter the inscription's id: ";
    cin >> id;

    auto foundInscription = find(Inscriptions, id);
    if (foundInscription.has_value())
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
                if (foundInscription.value()->getCourse()->getCourseTeacher()->getId() == foundTeacher->getId())
                {

                    foundInscription.value()->setStatus(true);
                    cout << "Course updated successfully, the inscription is now confirmed!" << endl;
                }
                else
                {
                    cout << "The given teacher is not responsible for the course!" << endl;
                    cout << "Inscription not updated!" << endl;
                }
            }
            else
            {
                cout << "The given id is not for a teacher!" << endl;
                cout << "Inscription not updated!" << endl;
            }
        }
        else
        {
            cout << "The given id is not found!" << endl;
            cout << "Inscription not updated!" << endl;
        }
    }
    else
    {
        cout << "Inscription not found!" << endl;
        cout << "Inscription not validated!" << endl;
    }
}