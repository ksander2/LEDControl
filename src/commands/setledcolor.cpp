#include "setledcolor.h"

SetLedColor::SetLedColor(string arg)
{
    _argStr =arg;
}

bool SetLedColor::execute()
{
    if(_argStr == "red")
    {
        _ledControl->setColor(led::Color::Red);
        cout << "set color red" << endl;
    }
    else if(_argStr == "green")
    {
        _ledControl->setColor(led::Color::Green);
        cout << "set color green" << endl;
    }
    else if(_argStr == "blue")
    {
        _ledControl->setColor(led::Color::Blue);
        cout << "set color blue" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
        return false;
    }
    return true;
}
