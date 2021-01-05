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
            read_From_File();
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
        cout << "[7] Exit" << endl;

            cin >> buffer_m;
            if (buffer_m[0] == '1')
                state_m = ST_LICENCEPLATE;
            else if(buffer_m[0] == '2'){
                state_m = ST_LIST;
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
                state_m = ST_WRITE;
            }
            break;
    }
    case ST_SEARCH:{
        system("CLS");
        cout << endl << "Licence plate: ";
        cin >> buffer_m;
        for (int i = 0; i < storage_m.size(); i++) {
            if(storage_m.at(i)->licencePlate() == buffer_m){
                storage_m.at(i)->print();
            }

        }

            cout << "New search: n, Back: b" << endl;
            char s;
            cin >> s;
            if(s == 'n') {
                state_m = ST_SEARCH;
                break;
            }
            else if(s == 'b'){
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
    int v_usage(0);
    int b_usage(0);
    int w_usage(0);
        for (int i = 0; i < storage_m.size(); i++) {
            if(storage_m.at(i)->getKind() == "Van"){
                v_usage = v_usage + storage_m.at(i)->usage();
            }
            if(storage_m.at(i)->getKind() == "Bus"){
                b_usage = b_usage + storage_m.at(i)->usage();
            }
            if(storage_m.at(i)->getKind() == "WorkMachine"){
                w_usage = w_usage + storage_m.at(i)->usage();
            }
        }
        cout << "Weekly usage of vehicle types" << endl;
        cout << endl;
        cout << "Vans usage: " << v_usage << "km" << endl;
        cout << "Buses usage: " << b_usage << "km" << endl;
        cout << "WorkMachines usage: " << w_usage << "h" << endl;
        cout << endl;
        cout << "Back: b" << endl;

        char s;
        cin >> s;
            if(s == 'b'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_LISTBYUSAGE;
                break;
            }
    }
    case ST_SERVICEBOUNDARY:{

    system("CLS");
    cout << "Set service requirement boundary for: " << endl;
        cout << "[1] Van" << endl;
        cout << "[2] Bus" << endl;
        cout << "[3] Work machine" << endl;
        cout << "[4] Back" << endl;
    char s;
    cin >> s;
            if(s == '1'){
        cout << endl << "Van: ";
            cin >> buffer_m;
                Van::setServiceReq(buffer_m);
                state_m = ST_SERVICEBOUNDARY;
                break;
            }
            else if(s == '2'){
        cout << endl << "Bus: ";
            cin >> buffer_m;
                Bus::setServiceReq(buffer_m);;
                state_m = ST_SERVICEBOUNDARY;
                break;
            }
            else if(s == '3'){
        cout << endl << "Work machine: ";
            cin >> buffer_m;
                WorkMachine::setServiceReq(buffer_m);;
                state_m = ST_SERVICEBOUNDARY;
                break;
            }
            else if(s == '4'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_SERVICEBOUNDARY;
                break;
            }
    }
    case ST_LISTSERVICEREQ:{
        system("CLS");
        cout << "Service required: " << endl;
        for (int i = 0; i < storage_m.size(); i++) {
            if(storage_m.at(i)->getKind()=="Van"){
                if(((Van*)storage_m.at(i))->getServiceReq() < storage_m.at(i)->usage()){
                    storage_m.at(i)->print();
                }
            }
            if(storage_m.at(i)->getKind()=="Bus"){
                if(((Bus*)storage_m.at(i))->getServiceReq() < storage_m.at(i)->usage()){
                    storage_m.at(i)->print();
                }
            }
            if(storage_m.at(i)->getKind()=="WorkMachine"){
                if(((WorkMachine*)storage_m.at(i))->getServiceReq() < storage_m.at(i)->usage()){
                    storage_m.at(i)->print();
                }
            }
        }
        cout << "[1] Set Boundary" << endl;
        cout << "[2] Back" << endl;
        char s;
        cin >> s;
            if(s == '1'){
                state_m = ST_SERVICEBOUNDARY;
                break;
            }
            else if(s == '2'){
                state_m = ST_MAIN;
                break;
            }
            else{
                state_m = ST_LISTSERVICEREQ;
                break;
            }
    }

    case ST_LICENCEPLATE:
    {
    system("CLS");
    cout << endl << "Vehicle type: ";
    char v;
    cin >> v;
    switch(v) {
    case 'b':{
        storage_m.push_back(new Bus);
        break;}
    case 'v':{
        storage_m.push_back(new Van);
        break;}
    case 'w':{
        storage_m.push_back(new WorkMachine);
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
                storage_m.at(index_m)->setLicencePlate(buffer_m);
                state_m = ST_TYPE;
            }
            break;
        }
        case ST_TYPE:
            cout << endl << "Type: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_LICENCEPLATE;
            else {
                storage_m.at(index_m)->setType(buffer_m);
                state_m = ST_YEAR;
            }
            break;
        case ST_YEAR:
            cout << endl << "Year: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_TYPE;
            else {
                storage_m.at(index_m)->setYearOfManufacturing(buffer_m);
                state_m = ST_CAPACITY;
            }
            break;
        case ST_CAPACITY:
            cout << endl << "Capacity: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_YEAR;
            else {
                storage_m.at(index_m)->setCapacity(buffer_m);
                state_m = ST_USAGE;
            }
            break;
        case ST_USAGE:
            cout << endl << "Usage: ";
            cin >> buffer_m;
            if (buffer_m[0] == '<')
                state_m = ST_CAPACITY;
            else {
                storage_m.at(index_m)->setUsage(buffer_m);
                state_m = ST_PRINT;
            }
            break;
        case ST_PRINT:

            system("CLS");

            storage_m.at(index_m)->print();
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
        case ST_LIST:

            system("CLS");

            print();

            cout << "Next vehicle: n, Back: b" << endl;
            cin >> c;
            switch(c) {
            case 'n':
                state_m = ST_LICENCEPLATE;
                break;
            case 'b':
                state_m = ST_MAIN;
                break;
            }

            break;


    case ST_WRITE:{
        write_To_File();
        state_m = ST_EXIT;
        break;
    }

        default:
            break;
        }


    }


