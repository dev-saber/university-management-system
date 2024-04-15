#include "Department.cpp"

#include <stdlib.h>

void  DepartmentMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Department Menu-----------" << endl;
        cout << "1. Add Department" << endl;
        cout << "2. Delete Department" << endl;
        cout << "3. Update Department" << endl;
        cout << "4. Display Departments" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addDepartment();
            break;
        case 2:
            deleteDepartment();
            break;  
        case 3:
            updateDepartment();
            break;
        case 4:
            displayDepartments();
            break;
       
        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}