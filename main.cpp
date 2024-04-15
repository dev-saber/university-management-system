#include "Field/FieldMenu.cpp"
#include "Department/DepartmentMenu.cpp"

int main()
{
    int choice;
    bool exit = false;

    do
    {
        system("CLS");
        cout << "---------------Main Menu-----------" << endl;
        cout << "1. Field Menu" << endl;
        cout << "2. Department Menu" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            FieldMenu();
            break;
        case 2:
            DepartmentMenu();
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