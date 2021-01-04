#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "vehicle.hpp"
class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u)/*: Vehicle(lp, y, t), capacity_m(c), usage_m(u) {}*/;
    Van() {
        setKind();
    }
    void setCapacity(string c) {capacity_m = stoi(c);}
    void setUsage(string u) {usage_m = stoi(u);}

    void setKind() {kind = "Van";}

    string getKind(){return kind;}/*
static void setServiceReq(string s){
        service_m = atoi(s.c_str());
    };

    static int getServiceReq(){
        return service_m;
    };*/


    void print();
    static int service_m;
private:
    string kind;
    int capacity_m;
    int usage_m;
};
#endif
