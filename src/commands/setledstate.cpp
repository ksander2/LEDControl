#include "setledstate.h"

SetLedState::SetLedState(string arg)
{
    _argStr = arg;
}

bool SetLedState::execute()
{
    if(_argStr == "on")
    {
        _ledControl->setState(led::State::on);
        cout << "set state on" << endl;
    }
    else if(_argStr == "off")
    {
        _ledControl->setState(led::State::off);
        cout << "set state off" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
        return false;
    }
    return true;
}
