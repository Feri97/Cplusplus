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
        ST_ADD,
        ST_LIST,
        ST_SEARCH,
        ST_LISTBYUSAGE,
        ST_SERVICELIMIT,
        ST_LISTSERVICEREQ,
        ST_WRITE,
        ST_EXIT
    };

    StateMachine(): state_m(ST_READ), index_m(0){}
    ~StateMachine();

    State state() {return state_m;}


    void FileRead();
    void FileWrite();
    void execute();
    void List();
private:
    string buffer_m;
    State state_m;

    vector<Vehicle*> vehicles_m;

    char input_m;
    int index_m;

};

#endif
