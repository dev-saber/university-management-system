#include "TimeTable.h"

int TimeTable::idd = 0;

TimeTable::TimeTable() : id(idd++) {}
TimeTable::TimeTable(Person *p) : id(idd++), person(p) {}

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
                cout << "Do you want to add another session? (0 for yes, 1 for no): ";
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
    cout << "TimeTable:" << endl;
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

void updateTimeTable()
{
    cout << "Enter the timetable ID: ";
    int id;
    cin >> id;
    auto foundTimeTable = find(timetables, id);
    if (!foundTimeTable.has_value())
    {
        cout << "TimeTable not found." << endl;
        cout << "TimeTable not updated." << endl;
        return;
    }
    else
    {
        int day;
        do
        {
            cout << "Enter the day (0 for Monday, 1 for Tuesday, 2 for Wednesday, 3 for Thursday, 4 for Friday, 5 for Saturday): ";
            cin >> day;
            if (day < 0 || day > 6)
            {
                cout << "Invalid day." << endl;
            }

        } while (day < 0 || day > 6);
        cout << "Sessions for " << weekDays[day] << ":" << endl;
        for (Session *i : foundTimeTable.value()->getTimetable(day))
        {
            i->display();
        }

        int sessionID;
        int keepGoing;
        do
        {
            cout << "Enter the session ID you want to update: ";
            cin >> sessionID;
            auto foundSession = find(foundTimeTable.value()->getTimetable(day), sessionID);
            if (!foundSession.has_value())
            {
                cout << "Session not found." << endl;
                cout << "Session not updated." << endl;
                return;
            }
            else
            {
                int choice;
                cout << "Do you want to update this session's course or delete this session? (0 for update, 1 for delete): ";
                cin >> choice;
                if (choice == 1)
                {
                    bool deleted = deleteByID(foundTimeTable.value()->getTimetable(day, 0), sessionID);
                    if (deleted)
                        cout << "Session deleted successfully!" << endl;
                    else
                        cout << "Session not found!" << endl;
                }
                else if (choice == 0)
                {
                    cout << "Enter the course ID: ";
                    int id;
                    cin >> id;
                    auto foundCourse = find(courses, id);
                    if (!foundCourse.has_value())
                    {
                        cout << "Course not found." << endl;
                        cout << "Session not updated." << endl;
                        return;
                    }
                    else
                    {
                        foundSession.value()->setCourse(foundCourse.value());
                        cout << "Enter the start time: ";
                        string start, end;
                        cin >> start;
                        foundSession.value()->setStart(start);
                        cout << "Enter the end time: ";
                        cin >> end;
                        foundSession.value()->setEnd(end);
                        cout << "Session updated successfully!" << endl;
                    }
                }
            }

            cout << "Do you want to update/delete another session? (0 for yes, 1 for no): ";
            cin >> keepGoing;

        } while (keepGoing == 1);
        cout << "TimeTable updated successfully!" << endl;
    }
}

vector<Session *> TimeTable::getTimetable(int day)
{
    return timetable[day];
}

void deleteTimeTable()
{
    int id;
    cout << "Enter timetable id you want to delete: ";
    cin >> id;
    bool deleted = deleteByID(timetables, id);
    if (deleted)
        cout << "TimeTable deleted successfully!" << endl;
    else
        cout << "TimeTable not found!" << endl;
}

vector<Session *> &TimeTable::getTimetable(int day, int d)
{
    return timetable[day];
}