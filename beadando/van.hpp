#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "vehicle.hpp"
class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u);
    Van() {
        setKind();
    }
    void setKind() {kind = "Van";}

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
