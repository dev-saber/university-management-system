#pragma once
#include "Student.h"
#include "StudentSearch.cpp"

Student::Student() : Person() {}
Student::Student(string f, string l, string scrolarLevel, Field *field) : Person(f, l), scrolarLevel(scrolarLevel), field(field) {}
Student::Student(Student &s) : Person(s), scrolarLevel(s.scrolarLevel), field(s.field) {}
void Student::setField(Field *f)
{
    field = f;
}

void Student::setScrolarLevel(string s)
{
    scrolarLevel = s;
}

void Student::display()
{
    Person::display();
    cout << "Scrolar Level: " << scrolarLevel << endl;
    field->display();
}

void addStudent()
{
    string fName, lName, scrolarLevel;
    int fieldId;
    cout << "Enter student first name: ";
    cin >> fName;
    cout << "Enter student last name: ";
    cin >> lName;
    cout << "Enter student scrolar level: ";
    cin >> scrolarLevel;
    cout << "Enter student field id: ";
    cin >> fieldId;

    auto foundField = find(fields, fieldId);
    if (foundField.has_value())
    {
        for (Field *i : fields)
        {
            if (i->getId() == fieldId)
            {

                students.push_back(new Student(fName, lName, scrolarLevel, i));
                break;
            }
        }
    }
    else
    {
        cout << "Field not found!" << endl;
    }
}

void deleteStudent()
{
    int id;
    cout << "Enter student id you want to delete: ";
    cin >> id;
    bool deleted = deleteByID(students, id);
    if (deleted)
        cout << "Student deleted successfully!" << endl;
    else
        cout << "Student not found!" << endl;
}

void updateStudent()
{
    int id;
    cout << "Enter student id you want to update: ";
    cin >> id;
    auto foundStudent = find(students, id);
    if (foundStudent.has_value())
    {
        string scrolarLevel;
        foundStudent.value()->updatePerson();
        cout << "Enter the new scrolar level of the student: ";
        cin >> scrolarLevel;

        foundStudent.value()->setScrolarLevel(scrolarLevel);

        cout << "Enter the new field id of the student: ";
        int fieldId;
        cin >> fieldId;
        auto foundField = find(fields, fieldId);
        if (foundField.has_value())
        {
            foundStudent.value()->setField(foundField.value());
            cout << "Student updated successfully!" << endl;
        }
        else
        {
            cout << "Field not found. Field not updated." << endl;
        }
    }
    else
        cout << "Student not found!" << endl;
}

void displayStudents()
{
    if (students.size() == 0)
    {
        cout << "No students to display!" << endl;
    }
    else
    {
        cout << "Students: " << endl;
        for (Student *i : students)
        {
            i->display();
        }
    }
}

string Student::getLastName()
{
    return lName;
}
string Student::getFirstName()
{
    return fName;
}
Field *Student::getField()
{
    return field;
}

void customSearchStudent()
{
    bool exit = false;
    do
    {
        system("CLS");
        cout << "---------------Search Student Menu-----------" << endl;
        cout << "1. Search by id" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by field" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            searchStudentById();
            break;
        case 2:
            searchStudentByFullName();
            break;
        case 3:
            searchStudentsByField();
            break;
        case 4:
            exit = true;
            return;
        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> choice;
    } while (exit == false);
}