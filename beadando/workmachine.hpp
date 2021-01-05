#ifndef _WORKMACHINE_HPP_
#define _WORKMACHINE_HPP_
#include "vehicle.hpp"

class WorkMachine: public Vehicle
{
public:
    WorkMachine(string lp, int y, string t, int c, int u);
    WorkMachine() {
        setKind();
    }

    void setKind() {kind = "WorkMachine";}

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

#endif // _WORKMACHINE_HPP_
