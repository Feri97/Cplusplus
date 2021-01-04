#include "van.hpp"
#include <iostream>

Van::Van(string lp, int y, string t, int c, int u): Vehicle(lp,y,t), capacity_m(c), usage_m(u)
{

        setKind();
}

void Van::print(){
    cout << this->licencePlate() << " " << this->manufacturingYear() << " " << this->type() << " Load capacity(T): " << this->capacity() << " Weekly distance(km): " << this->usage() << endl;

}
int Van::service_m = 0;
/*
ostream& operator<< (ostream& s, Van v)
{
    cout << v.licencePlate() << " " << v.manufacturingYear() << " " << v.type() << " Load capacity(T): " << v.capacity() << " Weekly distance(km): " << v.usage() << endl;
    return s;
}
*/
