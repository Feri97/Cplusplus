#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "vehicle.hpp"
class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u)/*: Vehicle(lp, y, t), capacity_m(c), usage_m(u) {}*/;
    Van() {}
    void setCapacity(string c) {capacity_m = stoi(c);}
    void setUsage(string u) {usage_m = stoi(u);}



    void print();
private:
};

#endif
