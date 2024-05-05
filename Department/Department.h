#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Entity/Entity.h"

class Department: public Entity
{
public:
    Department();
    Department(string);
    Department(Department&);
};

vector<Department*> departments;