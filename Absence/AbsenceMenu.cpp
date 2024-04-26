#include "Absence.cpp"

#include <stdlib.h>

void AbsenceMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Absence Menu-----------" << endl;
        cout << "1. Add Absence" << endl;
        cout << "2. Delete Absence" << endl;
        cout << "3. Update Absence" << endl;
        cout << "4. Display Absences" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addAbsence();
            break;
        case 2:
            deleteAbsence();
            break;
        case 3:
            updateAbsence();
            break;
        case 4:
            displayAbsences();
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