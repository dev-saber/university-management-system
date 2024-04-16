#include "Field.cpp"

#include <stdlib.h>

void  FieldMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Field Menu-----------" << endl;
        cout << "1. Add Field" << endl;
        cout << "2. Delete Field" << endl;
        cout << "3. Update Field" << endl;
        cout << "4. Display Fields" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addField();
            break;
        case 2:
            deleteField();
            break;  
        case 3:
            updateField();
            break;
        case 4:
            displayFields();
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