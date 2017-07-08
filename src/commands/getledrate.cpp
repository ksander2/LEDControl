#include "getledrate.h"

GetLedRate::GetLedRate()
{
}

bool GetLedRate::execute()
{
    cout << _ledControl->rate() << endl;
    _result_command_message = to_string( _ledControl->rate());
    return true;
}
