#include "bus.hpp"
#include <iostream>
/*
Bus::Bus(string lp, int y, string t, int c, int u): Vehicle(lp,y,t), capacity_m(c), usage_m(u)
{
}
*/
void Bus::print(){
    cout << this->licencePlate() << " " << this->manufacturingYear() << " " << this->type() << " Seats: " << this->capacity() << " Weekly distance(km): " << this->usage() << endl;

}
/*
ostream& operator<< (ostream& s, Bus b)
{
    cout << b.licencePlate() << " " << b.manufacturingYear() << " " << b.type() << " Seats: " << b.capacity() << " Weekly distance(km): " << b.usage() << endl;

    return s;
}
*/
