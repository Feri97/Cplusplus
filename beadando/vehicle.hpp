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
    Vehicle(string lp, int y, string t, int c, int u);
    Vehicle() {}
    ~Vehicle();

    void setLicencePlate(string);
    void setProductionYear(string y);
    void setType(string t);

    void setCapacity(string c);
    void setUsage(string u);

    int capacity();
    int usage();
    virtual void setVehicleType()=0;

    virtual string getVehicleType()=0;

    void setServiceReq(string s);

    int getServiceReq();

    string licencePlate();
    int productionYear();
    string type();

    virtual void print()=0;

protected:
    string vType;
    int capacity_m;
    int usage_m;
private:
    string licencePlate_m;
    int productionYear_m;
    string type_m;
};

#endif
