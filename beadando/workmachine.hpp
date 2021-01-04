#ifndef _WORKMACHINE_HPP_
#define _WORKMACHINE_HPP_
#include "vehicle.hpp"

class WorkMachine: public Vehicle
{
public:
    WorkMachine(string lp, int y, string t, int c, int u)/*: Vehicle(lp, y, t), capacity_m(c), usage_m(u) {}*/;
    WorkMachine() {}
    void setCapacity(string c) {capacity_m = stoi(c);}
    void setUsage(string u) {usage_m = stoi(u);}


    void print();
private:
};

#endif // _WORKMACHINE_HPP_
