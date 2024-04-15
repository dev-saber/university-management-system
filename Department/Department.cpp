#include "Department.h"

Department::Department() : Entity() {}
Department::Department(string l) : Entity(l) {}
Department::Department(Department &d) : Entity(d) {}

void addDepartment()
{
    cout << "Enter the label of the department: ";
    string label;
    cin >> label;

    departments.push_back(new Department(label));
    cout << "Department added successfully!" << endl;
}

void deleteDepartment()
{
    cout << "Enter the id of the department you want to delete: ";
    int id;
    cin >> id;
    bool deleted = deleteByID(departments, id);
    if (deleted)
        cout << "Department deleted successfully!" << endl;
    else
        cout << "Department not found!" << endl;
}

void updateDepartment()
{
    cout << "Enter the id of the department you want to update: ";
    int id;
    cin >> id;
    auto foundDepartment = find(departments, id);
    if (foundDepartment.has_value())
    {
        cout << "Enter the new label of the Department: ";
        string label;
        cin >> label;
        for (Department *i : departments)
        {
            if (i->getId() == id)
            {
                i->setLabel(label);
                cout << "Department updated successfully!" << endl;
                break;
            }
        }
    }
    else
        cout << "Department not found!" << endl;
}

void displayDepartments()
{
    if (departments.size() == 0)
    {
        cout << "No departments found!" << endl;
        return;
    }
    else
    {
        cout << "Departments: " << endl;
        for (Department *i : departments)
        {
            i->display();
        }
    }
}