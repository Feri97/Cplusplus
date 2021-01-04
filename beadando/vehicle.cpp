#include "vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(string lp, int y, string t): licencePlate_m(lp), manufacturingYear_m(y), type_m(t)
{
}

Vehicle::~Vehicle() {}

void Vehicle::setLicencePlate(string lp){licencePlate_m = lp;}
/*
ostream& operator<< (ostream& s, Vehicle v)
{
    cout << v.licencePlate() << " " << v.manufacturingYear() << " " << v.type() << endl;
    return s;
}
*/
