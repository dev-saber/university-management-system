#include "Staff.h"

Staff::Staff() : Person() {}
Staff::Staff(string f, string l, Department *d) : Person(f, l), department(d) {}
Staff::Staff(Staff &s) : Person(s), department(s.department) {}

void addStaff()
{
    string fName, lName;
    int depId;
    cout << "Enter the first name: ";
    cin >> fName;
    cout << "Enter the last name: ";
    cin >> lName;
    cout << "Enter the department id: ";
    cin >> depId;
    auto dep = find(departments, depId);
    if (dep.has_value())
    {
        staffs.push_back(new Staff(fName, lName, dep.value()));
        cout << "Staff added successfully" << endl;
    }
    else
    {
        cout << "Department not found" << endl;
        cout << "Staff not added" << endl;
    }
}

void Staff::display()
{
    Person::display();
    department->display();
}

void displayStaff()
{
    for (Staff *s : staffs)
    {
        s->display();
    }
}

void deleteStaff()
{
    int id;
    cout << "Enter staff id you want to delete: ";
    cin >> id;
    bool deleted = deleteByID(staffs, id);
    if (deleted)
    {
        cout << "Staff deleted successfully" << endl;
    }
    else
    {
        cout << "Staff not found" << endl;
    }
}

void Staff::setDepartment(Department *d)
{
    department = d;
}

void updateStaff()
{
    int id, idDep;
    cout << "Enter staff id you want to update: ";
    cin >> id;
    auto staff = find(staffs, id);
    if (staff.has_value())
    {
        staff.value()->updatePerson();
        cout << "Enter the new department id of the staff: ";
        cin >> idDep;
        auto dep = find(departments, idDep);
        if (dep.has_value())
        {
            staff.value()->setDepartment(dep.value());
            cout << "Staff updated successfully" << endl;
        }
        else
        {
            cout << "Department not found" << endl;
            cout << "Staff not updated" << endl;
        }
    }
    else
    {
        cout << "Staff not found" << endl;
    }
}
