#include "bus.hpp"
#include <iostream>

Bus::Bus(string lp, int y, string t, int c, int u): Vehicle(lp,y,t, c, u)
{
    setVehicleType();
}

Bus::Bus() {
    setVehicleType();
}

void Bus::print(){
    cout <<  "Licence plate: " << this->licencePlate() << endl <<  "Year: " << this->productionYear() << endl << "Type: " << this->type() << endl << "Seats: " << this->capacity() << endl << "Weekly distance travelled: " << this->usage() << "km" << endl << endl;

}

    void Bus::setVehicleType() {vType = "Bus";}

    string Bus::getVehicleType(){return vType;}

    void Bus::setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    int Bus::getServiceReq(){
        return service_m;
    }

int Bus::service_m = 0;
