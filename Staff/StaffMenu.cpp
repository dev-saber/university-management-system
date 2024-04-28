#include "Staff.cpp"

#include <stdlib.h>

void StaffMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Staff Menu-----------" << endl;
        cout << "1. Add Staff" << endl;
        cout << "2. Delete Staff" << endl;
        cout << "3. Update Staff" << endl;
        cout << "4. Display Staffs" << endl;
        cout << "5. Advanced Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStaff();
            break;
        case 2:
            deleteStaff();
            break;
        case 3:
            updateStaff();
            break;
        case 4:
            displayStaff();
            break;
        case 5:
            customSearchStaff();
            break;
        case 6:
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