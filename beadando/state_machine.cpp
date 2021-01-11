#include "state_machine.hpp"
#include "vehicle.hpp"
#include "bus.hpp"
#include "van.hpp"
#include "workmachine.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


void StateMachine::execute()
{

    switch(state_m) {
        case ST_READ:{
            FileRead();
            state_m = ST_MAIN;
            break;
        }
    case ST_MAIN:{

        system("CLS");
        cout << "[1] Add Vehicle" << endl;
        cout << "[2] List Vehicles" << endl;
        cout << "[3] Search Vehicle" << endl;
        cout << "[4] Sum Usage By Category" << endl;
        cout << "[5] Set Service Requirement Boundary For Each Category" << endl;
        cout << "[6] List Vehicles That Exceeded The Service Boundary" << endl;
        cout << "[7] Save & Exit" << endl;

            cin >> input_m;
            if (input_m == '1')
                state_m = ST_ADD;
            else if(input_m == '2'){
                state_m = ST_LIST;
            }
            else if(input_m == '3'){
                state_m = ST_SEARCH;
            }
            else if(input_m == '4'){
                state_m = ST_LISTBYUSAGE;
            }
            else if(input_m == '5'){
                state_m = ST_SERVICELIMIT;
            }
            else if(input_m == '6'){
                state_m = ST_LISTSERVICEREQ;
            }
            else if(input_m == '7'){
                state_m = ST_WRITE;
            }
            break;
    }
    case ST_SEARCH:{
        system("CLS");
            cout << "Search in the list of vehicles: "  << endl;
        cout << endl;
        cout << endl << "Licence plate: ";
        cin >> buffer_m;
        for (int i = 0; i < (int)vehicles_m.size(); i++) {
            if(vehicles_m.at(i)->licencePlate() == buffer_m){
                vehicles_m.at(i)->print();
            }

        }

        cout << endl;
            cout << "[1] New search"  << endl;
            cout << "[2] List of vehicles"  << endl;
            cout << "[3] Back" << endl;
            cin >> input_m;
            if(input_m == '1') {
                state_m = ST_SEARCH;
                break;
            }
            else if(input_m == '2'){
                state_m = ST_LIST;
                break;
            }
            else if(input_m == '3'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_SEARCH;
                break;
            }
    }
    case ST_LISTBYUSAGE:{
    system("CLS");
    int van_u(0);
    int bus_u(0);
    int workmachine_u(0);
        for (int i = 0; i < (int)vehicles_m.size(); i++) {
            if(vehicles_m.at(i)->getVehicleType() == "Van"){
                van_u += vehicles_m.at(i)->usage();
            }
            if(vehicles_m.at(i)->getVehicleType() == "Bus"){
                bus_u += vehicles_m.at(i)->usage();
            }
            if(vehicles_m.at(i)->getVehicleType() == "WorkMachine"){
                workmachine_u += vehicles_m.at(i)->usage();
            }
        }
        cout << "Weekly usage of vehicle types" << endl;
        cout << endl;
        cout << "Vans usage: " << van_u << "km" << endl;
        cout << "Buses usage: " << bus_u << "km" << endl;
        cout << "WorkMachines usage: " << workmachine_u << "h" << endl;
        cout << endl;
        cout << "[1] List vehicles" << endl;
        cout << "[2] Back" << endl;

        cin >> input_m;
            if(input_m == '1'){
                state_m = ST_LIST;
                break;
            }
            else if(input_m == '2'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_LISTBYUSAGE;
                break;
            }
    }
    case ST_SERVICELIMIT:{

    system("CLS");
    cout << "Set service requirement boundary for: " << endl;
        cout << endl;
        cout << "[1] Van" << endl;
        cout << "[2] Bus" << endl;
        cout << "[3] Work machine" << endl;
        cout << endl;
        cout << "[4] List vehicles that requires service" << endl;
        cout << "[5] Back" << endl;
        cout << endl;
    cin >> input_m;
            if(input_m == '1'){
        cout << endl << "Van: ";
            cin >> buffer_m;
                Van::setServiceReq(buffer_m);
                state_m = ST_SERVICELIMIT;
                break;
            }
            else if(input_m == '2'){
        cout << endl << "Bus: ";
            cin >> buffer_m;
                Bus::setServiceReq(buffer_m);
                state_m = ST_SERVICELIMIT;
                break;
            }
            else if(input_m == '3'){
        cout << endl << "Work machine: ";
            cin >> buffer_m;
                WorkMachine::setServiceReq(buffer_m);
                state_m = ST_SERVICELIMIT;
                break;
            }
            else if(input_m == '4'){
                state_m = ST_LISTSERVICEREQ;
                break;
            }
            else if(input_m == '5'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_SERVICELIMIT;
                break;
            }
    }
    case ST_LISTSERVICEREQ:{
        system("CLS");
        cout << "Service required for these vehicles: " << endl;
        cout << endl;
        for (int i = 0; i < (int)vehicles_m.size(); i++) {
            if(vehicles_m.at(i)->getVehicleType()=="Van"){
                if(Van::getServiceReq() < vehicles_m.at(i)->usage()){
                    vehicles_m.at(i)->print();
                }
            }
            if(vehicles_m.at(i)->getVehicleType()=="Bus"){
                if(Bus::getServiceReq() < vehicles_m.at(i)->usage()){
                    vehicles_m.at(i)->print();
                }
            }
            if(vehicles_m.at(i)->getVehicleType()=="WorkMachine"){
                if(WorkMachine::getServiceReq() < vehicles_m.at(i)->usage()){
                    vehicles_m.at(i)->print();
                }
            }
        }
        cout << "[1] Set Boundary" << endl;
        cout << "[2] Back" << endl;
        cin >> input_m;
            if(input_m == '1'){
                state_m = ST_SERVICELIMIT;
                break;
            }
            else if(input_m == '2'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_LISTSERVICEREQ;
                break;
            }
    }

    case ST_ADD:{
        system("CLS");
    cout << "Vehicle type: " << endl;
        cout << endl;
            cout << "[1] Bus"  << endl;
            cout << "[2] Van"  << endl;
            cout << "[3] WorkMachine" << endl;
            cout << "[4] Back" << endl;
    cin >> input_m;
    bool wrongInput = true;
    while(wrongInput)
    switch(input_m) {
    case '1':{
        vehicles_m.push_back(new Bus);
        wrongInput = false;
        break;}
    case '2':{
        vehicles_m.push_back(new Van);
        wrongInput = false;
        break;}
    case '3':{
        vehicles_m.push_back(new WorkMachine);
        wrongInput = false;
        break;}
    case '4':{
        state_m = ST_MAIN;
        wrongInput = false;
        break;
        }
    default:{
        system("CLS");
        cout << "No such option as: " << input_m << endl;
        cout << endl;
        cout << "Vehicle type: " << endl;
        cout << endl;
        cout << "[1] Bus"  << endl;
        cout << "[2] Van"  << endl;
        cout << "[3] WorkMachine" << endl;
        cout << endl;
        cout << "[4] Back" << endl;
        cin >> input_m;
        break;}
    }
    if(state_m == ST_MAIN){
        break;
    }
        system("CLS");
            cout << endl << "Licence plate: ";
            cin >> buffer_m;
            vehicles_m.at(index_m)->setLicencePlate(buffer_m);

            cout << endl << "Type: ";
            cin >> buffer_m;
            vehicles_m.at(index_m)->setType(buffer_m);

            cout << endl << "Year: ";
            cin >> buffer_m;
            vehicles_m.at(index_m)->setProductionYear(buffer_m);

            cout << endl << "Capacity: ";
            cin >> buffer_m;
            vehicles_m.at(index_m)->setCapacity(buffer_m);

            cout << endl << "Usage: ";
            cin >> buffer_m;
            vehicles_m.at(index_m)->setUsage(buffer_m);

            system("CLS");

            vehicles_m.at(index_m)->print();
            ++index_m;

            cout << "[1] New vehicle"  << endl;
            cout << "[2] Back" << endl;
            cin >> input_m;
            switch(input_m) {
            case '1':
                state_m = ST_ADD;
                break;
            case '2':
                state_m = ST_MAIN;
                break;
            }
            break;

        }
        case ST_LIST:{

            system("CLS");
            cout << "List of vehicles: "  << endl;
            cout << endl;

            List();

            cout << "[1] Add vehicle"  << endl;
            cout << "[2] Search"  << endl;
            cout << "[3] Back" << endl;
            cin >> input_m;
            switch(input_m) {
            case '1':
                state_m = ST_ADD;
                break;
            case '2':
                state_m = ST_SEARCH;
                break;
            case '3':
                state_m = ST_MAIN;
                break;
            }

            break;
        }


        case ST_WRITE:{
            FileWrite();
            state_m = ST_EXIT;
            break;
        }

        default:
            break;
        }


    }


