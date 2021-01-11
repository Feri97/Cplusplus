#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "vehicle.hpp"
class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u);
    Van();
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
