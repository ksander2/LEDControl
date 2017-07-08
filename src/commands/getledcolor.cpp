#include "getledcolor.h"

GetLedColor::GetLedColor()
{
}

bool GetLedColor::execute()
{
    cout << _ledControl->color() << endl;
 _result_command_message = _colorMap[_ledControl->color() ];
    return true;
}
