#include "Inscription.cpp"

#include <stdlib.h>

void InscriptionMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Inscription Menu-----------" << endl;
        cout << "1. Add Inscription" << endl;
        cout << "2. Validate Inscription" << endl;
        cout << "3. Display Inscriptions" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addInscription();
            break;
        case 2:
            validateInscription();
            break;
        case 3:
            displayInscriptions();
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