void StateMachine::read_From_File(){



    string line, l;

    vector<vector<string>> input;
    ifstream SaveFile("vehicles.txt");
    while(getline(SaveFile, line)){

        vector<string> strings;

        stringstream input_stream(line);
        while(getline(input_stream, l, ';')){
            strings.push_back(l);
        }

        input.push_back(strings);
    }
    SaveFile.close();

    for(int i = 0; i < input.size(); i++){

        string tmpLicencePlate = input.at(i).at(0);
        string tmpType = input.at(i).at(1);
        int tmpProductionYear = stoi(input.at(i).at(2));
        int tmpCapacity = stoi(input.at(i).at(3));
        int tmpUsage = stoi(input.at(i).at(4));

        if(input.at(i).at(5) == "WorkMachine"){
            storage_m.push_back(new WorkMachine(tmpLicencePlate, tmpProductionYear, tmpType, tmpCapacity, tmpUsage));
        }
        if(input.at(i).at(5) == "Van"){
            storage_m.push_back(new Van(tmpLicencePlate, tmpProductionYear, tmpType, tmpCapacity, tmpUsage));
        }
        if(input.at(i).at(5) == "Bus"){
            storage_m.push_back(new Bus(tmpLicencePlate, tmpProductionYear, tmpType, tmpCapacity, tmpUsage));
        }
    }
    index_m = storage_m.size();
}

void StateMachine::write_To_File(){

    ofstream SaveFile("vehicles.txt", ofstream::trunc);

  if (SaveFile.is_open())
  {
    for(int i = 0; i < storage_m.size(); i++){
        SaveFile << storage_m.at(i)->licencePlate() << ';' << storage_m.at(i)->type() << ';' << storage_m.at(i)->manufacturingYear() << ';' << storage_m.at(i)->capacity() << ';' << storage_m.at(i)->usage() << ';' << storage_m.at(i)->getKind() << endl;
    }

    SaveFile.close();
  }
  else cout << "Unable to open file";
}

void StateMachine::print()
{
    for(int i = 0; i < storage_m.size(); ++i) {
        storage_m.at(i)->print();
    }
}

StateMachine::~StateMachine()
{
    storage_m.clear();
}
