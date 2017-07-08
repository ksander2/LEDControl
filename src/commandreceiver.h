#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include "commands/getledstate.h"
#include "commands/setledstate.h"
#include "commands/getledcolor.h"
#include "commands/setledcolor.h"
#include "commands/setledrate.h"
#include "commands/getledrate.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class CommandReceiver
{
public:
    CommandReceiver(led *leds);
    bool makeCommand(string commandstring);
    string executeCommand();

    enum Command
    {
        getLedState,
        setLedState,
        getLedColor,
        setLedColor,
        getLedRate,
        setLedRate
    };

private: 
    map<string, Command> _commandMap;
    led *_led;
    AbstractCommand *command;
};

#endif // COMMANDRECEIVER_H
