#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "vehicle.hpp"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u);
    Bus() {
        setKind();
    }

    void setKind() {kind = "Bus";}

    string getKind(){return kind;}

    static void setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    static int getServiceReq(){
        return service_m;
    }

    void print();
    static int service_m;

//private:
    string kind;
};

#endif
