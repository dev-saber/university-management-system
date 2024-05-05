#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Entity/Entity.cpp"
class Field : public Entity
{
public:
    Field();
    Field(string);
    Field(Field&);
};

vector<Field*> fields;

