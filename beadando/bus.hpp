#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "vehicle.hpp"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u)/*: Vehicle(lp, y, t), capacity_m(c), usage_m(u){}*/;
    Bus() {
        setKind();
    }
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}
    void setUsage(string u) {usage_m = atoi(u.c_str());}
    void setKind() {kind = "Bus";}

    string getKind(){return kind;}/*
    static void setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    static int getServiceReq(){
        return service_m;
    }*/

    void print();
    static int service_m;
private:
    string kind;
    int capacity_m;
    int usage_m;
//    setPersonBorn(string b) {setBorn(b);}
};

#endif
