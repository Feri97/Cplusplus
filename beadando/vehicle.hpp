#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;


class Vehicle
{
public:
    Vehicle(string lp, int y, string t);
    Vehicle() {}
    ~Vehicle();

    void setLicencePlate(string);
    void setYearOfManufacturing(string y) {manufacturingYear_m = atoi(y.c_str());}
    void setType(string t) {type_m = t;}

    void setCapacity(string c) {capacity_m = stoi(c);}
    void setUsage(string u) {usage_m = stoi(u);}

    int capacity() {return capacity_m;}
    int usage() {return usage_m;}

    string licencePlate() {return licencePlate_m;}
    int manufacturingYear() {return manufacturingYear_m;}
    string type() {return type_m;}

    virtual void print() = 0;

protected:
    int capacity_m;
    int usage_m;
private:
    string licencePlate_m;
    int manufacturingYear_m;
    string type_m;
};


//ostream& operator<< (ostream& s, Vehicle v);
#endif
