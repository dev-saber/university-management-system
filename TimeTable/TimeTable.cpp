#include "TimeTable.h"

int TimeTable::idd = 0;

TimeTable::TimeTable() : id(idd++) {}
TimeTable::TimeTable(Person *p) : id(idd++), person(p) {}

// void TimeTable::addSession()
// {
//     Session *s = new Session();
//     s->setCourse(find(courses, 1).value());
//     cout << "Enter the start time: ";
//     cin >> s->start;
//     cout << "Enter the end time: ";
//     cin >> s->end;
//     timetable[0].push_back(s);
// }

void addTimeTable()
{
    cout << "Enter the person type (0 for student, 1 for staff): ";
    int type;
    cin >> type;
    while (type != 0 && type != 1)
    {
        cout << "Invalid type. Enter the person type (0 for student, 1 for staff): ";
        cin >> type;
    }
    cout << "Enter the person ID: ";
    int id;
    cin >> id;

    Person *foundPerson = nullptr;
    if (type == 0)
    {
        auto foundStudent = find(students, id);
        if (foundStudent.has_value())
        {
            foundPerson = foundStudent.value();
        }
    }
    else if (type == 1)
    {
        auto foundStaff = find(staffs, id);
        if (foundStaff.has_value())
        {

            foundPerson = foundStaff.value();
        }
    }

    if (foundPerson == nullptr)
    {
        cout << "Person not found." << endl;
        cout << "TimeTable not added." << endl;
        return;
    }
    else
    {
        cout << "person found entered the right place" << endl;
        TimeTable *t = new TimeTable(foundPerson);

        cout << "Insert the sessions in the timetable, from Monday to Saturday" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << weekDays[i] << " sessions:" << endl;
            int choice;
            vector<Session *> sessions;
            do
            {
                cout << "Enter the course ID: ";
                int id;
                cin >> id;
                auto foundCourse = find(courses, id);
                if (!foundCourse.has_value())
                {
                    cout << "Course not found." << endl;
                    cout << "Session not added." << endl;
                    continue;
                }
                else
                {
                    Session *s = new Session();
                    s->setCourse(foundCourse.value());
                    cout << "Enter the start time: ";
                    string start, end;
                    cin >> start;
                    s->setStart(start);
                    cout << "Enter the end time: ";
                    cin >> end;
                    s->setEnd(end);
                    sessions.push_back(s);
                }
                cout << "Do you want to add another session? (1 for yes, 0 for no): ";
                cin >> choice;
            } while (choice == 1);
            t->setTimetable(sessions);
        }
        timetables.push_back(t);
    }
}

void TimeTable::setTimetable(vector<Session *> t)
{
    timetable.push_back(t);
}

void TimeTable::display()
{
    cout << "TimeTable ID: " << id << endl;
    cout << "TimeTable for: " << person->getFirstName() << " " << person->getLastName() << endl;
    // timetable vector
    for (int i = 0; i < timetable.size(); i++)
    {
        cout << weekDays[i] << " sessions:" << endl;
        // session vector
        for (int j = 0; j < timetable[i].size(); j++)
        {
            // session object
            timetable[i][j]->display();
        }
    }
}

void displayTimeTables()
{
    for (int i = 0; i < timetables.size(); i++)
    {
        timetables[i]->display();
    }
}