void StateMachine::FileRead(){

    string l;
    string line;

    ifstream File("save.txt");
    vector<string> vehicle;

    while(getline(File, line)){

        stringstream input_stream(line);
        while(getline(input_stream, l, '|')){
            vehicle.push_back(l);
        }

        string vLicencePlate = vehicle.at(1);
        string vType = vehicle.at(2);
        int vProductionYear = stoi(vehicle.at(3));
        int vCapacity = stoi(vehicle.at(4));
        int vUsage = stoi(vehicle.at(5));

        if(vehicle.at(0) == "WorkMachine"){
            vehicles_m.push_back(new WorkMachine(vLicencePlate, vProductionYear, vType, vCapacity, vUsage));
        }
        if(vehicle.at(0) == "Van"){
            vehicles_m.push_back(new Van(vLicencePlate, vProductionYear, vType, vCapacity, vUsage));
        }
        if(vehicle.at(0) == "Bus"){
            vehicles_m.push_back(new Bus(vLicencePlate, vProductionYear, vType, vCapacity, vUsage));
        }
        vehicle.clear();
    }
    File.close();
    if((int)vehicles_m.size()>0){
        index_m = vehicles_m.size();
    }

    ifstream sReq("servicereq.txt");
    vector<string> requirements;

    while(getline(sReq, line)){
        stringstream input_stream(line);
        while(getline(input_stream, l, '|')){
            requirements.push_back(l);
        }
        Bus::setServiceReq(requirements.at(0));
        Van::setServiceReq(requirements.at(1));
        WorkMachine::setServiceReq(requirements.at(2));

        requirements.clear();
    }
    sReq.close();
}

void StateMachine::FileWrite(){

    ofstream File("save.txt", ofstream::trunc);

  if (File.is_open())
  {
    for(int i = 0; i < (int)vehicles_m.size(); i++){
        File << vehicles_m.at(i)->getVehicleType() << '|' << vehicles_m.at(i)->licencePlate() << '|' << vehicles_m.at(i)->type() << '|' << vehicles_m.at(i)->productionYear() << '|' << vehicles_m.at(i)->capacity() << '|' << vehicles_m.at(i)->usage() << endl;
    }

    File.close();
  }
  else cout << "An error has occurred while trying to open the save file";

    ofstream sReq("servicereq.txt", ofstream::trunc);

  if (sReq.is_open())
  {
        sReq << Bus::getServiceReq() << '|' << Van::getServiceReq() << '|' << WorkMachine::getServiceReq() << endl;

    sReq.close();
  }
  else cout << "An error has occurred while trying to open the save file";
}

void StateMachine::List()
{
    for(int i = 0; i < (int)vehicles_m.size(); ++i) {
        vehicles_m.at(i)->print();
    }
}

StateMachine::~StateMachine()
{
    vehicles_m.clear();
}
