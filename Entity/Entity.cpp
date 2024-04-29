#include "Entity.h"

int Entity::idd = 0;
Entity::Entity() : label(""), id(Entity::idd++) {}
Entity::Entity(string l) : label(l), id(Entity::idd++) {}
Entity::Entity(Entity &e) : label(e.label), id(Entity::idd++) {}

int Entity::getId()
{
    return id;
}
void Entity::display()
{
    cout << "ID: " << id << endl;
    cout << "Label: " << label << endl;
}
void Entity::setLabel(string l)
{
    label = l;
}