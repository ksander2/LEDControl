#include "setledrate.h"

SetLedRate::SetLedRate(string arg)
{
    _argStr =arg;
}

bool SetLedRate::execute()
{
    int freq = stoi(_argStr);
    if ( 0<= freq && freq <=5 )
    {
        _ledControl->setRate(freq);
        return true;
    }
    else
    {
        cout << "FAILED" << endl;
        return false;
    }
}
