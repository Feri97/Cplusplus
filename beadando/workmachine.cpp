#include "workmachine.hpp"
#include <iostream>

WorkMachine::WorkMachine(string lp, int y, string t, int c, int u): Vehicle(lp,y,t), capacity_m(c), usage_m(u) {
        setKind();}

void WorkMachine::print(){
    cout << this->licencePlate() << " " << this->manufacturingYear() << " " << this->type() << " Performance(KW): " << this->capacity() << " Weekly work(h): " << this->usage() << endl;

}
int WorkMachine::service_m = 0;
/*
ostream& operator<< (ostream& s, WorkMachine wm)
{
    cout << wm.licencePlate() << " " << wm.manufacturingYear() << " " << wm.type() << " Performance(KW): " << wm.capacity() << " Weekly work(h): " << wm.usage() << endl;
    return s;
}
*/
