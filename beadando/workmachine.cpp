#include "workmachine.hpp"
#include <iostream>

WorkMachine::WorkMachine(string lp, int y, string t, int c, int u): Vehicle(lp,y,t,c,u)
{
    setVehicleType();
}

WorkMachine::WorkMachine() {
    setVehicleType();
}

void WorkMachine::print(){
    cout <<  "Licence plate: " << this->licencePlate() << endl <<  "Year: " << this->productionYear() << endl << "Type: " << this->type() << endl << "Performance: " << this->capacity() << "KW" << endl << "Weekly work hours: " << this->usage() << "h" << endl << endl;

}

    void WorkMachine::setVehicleType() {vType = "WorkMachine";}

    string WorkMachine::getVehicleType(){return vType;}

    void WorkMachine::setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    int WorkMachine::getServiceReq(){
        return service_m;
    }

int WorkMachine::service_m = 0;
