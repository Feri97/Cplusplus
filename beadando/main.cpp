#include <iostream>
#include <stdlib.h>
#include <string>
#include "vehicle.hpp"
#include "bus.hpp"
#include "van.hpp"
#include "workmachine.hpp"
#include "state_machine.hpp"

using namespace std;

#define BUFFSIZE 30
/*
class Vehicle
{
public:
    Vehicle(string lp, int y, string t);
    Vehicle() {}
    ~Vehicle();

    void setLicencePlate(string lp) {licencePlate_m = lp;}
    void setYearOfManufacturing(string y) {manufacturingYear_m = atoi(y.c_str());}
    void setType(string t) {type_m = t;}

    string licencePlate() {return licencePlate_m;}
    int manufacturingYear() {return manufacturingYear_m;}
    string type() {return type_m;}

    void print();
protected:
private:
    string licencePlate_m;
    int manufacturingYear_m;
    string type_m;
};

class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u): Vehicle(lp, y, t), capacity_m(c), usage_m(u) {}
    Van() {}
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}
    void setUsage(string u) {usage_m = atoi(u.c_str());}


    int capacity() {return capacity_m;}
    int usage() {return usage_m;}

    void print();
private:
    int capacity_m;
    int usage_m;

//    setPersonBorn(string b) {setBorn(b);}
};


class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u): Vehicle(lp, y, t), capacity_m(c), usage_m(u) {

    }
    Bus() {}
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}
    void setUsage(string u) {usage_m = atoi(u.c_str());}


    int capacity() {return capacity_m;}
    int usage() {return usage_m;}

    void print();
private:
    int capacity_m;
    int usage_m;
};


class WorkMachine: public Vehicle
{
public:
    WorkMachine(string lp, int y, string t, int c, int u): Vehicle(lp, y, t), capacity_m(c), usage_m(u) {}
    WorkMachine() {}
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}
    void setUsage(string u) {usage_m = atoi(u.c_str());}


    int capacity() {return capacity_m;}
    int usage() {return usage_m;}

    void print();
private:
    int capacity_m;
    int usage_m;
};
*/
int main()
{
StateMachine sm;

    while(sm.state() != StateMachine::ST_EXIT) {
        sm.execute();
    }

    sm.print();

    return 0;
}
