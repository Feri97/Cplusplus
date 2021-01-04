#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "vehicle.hpp"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u)/*: Vehicle(lp, y, t), capacity_m(c), usage_m(u){}*/;
    Bus() {}
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}
    void setUsage(string u) {usage_m = atoi(u.c_str());}


    void print();
private:
//    setPersonBorn(string b) {setBorn(b);}
};

#endif
