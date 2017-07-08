#include "commandreceiver.h"
#include <algorithm>
#include <sstream>

CommandReceiver::CommandReceiver(led *leds)
{
    _commandMap["set-led-state"] = Command::setLedState;
    _commandMap["get-led-state"] = Command::getLedState;

    _commandMap["get-led-color"] = Command::getLedColor;
    _commandMap["set-led-color"] = Command::setLedColor;

    _commandMap["get-led-rate"] = Command::getLedRate;
    _commandMap["set-led-rate"] = Command::setLedRate;

    _led=leds;
}

bool CommandReceiver::makeCommand(string commandstring)
{
    stringstream stream(commandstring);
    string firstWord;
    string secondWord;
    string thirdWord;

    stream >> firstWord;
    stream >> secondWord;
    stream >> thirdWord;

    string arg = thirdWord;
    if (arg !="")
    {
        arg.erase(0,1);
        arg.pop_back();
    }

    string commandName = secondWord;
    auto search = _commandMap.find(commandName);
    if(search != _commandMap.end()) {
        switch (_commandMap.at(commandName)) {
        case getLedState:
        {
            command = new GetLedState();     
            break;
        }
        case setLedState:
        {
            command = new SetLedState(arg);
            break;
        }
        case getLedColor:
        {
            command = new GetLedColor();
            break;
        }
        case setLedColor:
        {
            command = new SetLedColor(arg);
            break;
        }
        case getLedRate:
        {
            command = new GetLedRate();
            break;
        }
        case setLedRate:
        {
            command = new SetLedRate(arg);
            break;
        }
        default:
            break;
        }
        command->setLedControl(_led);
    }
    else {
            std::cout << "command not found\n";
            return false;
        }
    return true;
}

string CommandReceiver::executeCommand()
{
    string result = "";

    if (command->execute())
    {
        result += "OK";
    }
    else
    {
        result += "FAILED";
    }

    if (command->result_command_message() != "")
    {
        result +=" ";
        result +=command->result_command_message();
        result += "\n";
    }
    else
    {
        result += " \n";
    }

    delete command;

    return result;
}

