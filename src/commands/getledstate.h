#ifndef GETLEDSTATE_H
#define GETLEDSTATE_H

#include "abstractcommand.h"
#include <map>
class GetLedState : public AbstractCommand
{

private:
    map<led::State, string> _stateMap =
    {  {led::State::on, "on"},
       {led::State::off, "off"}
    };
public:
    GetLedState();
    bool execute();
};

#endif // GETLEDSTATE_H
