#include "Course.cpp"

#include <stdlib.h>

void CourseMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "---------------Course Menu-----------" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Delete Course" << endl;
        cout << "3. Update Course" << endl;
        cout << "4. Display Courses" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addCourse();
            break;
        case 2:
         deleteCourse();
         break;
        case 3:
         updateCourse();
         break;
        case 4:
            displayCourses();
            break;

        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}