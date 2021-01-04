#include "state_machine.hpp"
#include "vehicle.hpp"
#include "bus.hpp"
#include "van.hpp"
#include "workmachine.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


void StateMachine::execute()
{
    // State state_m = ST_NAMEFIRST;

    //State state = ST_LICENCEPLATE;

    //string buffer;



//Vehicle v("asd",123,"asd");
//Bus b();
switch(state_m) {
    case ST_MAIN:{

system("CLS");
        cout << "[1] Add Vehicle" << endl;
        cout << "[2] List Vehicles" << endl;
        cout << "[3] Search Vehicle" << endl;
        cout << "[4] Sum Usage By Category" << endl;
        cout << "[5] Set Service Requirement Boundary For Each Category" << endl;
        cout << "[6] List Vehicles That Surpassed The Service Boundary" << endl;
        cout << "[7] Exit" << endl;

            cin >> buffer_m;
            if (buffer_m[0] == '1')
                state_m = ST_LICENCEPLATE;
            else if(buffer_m[0] == '2'){
                state_m = ST_PRINT;
            }
            else if(buffer_m[0] == '3'){
                state_m = ST_SEARCH;
            }
            else if(buffer_m[0] == '4'){
                state_m = ST_LISTBYUSAGE;
            }
            else if(buffer_m[0] == '5'){
                state_m = ST_SERVICEBOUNDARY;
            }
            else if(buffer_m[0] == '6'){
                state_m = ST_LISTSERVICEREQ;
            }
            else if(buffer_m[0] == '7'){
                state_m = ST_EXIT;
            }
            break;
    }
    case ST_SEARCH:{
        system("CLS");
        cout << endl << "Licence plate: ";
        cin >> buffer_m;
        for (int i = 0; i < STORAGESIZE; i++) {
            if(storage_m[i]->licencePlate() == buffer_m){
                storage_m[i]->print();
                break;
            }

        }

            cout << "New search: n, Correct: <, Exit: x" << endl;
            cin >> buffer_m;
            switch(buffer_m[0]) {
            case 'n':
                state_m = ST_SEARCH;
                break;
            case '<':
                state_m = ST_MAIN;
                break;
            case 'x':
                state_m = ST_EXIT;
                break;
            }
    }
    case ST_LISTBYUSAGE:{}
    case ST_SERVICEBOUNDARY:{}
    case ST_LISTSERVICEREQ:{}

        case ST_LICENCEPLATE:

    system("CLS");
    cout << endl << "Vehicle type: ";
    char v;
    cin >> v;
    switch(v) {
    case 'b':{
        Bus v_m();
        storage_m[index_m] = new Bus;
        break;}
    case 'v':{
        Van v_m();
        storage_m[index_m] = new Van;
        break;}
    case 'w':{
        WorkMachine v_m();
        storage_m[index_m] = new WorkMachine;
        break;}
    default:{
        cout << endl << "Wrong type";
        break;
    }
    }
            cout << endl << "Licence plate: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_LICENCEPLATE;
            else {
                v_m.setLicencePlate(buffer_m);
                state_m = ST_TYPE;
            }
            break;
        case ST_TYPE:
            cout << endl << "Type: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_LICENCEPLATE;
            else {
                v_m.setType(buffer_m);
                state_m = ST_YEAR;
            }
            break;
        case ST_YEAR:
            cout << endl << "Year: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_TYPE;
            else {
                v_m.setYearOfManufacturing(buffer_m);
                state_m = ST_CAPACITY;
            }
            break;
        case ST_CAPACITY:
            cout << endl << "Capacity: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_YEAR;
            else {
                v_m.setCapacity(buffer_m);
                state_m = ST_USAGE;
            }
            break;
        case ST_USAGE:
            cout << endl << "Usage: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_CAPACITY;
            else {
                v_m.setUsage(buffer_m);
                state_m = ST_PRINT;
            }
            break;
        case ST_PRINT:


            *(storage_m[index_m]) = v_m;
            ++index_m;

            cout << "Next vehicle: n, Correct: <, Exit: x" << endl;
            char c;
            cin >> c;
            switch(c) {
            case 'n':
                cout << "Please enter next vehicle:" << endl;
                state_m = ST_LICENCEPLATE;
                break;
            case '<':
                state_m = ST_USAGE;
                break;
            case 'x':
                state_m = ST_MAIN;
                break;
            }

            break;
        default:
            break;
        }

    //enofcase
    }




    //enofcase


void StateMachine::print()
{
    for(int i = 0; i < index_m; ++i) {
        //cout << *storage_m[i];
        storage_m[i]->print();
    }
}

StateMachine::~StateMachine()
{
    for(int i = 0; i < index_m; ++i) {
        delete storage_m[i];
    }
}
