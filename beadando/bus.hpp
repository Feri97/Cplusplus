#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "vehicle.hpp"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u);
    Bus();

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
