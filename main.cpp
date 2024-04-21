#include "Field/FieldMenu.cpp"
#include "Department/DepartmentMenu.cpp"
#include "Student/StudentMenu.cpp"
#include "Staff/StaffMenu.cpp"
#include "Course/CourseMenu.cpp"
#include "Inscription/InscriptionMenu.cpp"


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
        cout << "3. Student Menu" << endl;
        cout << "4. Staff Menu" << endl;
        cout << "5. Course Menu" << endl;
        cout << "6. Inscription Menu" << endl;
        cout << "-1. Exit" << endl;
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
        case 3:
            StudentMenu();
            break;
        case 4:
            StaffMenu();
            break;
        case 5:
            CourseMenu();
            break;
        case 6:
            InscriptionMenu();
            break;
        case -1:
            exit = true;
            break;
        default:
            return 0;
        }
    } while (exit == false);

    return 0;
}