#include "Absence.h"
int Absence::idd = 0;
Absence::Absence()
{
    // student = nullptr;
    // course = nullptr;
    id=Absence::idd++;
    absence = 0;
    date = time(0);
}
Absence::Absence(Student *s, Course *c, int a) : student(s), course(c), absence(a)
{
    id=Absence::idd++;
    date = time(0);
}
Absence::Absence(Absence *a) : student(a->student), course(a->course), absence(a->absence), date(a->date)
{
    id=Absence::idd++;
}

void Absence::setStudent(Student *s)
{
    student = s;
}
Student *Absence::getStudent()
{
    return student;
}
void Absence::setCourse(Course *c)
{
    course = c;
}
Course *Absence::getCourse()
{
    return course;
}
void Absence::setAbsence(int a)
{
    absence = a;
}
int Absence::getAbsence()
{
    return absence;
}
void Absence::setDate(time_t d)
{
    date = d;
}
time_t Absence::getDate()
{
    return date;
}
void Absence::display()
{
    cout << "ID: " << id << endl;
    cout << "Student: " << endl;
    student->display();
    cout << "Course: " << endl;
    course->display();
    
    cout << "Absence: " << absence << endl;
    cout << "Date: " << ctime(&date) << endl;
}

void addAbsence()
{
    cout << "Enter student ID: ";
    int studentID;
    cin >> studentID;
    auto student = find(students, studentID);
    if (!student.has_value())
    {
        cout << "Student not found!" << endl;
        return;
    }
    cout << "Enter course ID: ";
    int courseID;
    cin >> courseID;
    auto course = find(courses, courseID);
    if (!course.has_value())
    {
        cout << "Course not found!" << endl;
        return;
    }

    // check in registers if student is registered in course
    bool registered = false;
    for (Registration *registration : Registrations)
    {
        if (registration->getStudent()->getId() == student.value()->getId() && registration->getCourse()->getId() == course.value()->getId() && registration->getStatus() == true)
        {
            cout << "Student is registered in course!" << endl;
            registered = true;
            break;
            
        }
    }
    if (!registered)
    {
        cout << "Student is not registered in course or the registration is not approved!" << endl;
        return;
    }
    
    int absence;
    do
    {
        cout << "Enter absence: ";
        cin >> absence;
        if (absence < 0)
        {
            cout << "Absence can't be negative!" << endl;
        }

    } while (absence < 0);

    absences.push_back(new Absence(student.value(), course.value(), absence));
    cout << "Absence added successfully!" << endl;
}

void deleteAbsence()
{
    int id;
    cout << "Enter absence id you want to delete: ";
    cin >> id;
    bool deleted = deleteByID(absences, id);
    if (deleted)
        cout << "Absence deleted successfully!" << endl;
    else
        cout << "Absence not found!" << endl;
}

void updateAbsence()
{
    int id;
    cout << "Enter absence id you want to update: ";
    cin >> id;
    auto foundAbsence = find(absences, id);
    if (foundAbsence.has_value())
    {
        int absence;
        cout << "Enter the new absence: ";
        cin >> absence;
        foundAbsence.value()->setAbsence(absence);
        cout << "Absence updated successfully!" << endl;
    }
    else
    {
        cout << "Absence not found!" << endl;
    }
}
void displayAbsences()
{

    if (absences.size() == 0)
    {
        cout << "No absences to display!" << endl;
    }
    else
    {
        cout << "Absences: " << endl;
        for (Absence *absence : absences)
        {
            absence->display();
        }
    }
}