#include "van.hpp"
#include <iostream>

Van::Van(string lp, int y, string t, int c, int u): Vehicle(lp,y,t,c,u)
{
        setVehicleType();
}

Van::Van()
{
        setVehicleType();
}

void Van::print(){
    cout <<  "Licence plate: " << this->licencePlate() << endl <<  "Year: " << this->productionYear() << endl << "Type: " << this->type() << endl << "Load capacity: " << this->capacity() << "T" << endl << "Weekly distance travelled: " << this->usage() << "km" << endl << endl;

}

    void Van::setVehicleType() {vType = "Van";}

    string Van::getVehicleType(){return vType;}

    void Van::setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    int Van::getServiceReq(){
        return service_m;
    }

int Van::service_m = 0;
