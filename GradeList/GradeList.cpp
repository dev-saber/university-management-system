#include "GradeList.h"

int GradeList::idd = 0;
GradeList::GradeList() : id(idd++) {}

GradeList::GradeList(Student *student, Course *course) : id(idd++), student(student), course(course) {}

// we 'll  only use updategrade instead of addgrade bcs we'll add a new instance in vector of gradelist authomaticaly after the teacher's validation of the inscription in validate method so user w'll had to only update vectrof marks instead of creting new one

Student *GradeList::getStudent()
{
    return student;
}
Course *GradeList::getCourse()
{
    return course;
}
void GradeList::setMarks(double mark)
{
    marks.push_back(mark);
}

void GradeList::setMarks(double mark, int index)
{
    marks[index] = mark;
}
int GradeList::getId()
{
    return id;
}

void updateGradeList()
{
    cout << "Enter the student's id: ";
    int studentId;
    cin >> studentId;
    cout << "Enter the course's id: ";
    int courseId;
    cin >> courseId;
    vector<int> gradeListIds;

    for (GradeList *i : grades)
    {
        if (i->getStudent()->getId() == studentId && i->getCourse()->getId() == courseId)
        {
            // we push every validated inscription of that student on that specific course
            gradeListIds.push_back(i->getId());
        }
    }
    if (gradeListIds.size() == 0)
    {
        cout << "No student id registered on that given course id found in the GradeList!" << endl;
        cout << "Grade not updated!" << endl;
    }
    else
    {
        // we display the number of found instances matching the student & course ids
        cout << "GradeLists found: " << gradeListIds.size() << endl;
        cout << "Choose one of the following gradeList's id to update: " << endl;

        for (int i : gradeListIds)
        {
            auto findGradeList = find(grades, i);

            if (findGradeList.has_value())
            {
                findGradeList.value()->display();
            }
        }

        cout << "Enter the gradeList's id: ";
        int gradeListId;
        cin >> gradeListId;
        auto foundGradeList = find(grades, gradeListId);
        if (foundGradeList.has_value())
        {

            cout << "Would you like to append/update/delete a mark? append (0) update (1) delete (2): ";
            int choice;
            cin >> choice;
            if (choice == 0)
            {
                double mark;
                int appendChoice;
                do
                {
                    cout << "Enter the mark: ";
                    cin >> mark;
                    if (mark < 0 || mark > 20)
                    {
                        cout << "Invalid mark , mark must be between 0 and 20!" << endl;
                        continue;
                    }
                    foundGradeList.value()->setMarks(mark);
                    cout << "Mark appended successfully!" << endl;
                    cout << "Do you want to append another mark? yes (0) no (1): ";
                    cin >> appendChoice;
                } while (appendChoice == 0);
            }
            else if (choice == 1)
            {
                if (foundGradeList.value()->getMarks()->size() == 0)
                {
                    cout << "No marks to update!" << endl;
                    cout << "Add a mark first!" << endl;
                }
                else
                {
                    do
                    {
                        cout << "Enter the marks's index: ";
                        int index;
                        cin >> index;

                        if (index < 0 || index > foundGradeList.value()->getMarks()->size() - 1)
                        {
                            cout << "Invalid index!" << endl;
                            continue;
                        }
                        cout << "Enter the mark: ";
                        double mark;
                        cin >> mark;
                        foundGradeList.value()->setMarks(mark, index);
                        cout << "Mark updated successfully!" << endl;
                        cout << "Do you want to update another mark? yes (0) no (1): ";
                        cin >> choice;
                    } while (choice == 0);
                }
            }
            else if (choice == 2)
            {
                if (foundGradeList.value()->getMarks()->size() == 0)
                {
                    cout << "No marks to update!" << endl;
                    cout << "Add a mark first!" << endl;
                }
                else
                {
                    cout << "Enter the marks's index: ";
                    int index;
                    cin >> index;

                    if (index < 0 || index > foundGradeList.value()->getMarks()->size() - 1)
                    {
                        cout << "Invalid index!" << endl;
                    }
                    else
                    {
                        foundGradeList.value()->getMarks()->erase(foundGradeList.value()->getMarks()->begin() + index);
                        
                        
                        
                        // auto it = marks.begin() + index;
                        // marks.erase(it);

                        cout << "Mark deleted successfully!" << endl;
                    }
                }
            }

            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
        else
        {
            cout << "Grade Id not found!" << endl;
            cout << "Grade not updated!" << endl;
        }
    }
}

vector<double>* GradeList::getMarks()
{
    return &marks;
}

void GradeList::display()
{
    cout << "GradeList id: " << id << endl;
    student->display();
    course->display();
    if (marks.size() == 0)
    {
        cout << "No marks to display!" << endl;
    }
    else
    {
        cout << "marks: " << endl;
        for (int i = 0; i < marks.size(); i++)
        {
            cout << "Grade " << i << ": " << marks[i] << endl;
        }
    }
}

void displayGradeList()
{
    if (grades.size() == 0)
    {
        cout << "No GradeLists to display!" << endl;
    }
    else
    {
        for (GradeList *grade : grades)
        {
            grade->display();
        }
    }
}

void deleteGradeList()
{
    cout << "Enter the id of the GradeList you want to delete: ";
    int id;
    cin >> id;
    if (deleteByID(grades, id))
    {
        cout << "GradeList deleted successfully!" << endl;
    }
    else
    {
        cout << "GradeList not found!" << endl;
    }
}