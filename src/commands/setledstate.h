#ifndef SETLEDSTATE_H
#define SETLEDSTATE_H

#include "abstractcommand.h"

class SetLedState : public AbstractCommand
{
public:
    SetLedState(string arg);
    bool execute();

};

#endif // SETLEDSTATE_H
