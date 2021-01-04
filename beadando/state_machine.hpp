#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include <string>
#include "vehicle.hpp"
#include "bus.hpp"
#include "van.hpp"
#include "workmachine.hpp"
#include <iostream>
#include <vector>

#define STORAGESIZE 100
using namespace std;

class StateMachine
{
public:
    enum State {
        ST_READ,
        ST_MAIN,
        ST_SEARCH,
        ST_LISTBYUSAGE,
        ST_SERVICEBOUNDARY,
        ST_LISTSERVICEREQ,
        ST_LICENCEPLATE,
        ST_YEAR,
        ST_TYPE,
        ST_CAPACITY,
        ST_USAGE,
        ST_PRINT,
        ST_WRITE,
        ST_EXIT
    };

    StateMachine(): state_m(ST_MAIN), index_m(0){}
    ~StateMachine();

    State state() {return state_m;} // getter


    void read_From_File();
    void write_To_File();
    void execute();
    void print();
private:
    string buffer_m;
    State state_m;


    //Bus* storage_b_m[STORAGESIZE];
    //Van* storage_v_m[STORAGESIZE];
    //WorkMachine* storage_w_m[STORAGESIZE];
    vector<Vehicle*> storage_m;
    //storage_m.capacity=STORAGESIZE;
    //Vehicle* storage_m[STORAGESIZE];
    Bus v_m;
    //Vehicle v_m; //nem jó

    int index_m;

    //int index_b_m;
    //int index_v_m;
    //int index_w_m;
};

#endif
