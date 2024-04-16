#include "Admin.h"

Admin::Admin() : Staff() {}
Admin::Admin(string fn, string ln, Department *d) : Staff(fn,ln,d) {}
Admin::Admin(Admin &a) : Staff(a) {}

void Admin::display()
{
    cout << "Admin:" << endl;
    Staff::display();
}