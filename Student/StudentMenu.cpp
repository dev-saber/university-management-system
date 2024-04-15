#include "Student.cpp"

#include <stdlib.h>

void StudentMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Student Menu-----------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            exit = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}