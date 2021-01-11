#ifndef _WORKMACHINE_HPP_
#define _WORKMACHINE_HPP_
#include "vehicle.hpp"

class WorkMachine: public Vehicle
{
public:
    WorkMachine(string lp, int y, string t, int c, int u);
    WorkMachine();

    void setVehicleType();

    string getVehicleType();

    static void setServiceReq(string s);

    static int getServiceReq();

    void print();
    static int service_m;

private:
    string vType;
};

#endif
