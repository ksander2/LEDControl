#include "getledstate.h"

GetLedState::GetLedState()
{

}

bool GetLedState::execute()
{
    cout << _ledControl->state() << endl;
    _result_command_message = _stateMap[_ledControl->state()];
    return true;
}
