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
        ST_LIST,
        ST_WRITE,
        ST_EXIT
    };

    StateMachine(): state_m(ST_READ), index_m(0){}
    ~StateMachine();

    State state() {return state_m;}


    void read_From_File();
    void write_To_File();
    void execute();
    void print();
private:
    string buffer_m;
    State state_m;

    vector<Vehicle*> storage_m;

    int index_m;

};

#endif
