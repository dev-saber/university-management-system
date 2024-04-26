#include "Registration.cpp"

#include <stdlib.h>

void RegistrationMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Registration Menu-----------" << endl;
        cout << "1. Add Registration" << endl;
        cout << "2. Validate Registration" << endl;
        cout << "3. Display Registrations" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addRegistration();
            break;
        case 2:
            validateRegistration();
            break;
        case 3:
            displayRegistrations();
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