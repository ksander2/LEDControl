#ifndef SETLEDCOLOR_H
#define SETLEDCOLOR_H

#include "abstractcommand.h"

class SetLedColor : public AbstractCommand
{
public:
    SetLedColor(string arg);
    bool execute();
};

#endif // SETLEDCOLOR_H
