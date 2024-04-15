#include "Field/FieldMenu.cpp"
int main()
{
    int choice;
    bool exit = false;

    do
    {
        system("CLS");
        cout << "---------------Main Menu-----------" << endl;
        cout << "1. Field Menu" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            FieldMenu();
            break;
        case 5:
            exit = true;
            break;
        default:
            return 0;
        }
    } while (exit == false);

    return 0;
}