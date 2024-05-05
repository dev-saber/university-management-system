#pragma once
#include <iostream> 
#include "../Staff/Staff.h"

class Admin : public Staff
{
public:
    Admin();
    Admin(string, string, Department *d);
    Admin(Admin &);
    void display();
};
