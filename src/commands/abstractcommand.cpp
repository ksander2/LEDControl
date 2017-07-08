#include "commands/abstractcommand.h"

void AbstractCommand::setLedControl(led *ledControl)
{
    _ledControl = ledControl;
}

AbstractCommand::~AbstractCommand()
{

}
string AbstractCommand::argStr() const
{
    return _argStr;
}

void AbstractCommand::setArgStr(const string &argStr)
{
    _argStr = argStr;
}
string AbstractCommand::result_command_message() const
{
    return _result_command_message;
}
