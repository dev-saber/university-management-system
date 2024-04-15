#include "Field.h"

Field::Field() : Entity() {}
Field::Field(string l) : Entity(l) {}
Field::Field(Field &f) : Entity(f) {}

void addField()
{
    cout << "Enter the label of the field: ";
    string label;
    cin >> label;

    fields.push_back(new Field(label));
    cout << "Field added successfully!" << endl;
}

void deleteField()
{
    cout << "Enter the id of the field you want to delete: ";
    int id;
    cin >> id;
    bool deleted = deleteByID(fields, id);
    if (deleted)
        cout << "Field deleted successfully!" << endl;
    else
        cout << "Field not found!" << endl;
}

void updateField()
{
    cout << "Enter the id of the field you want to update: ";
    int id;
    cin >> id;
    auto foundField = find(fields, id);
    if (foundField.has_value())
    {
        cout << "Enter the new label of the field: ";
        string label;
        cin >> label;
        for (Field *i : fields)
        {
            if (i->getId() == id)
            {
                i->setLabel(label);
                cout << "Field updated successfully!" << endl;
                break;
            }
        }
    }
    else
        cout << "Field not found!" << endl;
}

void displayFields()
{
    if (fields.size() == 0)
    {
        cout << "No fields found!" << endl;
        return;
    }
    else
    {
        cout << "Fields: " << endl;
        for (Field *i : fields)
        {
            i->display();
        }
    }
}