#include "TimeTable.cpp"

#include <stdlib.h>

void TimeTableMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------TimeTable Menu-----------" << endl;
        cout << "1. Add TimeTable" << endl;
        cout << "2. Delete TimeTable" << endl;
        cout << "3. Update TimeTable" << endl;
        cout << "4. Display TimeTables" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTimeTable();
            break;
        case 2:
            deleteTimeTable();
            break;
        case 3:
            updateTimeTable();
            break;
        case 4:
            displayTimeTables();
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