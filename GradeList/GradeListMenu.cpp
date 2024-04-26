#include "GradeList.cpp"

#include <stdlib.h>

void GradeListMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Grade List Menu-----------" << endl;
        cout << "1. Display Grade Lists" << endl;
        cout << "2. Update Grade List" << endl;
        cout << "3. Delete Grade List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            displayGradeList();
            break;
        case 2:
            updateGradeList();
            break;
        case 3:
            deleteGradeList();
            break;
        case 4:
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