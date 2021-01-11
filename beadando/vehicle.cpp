#include "vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(string lp, int y, string t): licencePlate_m(lp), productionYear_m(y), type_m(t)
{
}

Vehicle::Vehicle(string lp, int y, string t, int c, int u): licencePlate_m(lp), productionYear_m(y), type_m(t), capacity_m(c), usage_m(u)
{
}

Vehicle::~Vehicle() {}

void Vehicle::setLicencePlate(string lp){licencePlate_m = lp;}

void Vehicle::setProductionYear(string y) {productionYear_m = atoi(y.c_str());}
void Vehicle::setType(string t) {type_m = t;}

void Vehicle::setCapacity(string c) {capacity_m = atoi(c.c_str());}
void Vehicle::setUsage(string u) {usage_m = atoi(u.c_str());}

int Vehicle::capacity() {return capacity_m;}
int Vehicle::usage() {return usage_m;}

string Vehicle::licencePlate() {return licencePlate_m;}
int Vehicle::productionYear() {return productionYear_m;}
string Vehicle::type() {return type_m;}
