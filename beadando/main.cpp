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

int main()
{
StateMachine sm;

    while(sm.state() != StateMachine::ST_EXIT) {
        sm.execute();
    }

    return 0;
}
